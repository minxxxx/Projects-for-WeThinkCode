//
//  ViewController.swift
//  Swifty
//
//  Created by Leslie DE JAGER on 2018/10/15.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit

let api = ApiController()

class ViewController: UIViewController {

    @IBOutlet weak var inputLabel: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        api.initialise()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        api.resetValues()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func searchButton(_ sender: Any) {
        let trimmedString = (inputLabel.text?.trimmingCharacters(in: .whitespacesAndNewlines))?.lowercased()
        if (trimmedString == "") {
            sendAlertMessage(errorTitle: "Input Error", message: "input is empty")
        } else {
            if api.doesUserExist(login: trimmedString!) == true {
                let profileView = self.storyboard?.instantiateViewController(withIdentifier: "ProfileView") as! ProfileViewController
                self.present(profileView, animated: true, completion: nil)
            } else {
                sendAlertMessage(errorTitle: "Request Error", message: "user not found")
            }
        }
    }
    
    // alert popup
    func sendAlertMessage(errorTitle: String, message: String)
    {
        let alert = UIAlertController(title: errorTitle, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        self.present(alert, animated: true, completion: nil)
    }
    
}

