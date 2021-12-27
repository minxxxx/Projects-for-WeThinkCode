//
//  LoginViewController.swift
//  Proteins
//
//  Created by Marco FERNANDES on 2018/10/17.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit
import LocalAuthentication

var protiens: [String] = []
let context:LAContext = LAContext()

class LoginViewController: UIViewController {

    @IBOutlet weak var gifView: UIImageView!
    @IBOutlet weak var loginButton: UIButton!
    

    override func viewDidLoad() {
        super.viewDidLoad()
        readFile()
        gifView.loadGif(name: "source")
        loginButton.layer.masksToBounds = true
        loginButton.layer.cornerRadius = 20
        // Do any additional setup after loading the view.
        if context.canEvaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, error: nil) {
            loginButton.isHidden = false
        } else {
            loginButton.isHidden = true
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func readFile() {
        if let path = Bundle.main.path(forResource: "ligands", ofType: "txt") {
            do {
                let data = try String(contentsOfFile: path, encoding: .utf8)
                protiens = data.components(separatedBy: .newlines)
            } catch {
                print(error)
            }
        }
    }
    
    // touch ID
    @IBAction func touchID(_ sender: Any) {
        if context.canEvaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, error: nil) {
            context.evaluatePolicy(LAPolicy.deviceOwnerAuthenticationWithBiometrics, localizedReason: "We need your fingerprint for access", reply: {(wasCorrect, error) in
                if wasCorrect {
                    let searchView = self.storyboard?.instantiateViewController(withIdentifier: "SearchView") as! SearchViewController
                    self.present(searchView, animated: false, completion: nil)
                } else {
                    self.sendAlertMessage(message: "biometeric scan did not match")
                }
            })
        } else {
            self.sendAlertMessage(message: "no biometeric hardware found")
        }
    }
    
    func sendAlertMessage(message: String)
    {
        let alert = UIAlertController(title: "Alert", message:  message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        
        self.present(alert, animated: true, completion: nil)
    }
    
}
