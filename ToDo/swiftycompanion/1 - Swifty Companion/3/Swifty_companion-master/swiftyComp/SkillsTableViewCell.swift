//
//  SkillsTableViewCell.swift
//  swiftyComp
//
//  Created by Melissa NAIDOO on 2018/10/19.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class SkillsTableViewCell: UITableViewCell {

    
    @IBOutlet weak var skillName: UILabel!
    @IBOutlet weak var skillLevel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
