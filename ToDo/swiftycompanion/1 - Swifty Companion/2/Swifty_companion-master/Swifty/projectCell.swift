//
//  projectCell.swift
//  Swifty
//
//  Created by Marco FERNANDES on 2018/10/16.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit

class projectCell: UITableViewCell {

    @IBOutlet weak var projectLabel: UILabel!
    @IBOutlet weak var marksLabel: UILabel!
    @IBOutlet weak var loadingView: UIView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
