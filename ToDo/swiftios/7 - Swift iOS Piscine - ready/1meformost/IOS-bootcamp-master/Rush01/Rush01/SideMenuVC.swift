//
//  SideMenuVC.swift
//  Rush01
//
//  Created by Thato MEKWA on 2018/10/13.
//  Copyright © 2018 Thato MEKWA. All rights reserved.
//

import UIKit

class SideMenuVC: UITableViewController {

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print(indexPath.row)
         NotificationCenter.default.post(name: NSNotification.Name("ToggleSideMenu"), object: nil)
        switch indexPath.row {
        case 0:
            print("Apple Maps")
        case 1:
             NotificationCenter.default.post(name: NSNotification.Name("showNavigation"), object: nil)
        case 2:
             NotificationCenter.default.post(name: NSNotification.Name("showSignIn"), object: nil)
        default:
            break;
        }
    }

}
