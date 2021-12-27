//
//  CircleView.swift
//  Day06
//
//  Created by Marco FERNANDES on 2018/10/09.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

extension CGFloat {
    static func random() -> CGFloat {
        return (CGFloat(arc4random()) / CGFloat(UInt32.max))
    }
}

extension UIColor {
    static var random:UIColor {
        return UIColor(red: .random(), green: .random(), blue: .random(), alpha: .random())
    }
}

class CreateShape: UIView {

    /*
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        // Drawing code
    }
    */
    
    var typeGiven: Int?
    
    
    
    override var collisionBoundsType: UIDynamicItemCollisionBoundsType {
        switch typeGiven {
        case 0:
            return .ellipse
        default:
            return .rectangle
        }
    }
    
    init(frame: CGRect, type: Int) {
        super.init(frame: frame)
        self.backgroundColor = UIColor.clear
        typeGiven = type
    }
    
    required init(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func draw(_ rect: CGRect) {
        // Get the Graphics Context
        if (typeGiven == 0) {
            let path = UIBezierPath(ovalIn: rect)
            UIColor.random.setFill()
            path.fill()
        } else if (typeGiven == 1) {
            let path = UIBezierPath(rect: rect)
            UIColor.random.setFill()
            path.fill()
        }
    }

}
