//
//  ViewController.swift
//  4chan
//
//  Created by Tchang on 04/06/16.
//  Copyright © 2016 Tchang. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON

class ViewController: UIViewController {
    
    @IBOutlet weak var loginText: UITextField!
    @IBOutlet weak var loadButton: UIButton!
    
    var jsonData: JSON?
    var auth = AppAuth()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Mvallet - Intra 42"
        self.view.backgroundColor = UIColor(patternImage: UIImage(imageLiteral: "background"))
        auth.get_token()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func onLoad(sender: UIButton) {
        if loginText.text != "" {
            loadButton.enabled = false
            let login = loginText.text?.stringByReplacingOccurrencesOfString(" ", withString: "", options: NSStringCompareOptions.LiteralSearch, range: nil)
            auth.check_user(login!) {
                completion in
                if completion != nil {
                    self.jsonData = completion
                    self.performSegueWithIdentifier("Profile", sender: nil)
                    self.loadButton.enabled = true
                } else {
                    let alert = UIAlertController(title: "Error", message: "This login doesn't exists", preferredStyle: UIAlertControllerStyle.Alert)
                    alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default, handler: nil))
                    self.presentViewController(alert, animated: true, completion: nil)
                    self.loadButton.enabled = true
                }
            }
        }
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "Profile" {
            let new = segue.destinationViewController as! ProfileViewController
            new.data = jsonData
        }
    }
}