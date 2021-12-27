//
//  ViewController.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/08.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
     }
    
    @IBAction func tapGesture(_ sender: UITapGestureRecognizer) {
        print("tap in position \(sender.location(in: view))")
        let shape = ShapeUIView.init(x: sender.location(in: view).x, y: sender.location(in: view).y)
        view.addSubview(shape)
    }
    

    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
