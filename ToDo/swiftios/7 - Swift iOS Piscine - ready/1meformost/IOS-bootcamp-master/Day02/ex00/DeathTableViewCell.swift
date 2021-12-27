//
//  DeathTableViewCell.swift
//  ex00
//
//  Created by Marco FERNANDES on 2018/10/03.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

class DeathTableViewCell: UITableViewCell {
    
    
    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var dateLabel: UILabel!
    @IBOutlet weak var detailLabel: UILabel!
    
    var death : (String, String, String)? {
        didSet {
            if let d = death {
                nameLabel?.text = d.0
                dateLabel?.text = d.1
                detailLabel?.text = d.2
            }
        }
    }

}
