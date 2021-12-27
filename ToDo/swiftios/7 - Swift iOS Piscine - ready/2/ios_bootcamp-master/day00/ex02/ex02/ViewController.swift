//
//  ViewController.swift
//  ex02
//
//  Created by Melissa NAIDOO on 2018/10/01.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var label: UILabel!
    
    @IBAction func numbers(_ sender: UIButton) {
        
        label.text = label.text! + String(sender.tag - 1)
        print("Number " + String(sender.tag - 1) + " is pressed")
        
    }
    
    @IBAction func actions(_ sender: UIButton) {
        
        switch (sender.tag) {
        case 12 : print("clear")
            return
        case 13 : print("change sign of number")
            return
        case 14 : print("equals")
            return
        case 15 : print("subtract")
            return
        case 16 : print("divide")
            return
        case 17 : print("add")
            return
        case 18 : print("multiply")
            return
        default:
            print("hello")
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

