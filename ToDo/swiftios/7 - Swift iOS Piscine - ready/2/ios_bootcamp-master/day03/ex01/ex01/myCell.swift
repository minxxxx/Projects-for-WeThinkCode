//
//  myCell.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/05.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class myCell: UICollectionViewCell {
    
    
    @IBOutlet weak var myImageView: UIImageView!
    
    @IBOutlet weak var spinner: UIActivityIndicatorView!
    
    func spinner (shouldSpin status: Bool)
    {
        if status == true{
            spinner.isHidden = false
            spinner.startAnimating()
        }
        else
        {
            spinner.isHidden = true
            spinner.stopAnimating()
        }
    }
    
}
