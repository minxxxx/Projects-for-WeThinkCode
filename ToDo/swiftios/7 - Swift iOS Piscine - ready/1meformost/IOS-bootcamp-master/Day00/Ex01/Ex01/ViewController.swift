//
//  ViewController.swift
//  Ex01
//
//  Created by Marco FERNANDES on 2018/10/01.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var label: UILabel!
    
    @IBAction func clickMe(_ sender: Any) {
        if (label.text == "Hello") {
            label.text = "world!"
        } else {
            label.text = "Hello"
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

