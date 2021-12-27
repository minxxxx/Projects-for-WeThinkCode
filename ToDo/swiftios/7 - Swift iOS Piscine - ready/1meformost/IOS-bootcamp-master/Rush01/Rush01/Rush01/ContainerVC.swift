//
//  ViewController.swift
//  Rush01
//
//  Created by Thato MEKWA on 2018/10/12.
//  Copyright © 2018 Thato MEKWA. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class ContainerVC: UIViewController{
    
    @IBOutlet weak var sideMenuConstraint:NSLayoutConstraint!
    var sideMenuOpen = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("View is loaded")
        
        NotificationCenter.default.addObserver(self, selector: #selector(toggleSideMenu), name: NSNotification.Name("ToggleSideMenu"), object: nil)
    }
    
    @objc func toggleSideMenu()  {
        if sideMenuOpen {
            
            sideMenuOpen = false
            sideMenuConstraint.constant = -240
        }else{
            sideMenuOpen = true
            sideMenuConstraint.constant = 0
        }
    }
}

