//
//  ProfileViewController.swift
//  Swifty
//
//  Created by Marco FERNANDES on 2018/10/15.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var emailLabel: UILabel!
    @IBOutlet weak var correctionLabel: UILabel!
    @IBOutlet weak var lvlLabel: UILabel!
    @IBOutlet weak var navBar: UINavigationBar!
    @IBOutlet weak var profileImage: UIImageView!
    @IBOutlet weak var infoTable: UITableView!
    @IBOutlet weak var detailButton: UIButton!
    @IBOutlet weak var tableName: UILabel!
    
    // 0 = projects
    // 1 = levels
    var type = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // ui setup
        emailLabel.layer.masksToBounds = true
        correctionLabel.layer.masksToBounds = true
        lvlLabel.layer.masksToBounds = true
        emailLabel.layer.cornerRadius = 10
        correctionLabel.layer.cornerRadius = 10
        lvlLabel.layer.cornerRadius = 10
        // apply details
        navBar.topItem?.title = api.displayName
        emailLabel.text = String("   Username: " +  api.login)
        correctionLabel.text = String("   Correction: " + api.correctionPoints)
        lvlLabel.text = String("   Level: " + api.level)
        // assign image here
        api.getImage(profileImage: profileImage)
        profileImage.layer.masksToBounds = true
        profileImage.layer.cornerRadius = 30
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func moreDetailsButton(_ sender: Any) {
        if type == 0 {
            type = 1
            detailButton.setTitle("Project Details", for: .normal)
            tableName.text = "Skills"
            infoTable.reloadData()
        } else {
            type = 0
            detailButton.setTitle("Skills Details", for: .normal)
            tableName.text = "Projects"
            infoTable.reloadData()
        }
    }
    
    @IBAction func searchButton(_ sender: Any) {
        api.resetValues()
        type = 0
        self.dismiss(animated: true, completion: nil)
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if type == 0 {
            return api.projects.count
        } else {
            return api.skills.count
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "projectCell") as! projectCell
        if type == 0 {
            cell.projectLabel.text = api.projects[indexPath.row].0
            cell.marksLabel.text = String(api.projects[indexPath.row].1)
        } else {
            cell.projectLabel.text = api.skills[indexPath.row].0
            cell.marksLabel.text = String(api.skills[indexPath.row].1)
        }
        return cell
    }
}
