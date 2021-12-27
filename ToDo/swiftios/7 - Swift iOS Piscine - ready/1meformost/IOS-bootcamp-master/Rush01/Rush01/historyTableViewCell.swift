//
//  historyTableViewCell.swift
//  Rush01
//
//  Created by Marco FERNANDES on 2018/10/13.
//  Copyright © 2018 Thato MEKWA. All rights reserved.
//

import UIKit

class historyTableViewCell: UITableViewCell {

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var subtitleLable: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
