//
//  ViewController.swift
//  ex01
//
//  Created by Melissa NAIDOO on 2018/10/01.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var helloLabel: UILabel!
    @IBAction func helloButton(_ sender: UIButton) {
        helloLabel.text = "Hello World !"
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

