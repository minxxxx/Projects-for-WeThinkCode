//
//  ViewController.swift
//  swifty_companion
//
//  Created by Melissa NAIDOO on 2018/10/16.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit
import Foundation

class ViewController: UIViewController {

    @IBOutlet weak var search: UIButton!
    @IBOutlet weak var usernameText: UITextField!
    @IBAction func searchUsername(_ sender: UIButton) {
        search.setTitle("Searching...", for: .normal)
        if (usernameText.text == "" || usernameText.text == nil)
        {
            self.creatAlert(title: "Error", message: "Please enter a valid username")
            search.setTitle("Search Username", for: .normal)
        }
        else
        {
            APIController().getUser(username: usernameText.text!, with: { data in
                    guard let userData = try? JSONDecoder().decode(Users.self, from: data) else {
                        DispatchQueue.main.async {
                            self.creatAlert(title: "Error", message: "The username does not exist")
                            self.search.setTitle("Search Username", for: .normal)
                        }
                        return
                    }
                    print("first_name: \(userData.first_name)")
                    print("last_name: \(userData.last_name)")
                    print("login: \(userData.login)")
                    print("email: \(userData.email)")
                    print("imageUrl: \(userData.image_url)")
                    print("correction_point: \(userData.correction_point)")
                    print("wallet : \(userData.wallet)")
                APIController.USER = userData
                DispatchQueue.main.async {
                    self.performSegue(withIdentifier: "profilePage", sender: self)
                    self.search.setTitle("Search Username", for: .normal)
                }
            }, with: { err in
                print("error: ", err.localizedDescription)
            })
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("start")
        APIController().request(req: APIController().getCodeRequest(), with: {data in
            print("Ok")
        }, with: {error in print("Err")})
        print("end")
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if(segue.identifier == "profilePage")
        {
            if let nextViewController = segue.destination as? ParentViewController{
                 nextViewController.User = APIController.USER
            }
        }
    }
    
    func creatAlert(title:String, message:String)
    {
        let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: { (action) in
            alert.dismiss(animated: true, completion: nil)
        }))
        
        self.present(alert, animated: true, completion: nil)
    }
 
}
