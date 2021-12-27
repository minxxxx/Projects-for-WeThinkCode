//
//  ViewController.swift
//  swifty-protein
//
//  Created by Antoine JOUANNAIS on 5/26/17.
//  Copyright © 2017 Antoine JOUANNAIS. All rights reserved.
//

import UIKit
import LocalAuthentication

class ViewController: UIViewController {
    let context = LAContext()
    let kMsgShowReason = NSLocalizedString("You need to authenticate, baby", comment: "Reason for authenticating")
    let kMsgFingerOK = NSLocalizedString("Login successful! ✅", comment: "login successful message")

    
    @IBOutlet weak var touchButton: UIButton!
    @IBAction func touchMe(_ sender: UIButton) {
        self.context.evaluatePolicy(.deviceOwnerAuthentication, localizedReason: kMsgShowReason) {
            success, error in
            DispatchQueue.main.async { // necessaire pour affichage dans le main thread
                guard success else {
                    guard let error = error else {
                        self.showUnexpectedErrorMessage()
                        return
                    }
                    self.message.text = error.localizedDescription
                    let alert = UIAlertController(title: "Alert", message: error.localizedDescription, preferredStyle: UIAlertControllerStyle.alert)
                    alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.default, handler: nil))
                    self.present(alert, animated: true, completion: nil)
                    return
                }
                // Good news! Everything went fine 👏
                self.message.text = self.kMsgFingerOK
                self.performSegue(withIdentifier: "SegueToSecond", sender: self)
            }
        }

    }
    
    
    @IBOutlet weak var message: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        var err: NSError?
        guard context.canEvaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, error: &err) else {
            // Print the localized message received by the system
            message.text = err?.localizedDescription
            self.touchButton.isHidden = true
            return
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    private func showUnexpectedErrorMessage() {
        message.text = NSLocalizedString("Unexpected error! 😱", comment: "Message for unexpected error")
    }
    
    
    func application(application: UIApplication, shouldSaveApplicationState coder: NSCoder) -> Bool {
        return false
    }
    
    func application(application: UIApplication, shouldRestoreApplicationState coder: NSCoder) -> Bool {
        return false
    }
}
