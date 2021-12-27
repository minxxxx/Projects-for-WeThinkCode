//
//  APIController.swift
//  swifty_companion
//
//  Created by Melissa NAIDOO on 2018/10/17.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import Foundation
import UIKit

public class APIController: UIViewController{
    
    
    static var CONSUMER_KEY:String = "e141b7db56dbb2770f747da79497b3e4b0f5854201108cdf6789c86dcd2103a7"
    static var CONSUMER_SECRET:String = "27de36182639dbf3cdd04548e719a1dd6f97b3c40389fc38ecb5f77819fba5ed"
    static var TOKEN: String = ""
    static var USER:Users!
    let spin = ViewController()
    

    func getCodeRequest() -> NSMutableURLRequest {
        let url: URL = URL(string: "https://api.intra.42.fr/oauth/token")!
        let request: NSMutableURLRequest = NSMutableURLRequest(url: url)
        var grant = ""
        
        grant = "grant_type=client_credentials"
        grant += "&client_id=\(APIController.CONSUMER_KEY)"
        grant += "&client_secret=\(APIController.CONSUMER_SECRET)"
        request.httpMethod = "POST"
        request.httpBody = grant.data(using: String.Encoding.utf8)
        return(request)
    }
    
     func getUser(username: String, with successFunc: @escaping (Data) -> (Void), with errorFunc: @escaping (Error) -> (Void)){
        let req = NSMutableURLRequest(url: NSURL(string:"https://api.intra.42.fr/v2/users/\(username.lowercased())")! as URL)
        req.httpMethod = "GET"
        req.addValue("Bearer \(APIController.TOKEN)", forHTTPHeaderField: "Authorization")
        URLSession.shared.dataTask(with: req as URLRequest) { data, response, error in
            if error != nil {
                //Your HTTP request failed.
                errorFunc(error!)
            }
            else {
                //Your HTTP request succeeded
                successFunc(data!)
            }
        }.resume()
    }
    
    func request(req: NSMutableURLRequest, with successCallBack: @escaping (Data) -> (Void), with errorCallBack: @escaping (Error) -> (Void)){
        let task = URLSession.shared.dataTask(with: req as URLRequest){
            (data, response, error) in
            if let err = error{
                DispatchQueue.main.async {
                    // UIApplication.shared.isNetworkActivityIndicatorVisible = false
                    errorCallBack(err)
                }
            }
            else if let d = data{
                DispatchQueue.main.async {
                    
                    do {
                        if let resp: NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary {
                            print("resp: ", resp)
                            
                            APIController.TOKEN = (resp["access_token"] as! String)
                            print(APIController.TOKEN)
                        }
                    }
                    catch (let err) {
                        print("catch err: ",err)
                    }
                    
                    successCallBack(d)
                }
            }else{
                print("Error with request")
                }
        }
        
        // UIApplication.shared.isNetworkActivityIndicatorVisible = true
        task.resume()
    }
}
