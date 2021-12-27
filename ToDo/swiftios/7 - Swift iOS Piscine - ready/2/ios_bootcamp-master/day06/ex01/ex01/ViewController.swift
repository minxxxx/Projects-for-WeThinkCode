//
//  ViewController.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/08.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    var animator : UIDynamicAnimator?
    let gravity = UIGravityBehavior()
    let direction = CGVector(dx: 0.0, dy: 1.0)
    let boundaries = UICollisionBehavior.init()
    let bounce = UIDynamicItemBehavior()
    
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
 
        animator = UIDynamicAnimator(referenceView: self.view)
    }
    
    @IBAction func tapGesture(_ sender: UITapGestureRecognizer) {
        print("tap in position \(sender.location(in: view))")
        let shape = ShapeUIView.init(x: sender.location(in: view).x, y: sender.location(in: view).y)
        view.addSubview(shape)
        
        //gravity
        gravity.addItem(shape)
        gravity.gravityDirection = direction
        
        
        //collsion
        self.boundaries.addItem(shape)
        self.boundaries.translatesReferenceBoundsIntoBoundary = true
        
        //elasticity
        bounce.addItem(shape)
        bounce.elasticity = 0.5
        
        animator?.addBehavior(bounce)
        animator?.addBehavior(boundaries)
        animator?.addBehavior(gravity)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
