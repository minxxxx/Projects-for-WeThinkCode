//
//  tweetTableViewCell.swift
//  D04
//
//  Created by Marco on 5/10/2018.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit

class tweetTableViewCell: UITableViewCell {
    
    @IBOutlet weak var tweetLabel: UILabel!
    @IBOutlet weak var namelabel: UILabel!
    @IBOutlet weak var dateLabel: UILabel!
    
    func appendLabel(details: Tweet) {
        namelabel.text = details.name
        dateLabel.text = details.date
        tweetLabel.text = details.text
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
