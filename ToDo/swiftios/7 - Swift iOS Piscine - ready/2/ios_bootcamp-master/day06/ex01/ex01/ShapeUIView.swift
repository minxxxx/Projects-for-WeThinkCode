//
//  ShapeUIView.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/08.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ShapeUIView: UIView {
    
   init(x: CGFloat, y: CGFloat) {
        let i = arc4random()%2
        let color = UIColor.init(red: CGFloat(drand48()), green: CGFloat(drand48()), blue: CGFloat(drand48()), alpha: 1)
        super.init(frame: CGRect(x: x - 100/2, y: y - 100/2, width: 100, height: 100))
        self.backgroundColor = color
        if i == 0
        {
            self.layer.cornerRadius = self.frame.size.width/2
        }
    }
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
   
    
    
}
