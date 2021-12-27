//
//  ViewController.swift
//  D04
//
//  Created by Marco on 2018/10/05.
//  Copyright © 2018 Marco. All rights reserved.
//

import UIKit



class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, APITwitterDelegate  {
    
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var inputText: UITextField!

    let userInfo: [AnyHashable : Any] = [
    NSLocalizedDescriptionKey :  NSLocalizedString("Unauthorized", value: "Something went wrong clearly", comment: "")]
    
    var to = ""
    var tweets : [Tweet] = []
    
    // append all gotten tweets here
    func Tweets(tweet: Tweet) {
        print("=============================================================")
        self.tweets.append(tweet)
    }
    
    // print out an alert message
    func TwitterError(error: NSError) {
        let alert = UIAlertController(title: "Oh-no!:", message: error.domain, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.tweets.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "tweetCell") as! tweetTableViewCell
        //cell.death = Data.Names[indexPath.row]
        cell.appendLabel(details: self.tweets[indexPath.row])
        return cell
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        connect()
        self.inputText.delegate = self
    }
    
    

    
    func textFieldShouldReturn(_ textField:UITextField) -> Bool {
        textField.resignFirstResponder()
        let test = APIController(delegate: self, token: self.to)

        if (inputText.text != "") {
            tweets.removeAll()
            test.requestTwitter(variable: inputText.text! )
            tableView.reloadData()
        } else {
            let err = NSError(domain: "Empty Text Field", code: 100, userInfo: userInfo as? [String : Any])
            TwitterError(error: err)
        }
        return true
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func connect()
    {
        let customerKey = "0q9lIPPpotMDDcBB2qDMVWgT4"
        let customerSecret = "VTbhUM9NOqLDN8U4evnDdXrE58JyFkcuNy4924aXqtqeX8sdT7"
        let bearer = ((customerKey + ":" + customerSecret).data(using: String.Encoding.utf8))!.base64EncodedString(options: NSData.Base64EncodingOptions(rawValue: 0))
        let url = URL(string: "https://api.twitter.com/oauth2/token")
        let request = NSMutableURLRequest(url: url!)
        request.httpMethod = "POST"
        
        request.setValue("Basic \(bearer)", forHTTPHeaderField: "Authorization")
        request.setValue("application/x-www-form-urlencoded;charset=UTF-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = "grant_type=client_credentials".data(using: String.Encoding.utf8)
        
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            print(response as Any)
            if let err = error{
                let errNs = NSError(domain: "Connection Error", code: 402, userInfo: self.userInfo as? [String : Any])
                self.TwitterError(error: errNs)
                print(err)
            }
            else if let d = data{
                do{
                    if let dic : NSDictionary = try JSONSerialization.jsonObject(with: d, options: JSONSerialization.ReadingOptions.mutableContainers) as? NSDictionary{
                        if let temp = dic["access_token"] {
                            self.to = (temp as? String)!
                        }
                    }
                }
                catch(let err){
                    let errNs = NSError(domain: "Connection Error", code: 404, userInfo: self.userInfo as? [String : Any])
                    self.TwitterError(error: errNs)
                    print(err)
                }
            }
        }
        task.resume()
    }

}

