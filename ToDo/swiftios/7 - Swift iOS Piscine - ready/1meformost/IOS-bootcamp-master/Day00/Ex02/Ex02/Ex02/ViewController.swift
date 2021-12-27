//
//  ViewController.swift
//  Ex02
//
//  Created by Marco FERNANDES on 2018/10/01.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var numberLabel: UILabel!
    
    @IBAction func clearButton(_ sender: Any) {
        print("Cleared was pressed")
        numberLabel.text = ""
    }
    
    // ======================================= //
    @IBAction func addButton(_ sender: Any) {
        print("Add was pressed")
    }
    @IBAction func multiplyButton(_ sender: Any) {
        print("Multiply was pressed")
    }
    @IBAction func minusButton(_ sender: Any) {
        print("Minus was pressed")
    }
    @IBAction func divideButton(_ sender: Any) {
        print("Divide was pressed")
    }
    // ========================================== //

    @IBAction func nineButton(_ sender: Any) {
        numberLabel.text = "9"
        print(9)
    }
    @IBAction func eightButton(_ sender: Any) {
        numberLabel.text = "8"
        print(8)
    }
    @IBAction func sevenButton(_ sender: Any) {
        numberLabel.text = "7"
        print(7)
    }
    @IBAction func sixButton(_ sender: Any) {
        numberLabel.text = "6"
        print(6)
    }
    @IBAction func fiveButton(_ sender: Any) {
        numberLabel.text = "5"
        print(5)
    }
    @IBAction func fourButton(_ sender: Any) {
        numberLabel.text = "4"
        print(4)
    }
    @IBAction func threeButton(_ sender: Any) {
        numberLabel.text = "3"
        print(3)
    }
    @IBAction func twoButton(_ sender: Any) {
        numberLabel.text = "2"
        print(2)
    }
    @IBAction func oneButton(_ sender: Any) {
        numberLabel.text = "1"
        print(1)
    }
    @IBAction func zeroButton(_ sender: Any) {
        numberLabel.text = "0"
        print(0)
    }
    // ================================================= //
    @IBAction func equalButton(_ sender: Any) {
        print("Equals was pressed")
    }
    
    @IBAction func changeType(_ sender: Any) {
        print("Change type was pressed")
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

