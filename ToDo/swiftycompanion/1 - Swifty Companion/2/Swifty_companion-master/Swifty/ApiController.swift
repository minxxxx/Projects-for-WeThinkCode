//
//  ApiController.swift
//  Swifty
//
//  Created by Leslie DE JAGER on 2018/10/15.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import Foundation
import UIKit

final class ApiController
{
    
    init()
    {
        self.token = "";
        self.login = "";
        self.id = 0;
        self.email = "";
        self.level = "";
        self.skills = [];
        self.correctionPoints = "";
        self.image = "";
        self.projects = [];
        self.displayName = "";
        
        self.secret = "fedf0a2f62aee1b77f70100da3c71d10ce0ace3fcbb7283ffa4ebd1396f0bb9d";
        self.uid = "9dcd6588365173aa3cbdbb820e12e72b82434afe65f7208afbf2a14692d020c8";
    }
    
    var token:String;
    var secret:String;
    var uid:String;
    var login:String;
    var id: Int;
    var email: String;
    var level: String;
    var skills: [(String, String)];
    var correctionPoints :String;
    var image:String;
    var displayName : String;
    var projects: [(String, Int)];
    
    func resetValues()
    {
        self.login = "";
        self.id = 0;
        self.email = "";
        self.level = "";
        self.skills = [];
        self.correctionPoints = "";
        self.image = "";
        self.displayName = "";
        self.projects = [];
    }
    
    func processProjects(data:[[String:AnyObject]])
    {
        for project in data
        {
            var mark = 0
            if let tempMark = project["final_mark"] as? Int
            {
                mark = tempMark
            }
            let details = project["project"] as! [String:AnyObject]
            let proj = details["name"] as! String
            let slug = details["slug"] as! String
            if slug.range(of:"bootcamp") == nil && slug.range(of:"day") == nil && slug.range(of:"rush") == nil
            {
                let result = (proj, mark)
                self.projects.append(result)
            }
        }
    }
    
    func processSkills(data:[String:AnyObject])
    {
        if let skills = data["skills"] as? [[String:AnyObject]]
        {
            if skills.count == 0
            {
                return
            }
            for skill in skills
            {
                let name = "\((skill["name"])!)";
                let level = "\((skill["level"])!)";
                let s = (name, level);
                self.skills.append(s);
            }
        }
    }
    
    func processUser(dic:NSDictionary)
    {
        self.email = dic["email"] as! String
        self.correctionPoints = "\(dic["correction_point"] as! Int)"
        self.image = dic["image_url"] as! String
        self.displayName = dic["displayname"] as! String
        if let stD = dic["cursus_users"] as? [[String: AnyObject]]{
            self.id = (stD[0]["id"] as? Int)!
            self.level = "\((stD[0]["level"])!)"
            processSkills(data: stD[0])
        }
        if let stD = dic["projects_users"] as? [[String: AnyObject]]{
            processProjects(data: stD);
        }
    }
    
    func initialise()
    {
        let url = URL(string: "https://api.intra.42.fr/v2/oauth/token")
        
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "POST"
        request.httpBody = "grant_type=client_credentials&client_id=\(self.uid)&client_secret=\(self.secret)".data(using: String.Encoding.utf8)
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            if let err = error{
                print(err)
            }
            else if let d = data{
                do{
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary{
                        if let temp = dic["access_token"]
                        {
                            self.token = temp as! String
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
    
    func doesUserExist(login: String) -> Bool
    {
        apiRequest(processData: processUser, urlString: "https://api.intra.42.fr/v2/users/\(login)")
        if id != 0
        {
            self.login = login;
            return true
        }
        return false;
    }
    
    
    
    func apiRequest(processData : @escaping (NSDictionary) -> Void, urlString:String)
    {
        let url = URL(string: urlString)
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(self.token)", forHTTPHeaderField: "Authorization")
        
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            let HttpResponse = response as? HTTPURLResponse
            if let err = error{
                print(err)
            }
            else if HttpResponse?.statusCode == 200, let d = data{
                do{
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary{
                        processData(dic)
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
    
    func getImage(profileImage: UIImageView)
    {
        let img = URL(string: "https://cdn.intra.42.fr/users/medium_\(self.login).jpg")
        let session = URLSession(configuration: .default)
        let group = DispatchGroup()
        let getImgFromUrl = session.dataTask(with: img!) {(data, response, error) in
            if let error = error {
                print("Error Occurred: \(error)")
            } else {
                if (response as? HTTPURLResponse) != nil {
                    if let data = data {
                        let imageTemp = UIImage(data: data)
                        if (data.count > 180) {
                            DispatchQueue.main.async {
                                profileImage.image = imageTemp
                            }
                        } else {
                            self.getDefault(profileImage: profileImage)
                        }
                    }
                }
            }
            group.leave()
        }
        group.enter()
        getImgFromUrl.resume()
        group.wait()
    }
    
    func getDefault(profileImage: UIImageView)
    {
        let img = URL(string: "https://cdn.intra.42.fr/users/medium_default.png")
        let session = URLSession(configuration: .default)
        let getImgFromUrl = session.dataTask(with: img!) {(data, response, error) in
            if let error = error {
                print("Error Occurred: \(error)")
            } else {
                if (response as? HTTPURLResponse) != nil {
                    if let data = data {
                        let imageTemp = UIImage(data: data)
                        DispatchQueue.main.async {
                            profileImage.image = imageTemp
                        }
                    }
                }
            }
        }
        getImgFromUrl.resume()
    }
}
