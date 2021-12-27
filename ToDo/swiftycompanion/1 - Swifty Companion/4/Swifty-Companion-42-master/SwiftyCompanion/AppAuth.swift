//
//  AppAuth.swift
//  4chan
//
//  Created by Tchang on 06/06/16.
//  Copyright © 2016 Tchang. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON

class AppAuth: NSObject {
    
    var token = String()
    let url = "https://api.intra.42.fr/oauth/token"
    let config = [
        "grant_type" : "client_credentials",
        "client_id": "1692f8821ba52f7303abbdeb915287fbb6c37e850ad4fd69aee62624083c0990",
        "client_secret": "71840f4841f04df776ea21f605b638fc7c3ddce20c8169d56488b5b46da6b35b"]
    
    func get_token() {
        let verif = NSUserDefaults.standardUserDefaults().objectForKey("token")
        if verif == nil {
            Alamofire.request(.POST, url, parameters: config).validate().responseJSON {
                response in
                switch response.result {
                case .Success:
                    if let value = response.result.value {
                        let json = JSON(value)
                        self.token = json["access_token"].stringValue
                        NSUserDefaults.standardUserDefaults().setObject(json["access_token"].stringValue, forKey: "token")
                        print("NEW token:", self.token)
                        self.check_token()
                    }
                case .Failure(let error):
                    print(error)
                }
            }
        } else {
            self.token = verif as! String
            print("SAME token:", self.token)
            check_token()
        }
    }
    
    private func check_token() {
        let check = NSURL(string: "https://api.intra.42.fr/oauth/token/info")
        let bearer = "Bearer " + self.token
        let request = NSMutableURLRequest(URL: check!)
        request.HTTPMethod = "GET"
        request.setValue(bearer, forHTTPHeaderField: "Authorization")
        Alamofire.request(request).validate().responseJSON {
            response in
            switch response.result {
            case .Success:
                if let value = response.result.value {
                    let json = JSON(value)
                    print("The token will expire in:", json["expires_in_seconds"], "seconds.")
                }
            case .Failure:
                print("Error: Trying to get a new token...")
                NSUserDefaults.standardUserDefaults().removeObjectForKey("token")
                self.get_token()
            }
        }
    }
    
    func check_user(user: String, completion: JSON? -> Void) {
        let userUrl = NSURL(string: "https://api.intra.42.fr/v2/users/" + user)
        let bearer = "Bearer " + self.token
        let request = NSMutableURLRequest(URL: userUrl!)
        request.HTTPMethod = "GET"
        request.setValue(bearer, forHTTPHeaderField: "Authorization")
        Alamofire.request(request).validate().responseJSON {
            response in
            switch response.result {
            case .Success:
                if let value = response.result.value {
                    let json = JSON(value)
                    completion(json)
                }
            case .Failure:
                completion(nil)
                print("Error: This login doesn't exists")
            }
        }
    }
}
