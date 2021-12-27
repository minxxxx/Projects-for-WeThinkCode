//
//  ProfileViewController.swift
//  4chan
//
//  Created by Tchang on 07/06/16.
//  Copyright © 2016 Tchang. All rights reserved.
//

import UIKit
import SwiftyJSON

class ProfileViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    var data: JSON?
    @IBOutlet weak var profileImage: UIImageView!
    @IBOutlet weak var loginText: UITextField!
    @IBOutlet weak var nameText: UITextField!
    @IBOutlet weak var phoneText: UITextField!
    
    @IBOutlet weak var tableViewSkill: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.backgroundColor = UIColor(patternImage: UIImage(imageLiteral: "background"))
        self.title = data!["login"].string! + " - " + String(data!["cursus"][0]["level"])
        
        tableViewSkill.delegate = self
        tableViewSkill.dataSource = self
        self.tableViewSkill.backgroundColor = UIColor.clearColor()
        
        loadImage()
        loadTextField()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func loadTextField() {
        loginText.enabled = false
        nameText.enabled = false
        phoneText.enabled = false
        if let location = data!["location"].string {
            loginText.text = location
        }
        if let name = data!["displayname"].string {
            nameText.text = name
        }
        if let phone = data!["phone"].string {
            phoneText.text = phone
        }
    }
    
    func loadImage() {
        let strUrl = data!["image_url"].string!
        if let url = NSURL(string: strUrl) {
            if let data = NSData(contentsOfURL: url) {
                profileImage.image = UIImage(data: data)
            } else {
                profileImage.image = UIImage(imageLiteral: "doge")
            }
        }
    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return UITableViewAutomaticDimension
    }
    
    func tableView(tableView: UITableView, estimatedHeightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return UITableViewAutomaticDimension
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return data!["cursus"][0]["skills"].count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("skillCell", forIndexPath: indexPath) as! skillTableViewCell
        let level = data!["cursus"][0]["skills"][indexPath.row]["level"].float
        let name = data!["cursus"][0]["skills"][indexPath.row]["name"].string
        let fill: String = name! + " - " + String(level!)
        cell.backgroundColor = UIColor.clearColor()
        cell.skillText.text = fill
        cell.skillText.textColor = UIColor.whiteColor()
        cell.skillText.enabled = false
        cell.skillBar.setProgress(level! / 20, animated: true)
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        tableView.deselectRowAtIndexPath(indexPath, animated: true)
    }
}
