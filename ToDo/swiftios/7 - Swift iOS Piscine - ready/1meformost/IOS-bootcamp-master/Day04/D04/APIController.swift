//
//  APIController.swift
//  D04
//
//  Created by Marco on 2018/10/05.
//  Copyright © 2018 Marco. All rights reserved.
//

import Foundation

extension String {
    func condensingWhitespace() -> String {
        return self.components(separatedBy: .whitespacesAndNewlines)
            .filter { !$0.isEmpty }
            .joined(separator: " ")
    }
}

class APIController
{
    weak var delegate : APITwitterDelegate?
    let token:String

    init(delegate: APITwitterDelegate?, token: String) {
        self.delegate = delegate
        self.token = token
    }
    
    let urlStart = "https://api.twitter.com/1.1/search/tweets.json?q="
    let urlEnd = "&result_type=recent&count=100"
    
    func requestTwitter(variable: String){
        let trimmed = variable.trimmingCharacters(in: .whitespacesAndNewlines)
        let spaced = trimmed.condensingWhitespace()
        let result = spaced.replacingOccurrences(of: " ", with: "%20")
            let url = URL(string: self.urlStart + result + self.urlEnd)
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "GET"
        request.setValue("Bearer \(self.token)", forHTTPHeaderField: "Authorization")
        let dispatch = DispatchGroup()
        let task = URLSession.shared.dataTask(with: request as URLRequest) {
            (data, response, error) in
            // Check for error
            if error != nil {
                self.delegate?.TwitterError(error: error! as NSError)
                return
            } else if let d = data {
                do {
                    if let responseObject = try JSONSerialization.jsonObject(with: d, options: []) as? [String:AnyObject],
                        let arrayStatuses = responseObject["statuses"] as? [[String:AnyObject]] {
                        //print("Data items count: \(arrayStatuses.count)")
                        for status in arrayStatuses {
                            let text = status["text"] as! String
                            let user = status["user"]?["name"]  as! String
                            if let date = status["created_at"] as? String {
                                let dateFormatter = DateFormatter()
                                dateFormatter.dateFormat = "E MMM dd HH:mm:ss Z yyyy"
                                if let date = dateFormatter.date(from: date) {
                                    dateFormatter.dateFormat = "dd/MM/yyyy HH:mm"
                                    let newDate = dateFormatter.string(from: date)
                                    let temp = Tweet(name: user, text: text, date: newDate)
                                    print(temp)
                                    self.delegate?.Tweets(tweet: temp)
                                }
                            }
                        }
                    }
                } catch let error as NSError {
                    self.delegate?.TwitterError(error: error)
                }
            }
            dispatch.leave()
        }
        dispatch.enter()
        task.resume()
        dispatch.wait()
    }
}
