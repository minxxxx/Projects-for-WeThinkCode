//
//  ViewController.swift
//  Day06
//
//  Created by Marco FERNANDES on 2018/10/09.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit
import CoreMotion

var shapesInView:[CreateShape] = []

class ViewController: UIViewController {
    
    let dynamicAnimator = UIDynamicAnimator()
    let gravity = UIGravityBehavior()
    let collision = UICollisionBehavior()
    let behavior = UIDynamicItemBehavior(items: [])
    let accManager = CMMotionManager()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        gravity.magnitude = 5
        
        dynamicAnimator.addBehavior(gravity)
        // set the view bounds
        collision.addBoundary(withIdentifier: "left" as NSCopying, from: CGPoint(x: 0.0, y: 0.0), to: CGPoint(x: 0.0, y: view.bounds.size.height))
        collision.addBoundary(withIdentifier: "right" as NSCopying, from: CGPoint(x: view.bounds.size.width, y: 0.0), to: CGPoint(x: view.bounds.size.width, y: view.bounds.size.height))
        collision.addBoundary(withIdentifier: "top" as NSCopying, from: CGPoint(x: 0.0, y: 0.0), to: CGPoint(x: view.bounds.size.width, y: 0.0))
        collision.addBoundary(withIdentifier: "bottom" as NSCopying, from: CGPoint(x: 0.0, y: view.bounds.size.height), to: CGPoint(x: view.bounds.size.width, y: view.bounds.size.height))
        dynamicAnimator.addBehavior(collision)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        if (accManager.isAccelerometerAvailable) {
            accManager.accelerometerUpdateInterval = 0.2
            accManager.startAccelerometerUpdates(to: OperationQueue.current!) {
                (data,  error) in
                if let data = data {
                    self.gravity.gravityDirection = CGVector(dx: data.acceleration.x, dy: -data.acceleration.y)
                }
            }
        } else {
            print("accelorameter not found")
        }
    }
    
    // what the pinch gesture does when used on the shape view
    @objc func resize(_ pinchGesture: UIPinchGestureRecognizer) {
        let view = pinchGesture.view as! CreateShape
        switch pinchGesture.state {
        case .began:
            gravity.removeItem(view)
        case .changed:
            collision.removeItem(view)
            behavior.removeItem(view)
            if (view.bounds.size.width <= 20) {
                view.bounds.size.width = 21
                view.bounds.size.height = 21
            } else if (view.bounds.size.width >= 151) {
                view.bounds.size.width = 150
                view.bounds.size.height = 150
            } else {
                view.bounds.size.width = view.bounds.size.width * pinchGesture.scale
                view.bounds.size.height = view.bounds.size.height * pinchGesture.scale
            }
            collision.addItem(view)
            behavior.addItem(view)
            dynamicAnimator.updateItem(usingCurrentState: view)
        case .ended:
            gravity.addItem(view)
        default:
            break ;
        }
    }
    
    // what the panning gesture does when used on the shape view
    @objc func panning(panGesture: UIPanGestureRecognizer) {
        switch panGesture.state {
        case .began:
            self.gravity.removeItem(panGesture.view!);
        case .changed:
            panGesture.view?.center = panGesture.location(in: self.view);
            self.dynamicAnimator.updateItem(usingCurrentState: panGesture.view!);
        case .ended:
            self.gravity.addItem(panGesture.view!);
        default:
            break ;
        }
    }
    
    // what the rotate gesture does when used on the shape view
    @objc func rotate(rotationGesture: UIRotationGestureRecognizer) {
        switch rotationGesture.state {
        case .began:
            self.gravity.removeItem(rotationGesture.view!);
        case .changed:
            self.collision.removeItem(rotationGesture.view!);
            self.behavior.removeItem(rotationGesture.view!)
            rotationGesture.view!.transform = rotationGesture.view!.transform.rotated(by: rotationGesture.rotation);
            rotationGesture.rotation = 0;
            self.collision.addItem(rotationGesture.view!);
            self.behavior.addItem(rotationGesture.view!)
            self.dynamicAnimator.updateItem(usingCurrentState: rotationGesture.view!);
        case .ended:
            self.gravity.addItem(rotationGesture.view!);
        default:
            break ;
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func tapGesture(_ sender: UITapGestureRecognizer) {
        print("Tapped!!")
        let Center = sender.location(in: view)
        let Width = CGFloat(100)
        let Height = Width
        // randomize the shape type 0:circle
        let type = Int(arc4random_uniform(2) + 0)
        let shape = CreateShape(frame: CGRect(x: Center.x - (Width/2), y: Center.y - (Height/2), width: Width, height: Height), type: type)
        behavior.addItem(shape)
        behavior.elasticity = 0.6
        dynamicAnimator.addBehavior(behavior)
        gravity.addItem(shape)
        // give shape the collision
        collision.addItem(shape)
        
        // give the shape a PanGesture
        let panGesture = UIPanGestureRecognizer(target: self, action: #selector(panning));
        shape.addGestureRecognizer(panGesture)
        // give the shape a PinchGesture
        let pinchGesture = UIPinchGestureRecognizer(target: self, action: #selector(resize))
        shape.addGestureRecognizer(pinchGesture)
        // give the shape a RotateGesture
        let rotateGesture = UIRotationGestureRecognizer(target: self, action: #selector(rotate))
        shape.addGestureRecognizer(rotateGesture)
        
        shape.isUserInteractionEnabled = true
        shapesInView.append(shape)
        view.addSubview(shape)
    }
    
}

