//
//  ApiController.swift
//  42Connect
//
//  Created by Marco FERNANDES on 2018/10/06.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

struct Topic {
    var name: String;
    var user: String;
    var date: String;
    var messages_url: String!
    var id: Int!
    
    init(name: String, user: String, date: String, messages_url: String, id: Int) {
        self.name = name;
        self.user = user;
        self.date = date;
        self.messages_url = messages_url;
        self.id = id;
    }
}

struct Message {
    var content: String;
    var user: String;
    var date: String;
    var isReply: Bool;
    var id: Int!
    
    init(content: String, user: String, date: String, isReply: Bool, id: Int) {
        self.content = content;
        self.user = user;
        self.date = date;
        self.isReply = isReply;
        self.id = id;
    }
}


var Topics: [Topic] = [];
var Messages: [Message] = [];
var Responses: [Message] = [];


class ApiController: NSObject {

    let uid = "cf646bd3b744848776ae359d4c513e8bfb367acd7df45298c90af04f6f0c8171";
    let secret = "1893b7e2b47e8f8e6cc2c319ab082375acc0f77135bcfb97cb96325ea81add0f";
    static var token: String  = ""
    
    func getAccessToken(){
        let url = URL(string: "https://api.intra.42.fr/v2/oauth/token")
        
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "POST"
        request.httpBody = "grant_type=client_credentials&client_id=\(uid)&client_secret=\(secret)".data(using: String.Encoding.utf8)
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            print(response as Any)
            if let err = error{
                print(err)
            }
            else if let d = data{
                do{
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary{
                        if let temp = dic["access_token"]
                        {
                            ApiController.token = (temp as! String)
                            print(temp as! String)
                        }
                    }
                }
                catch(let err){
                    print(err)
                }
            }
            group.leave()
        }
        group.enter()
        task.resume()
        group.wait()
    }
    
    func handleDate(created_at: String) -> String {
        let dateFormatter = DateFormatter();
        dateFormatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss.SSSXXXXX";
        let date = dateFormatter.date(from: created_at);
        dateFormatter.dateFormat = "MM/dd/yy HH:mm";
        if let d = date {
            return (dateFormatter.string(from: d));
        }
        return (created_at);
    }
    
    func handleTopics(dic: [Any]) {
        Topics.removeAll();
        for i in 0...(dic.count - 1) {
            if let topic = dic[i] as? [String: Any] {
                if let user = topic["author"] as? [String: Any] {
                    Topics.append(Topic(
                        name: topic["name"] as! String,
                        user: user["login"] as! String,
                        date: handleDate(created_at: topic["created_at"] as! String),
                        messages_url: topic["messages_url"] as! String,
                        id: topic["id"] as! Int
                    ));
                }
            }
        }
    }
    
    func handleMessages(dic: [Any], isReply: Bool) {
        var replies: [Any];
        
        for i in 0...(dic.count - 1) {
            if let message = dic[i] as? [String: Any] {
                if let user = message["author"] as? [String: Any] {
                    replies = message["replies"] as! [Any];
                    Messages.append(Message(
                        content: message["content"] as! String,
                        user: user["login"] as! String,
                        date: handleDate(created_at: message["created_at"] as! String),
                        isReply: isReply,
                        id: message["id"] as! Int
                        )
                    );
                    if (replies.count > 0) {
                        handleMessages(dic: replies, isReply: true);
                    }
                };
            }
        }
    }
    
    func getTopics()
    {
        let url = URL(string: "https://api.intra.42.fr/v2/topics.json")
        
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(String(describing: ApiController.token))", forHTTPHeaderField: "Authorization")
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            print(response as Any)
            if let err = error{
                print(err)
            }
            else if let d = data{
                do{
                    if let dic  = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? [Any]{
                        if dic.count > 0 {
                            self.handleTopics(dic: dic)
                        }
                        
                    }
                }
                catch(let err){
                    print(err)
                }
            }
            group.leave()
        }
        group.enter()
        task.resume()
        group.wait()
        print(Topics.count)
        
    }
    
    func getMessages(id : Int)
    {
        let url = URL(string: "https://api.intra.42.fr/v2/topics/\(id)/messages")
        
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(String(describing: ApiController.token))", forHTTPHeaderField: "Authorization")
        
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            print(response as Any)
            if let err = error{
                print(err)
            }
            else if let d = data{
                do{
                    if let dic = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? [Any]{
                        if dic.count > 0 {
                            self.handleMessages(dic: dic, isReply: false)
                        }
                        
                        //                        print("result")
                        //                        print(dic)
                    }
                }
                catch(let err){
                    print(err)
                }
            }
            group.leave()
        }
        group.enter()
        task.resume()
        group.wait()
        print(Messages.count)
    }

    func handleReponses(dic: [Any], isReply: Bool) {
        
        for i in 0...(dic.count - 1) {
            if let message = dic[i] as? [String: Any] {
                if let user = message["author"] as? [String: Any] {
                    Responses.append(Message(
                        content: message["content"] as! String,
                        user: user["login"] as! String,
                        date: handleDate(created_at: message["created_at"] as! String),
                        isReply: isReply,
                        id: message["id"] as! Int
                        )
                    );
                };
            }
        }
    }
    
    func getReponses(topicID : Int, messageID : Int)
    {
        let url = URL(string: "https://api.intra.42.fr/v2/topics/\(topicID)/messages/\(messageID)/messages")
        
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(ApiController.token)", forHTTPHeaderField: "Authorization")
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            print(response as Any)
            if let err = error{
                print(err)
            }
            else if let d = data{
                do{
                    if let dic = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? [Any]{
                        if dic.count > 0 {
                            self.handleReponses(dic: dic, isReply: true)
                        }
                    }
                }
                catch(let err){
                    print(err)
                }
            }
            group.leave()
        }
        group.enter()
        task.resume()
        group.wait()
        print(Responses.count)
    }
    
    
}
