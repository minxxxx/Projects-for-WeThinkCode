//
//  ViewController.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/08.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    var animator = UIDynamicAnimator.init()
    let gravity = UIGravityBehavior.init()
    let direction = CGVector(dx: 0.0, dy: 1.0)
    let boundaries = UICollisionBehavior.init()
    let bounce = UIDynamicItemBehavior.init()
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("View Loaded")
        animator = UIDynamicAnimator(referenceView: self.view)
    }
    
    @IBAction func tapGesture(_ sender: UITapGestureRecognizer) {
        print("tap in position \(sender.location(in: view))")
        
        let shape = ShapeUIView.init(x: sender.location(in: view).x, y: sender.location(in: view).y)
        
        let pan_gesture = UIPanGestureRecognizer(target: self, action: #selector(panGesture(_:)))

        let pinch_gesture = UIPinchGestureRecognizer(target: self, action: #selector(pinchGesture(pinchGesture:)))
   
        let rotate_gesture = UIRotationGestureRecognizer(target: self, action: #selector(rotateGesture(rotateGesture:)))

        
        let gests: [UIGestureRecognizer] = [pan_gesture, pinch_gesture, rotate_gesture]
        
        view.addSubview(shape)
        self.behaviors(shape)
        for gest in gests{
            
            shape.addGestureRecognizer(gest)
            print(gest)
        }
        
    }
    
    
    func behaviors(_ shape: ShapeUIView) {
        //gravity
        gravity.addItem(shape)
        gravity.gravityDirection = direction
        
        
        //collsion
        self.boundaries.addItem(shape)
        self.boundaries.translatesReferenceBoundsIntoBoundary = true
        
        //elasticity
        bounce.addItem(shape)
        bounce.elasticity = 0.5
        
        animator.addBehavior(bounce)
        animator.addBehavior(boundaries)
        animator.addBehavior(gravity)
    }
    
//    @objc func pinchGesture(pinchGesture: UIPinchGestureRecognizer)
//    {
//        self.view.bringSubview(toFront: pinchGesture.view!)
//        pinchGesture.view?.transform = (pinchGesture.view?.transform)!.scaledBy(x: pinchGesture.scale, y: pinchGesture.scale)
//        pinchGesture.scale = 1.0
//    }
    @objc func pinchGesture(pinchGesture : UIPinchGestureRecognizer) {
            switch pinchGesture.state {
            case .began:
                gravity.removeItem(pinchGesture.view!)
                boundaries.removeItem(pinchGesture.view!)
                bounce.removeItem(pinchGesture.view!)
            case.changed:
                pinchGesture.view?.layer.bounds.size.height *= pinchGesture.scale
                pinchGesture.view?.layer.bounds.size.width *= pinchGesture.scale
                if let tmp = pinchGesture.view! as? ShapeUIView {
                    if (tmp.circle) {pinchGesture.view!.layer.cornerRadius *= pinchGesture.scale}}
                pinchGesture.scale = 1
            case .ended:
                gravity.addItem(pinchGesture.view!)
                boundaries.addItem(pinchGesture.view!)
                bounce.addItem(pinchGesture.view!)
            case .failed, .cancelled:
                print("Failed or Cancelled")
            case .possible:
                print("Possible")
            }
    }
    
    @objc func panGesture (_ sender: UIPanGestureRecognizer) {
        switch sender.state {
        case .cancelled, .failed, .ended:
            gravity.addItem(sender.view!)
            gravity.gravityDirection = direction
            boundaries.addItem(sender.view!)
            bounce.addItem(sender.view!)
        case .changed, .began, .possible:
            gravity.removeItem(sender.view!)
             boundaries.removeItem(sender.view!)
            bounce.removeItem(sender.view!)
            sender.view?.center = sender.location(in: sender.view?.superview)
            animator.updateItem(usingCurrentState: sender.view!)
        }
    }
    
    @objc func rotateGesture(rotateGesture: UIRotationGestureRecognizer){
        var lastRotation = CGFloat()
        self.view.bringSubview(toFront: rotateGesture.view!)
        if(rotateGesture.state == UIGestureRecognizerState.ended){
            lastRotation = 0.0;
        }
        let rotation = 0.0 - (lastRotation - rotateGesture.rotation)
        // var point = rotateGesture.location(in: viewRotate)
        let currentTrans = rotateGesture.view?.transform
        let newTrans = currentTrans!.rotated(by: rotation)
        rotateGesture.view?.transform = newTrans
        lastRotation = rotateGesture.rotation
    }

//    @objc func rotateGesture(rotateGesture: UIRotationGestureRecognizer){
//        if let view = rotateGesture.view {
//            print(rotateGesture.rotation)
//            switch rotateGesture.state {
//            case .began:
//                print("Began")
//                gravity.removeItem(rotateGesture.view!)
//            case.changed:
//                print("Changed")
//                view.transform = view.transform.rotated(by: rotateGesture.rotation)
//                animator?.updateItem(usingCurrentState: rotateGesture.view!)
//                rotateGesture.rotation = 0
//            case .ended:
//                print("Ended")
//                gravity.addItem(rotateGesture.view!)
//            case .failed, .cancelled:
//                print("Failed or Cancelled")
//            case .possible:
//                print("Possible")
//            }
//        }
//    }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
