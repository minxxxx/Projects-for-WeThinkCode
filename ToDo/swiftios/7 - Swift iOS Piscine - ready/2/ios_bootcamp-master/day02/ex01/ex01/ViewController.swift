//
//  ViewController.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/04.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var tableView: UITableView!{
        didSet {
            tableView.delegate = self
            tableView.dataSource = self
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return Data.name.count
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "deathcell")
        cell?.textLabel?.text = Data.name[indexPath.row].0
        cell?.detailTextLabel?.text = String( Data.name[indexPath.row].1)
        return cell!
    }
    


}

