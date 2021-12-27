//
//  TopProfileViewController.swift
//  swiftyComp
//
//  Created by Melissa NAIDOO on 2018/10/18.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class TopProfileViewController: UIViewController{
    
    var User : Users!
    let alert = ViewController()

    @IBOutlet weak var levelBar: UILabel!
    @IBOutlet weak var usernameLabel: UILabel!
    @IBOutlet weak var correctionLabel: UILabel!
    @IBOutlet weak var walletLabel: UILabel!
    @IBOutlet weak var emailLabel: UILabel!
    @IBOutlet weak var userImage: UIImageView!
    @IBOutlet weak var lastNameLabel: UILabel!
    @IBOutlet weak var firstNameLabel: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()

        //make image circular
        self.userImage.layer.borderWidth = 1
        self.userImage.layer.masksToBounds = false
        self.userImage.layer.borderColor = UIColor.white.cgColor
        self.userImage.layer.cornerRadius = self.userImage.frame.height/2
        self.userImage.clipsToBounds = true
       
        self.usernameLabel.text = "\(self.User.login)".capitalized
        self.correctionLabel.text = "Evaluation Points: \(self.User.correction_point)"
        self.emailLabel.text = "Email: \(self.User.email)"
        self.walletLabel.text = "Wallet: \(self.User.wallet)"
        self.firstNameLabel.text = "First Name: \(self.User.first_name)".capitalized
        self.lastNameLabel.text = "Last Name: \(self.User.last_name)".capitalized
        self.levelBar.text = "Level: \(String(format: "%.2f", self.User.cursus_users[0].level))%"
        
        let cut = self.User.image_url.split(separator: "/")[3]
        downloadImage(url: "https://cdn.intra.42.fr/users/medium_\(cut)")

    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    //Downloading image
    func downloadImage(url: String)
    {
        let url:URL = URL(string: url)!
        let session = URLSession.shared
        let task = session.dataTask(with: url, completionHandler: {
            (data, response, error) in
            if data != nil
            {
                let image = UIImage(data: data!)
                
                if(image != nil)
                {
                    DispatchQueue.main.async(execute: {
                        self.userImage.image = image
                    })
                }
            } else {
                self.alert.creatAlert(title: "Download Error", message: "Could not download image")
            }
        })
        task.resume()
    }

}
