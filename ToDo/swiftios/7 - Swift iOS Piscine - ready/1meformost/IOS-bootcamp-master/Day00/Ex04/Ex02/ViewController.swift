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
    
    var firstDigit = true
    
    var lastOpperatorPressed = ""
    
    var firstNum = ""
    var secondNum = ""
    
    var clear = false
    
    @IBAction func clearButton(_ sender: Any) {
        numberLabel.text = ""
        firstDigit = true
    }
    
    // ======================================= //
    @IBAction func addButton(_ sender: Any) {
        if (lastOpperatorPressed == "") {
            lastOpperatorPressed = "+"
            firstNum = numberLabel.text!
            clear = true
            firstDigit = true
        } else {
            lastOpperatorPressed = ""
            clear = false
        }
    }
    @IBAction func multiplyButton(_ sender: Any) {
        if (lastOpperatorPressed == "") {
            lastOpperatorPressed = "x"
            firstNum = numberLabel.text!
            clear = true
            firstDigit = true
        } else {
            lastOpperatorPressed = ""
            clear = false
        }
    }
    @IBAction func minusButton(_ sender: Any) {
        if (lastOpperatorPressed == "") {
            lastOpperatorPressed = "-"
            firstNum = numberLabel.text!
            clear = true
            firstDigit = true
        } else {
            lastOpperatorPressed = ""
            clear = false
        }
    }
    @IBAction func divideButton(_ sender: Any) {
        let btn = UIButton(type: UIButtonType.system) as UIButton
        if (lastOpperatorPressed == "") {
            lastOpperatorPressed = "/"
            firstNum = numberLabel.text!
            clear = true
            firstDigit = true
            btn.backgroundColor = UIColor.black
        } else {
            lastOpperatorPressed = ""
            clear = false
        }
    }
    // ========================================== //

    @IBAction func nineButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "9"
        firstDigit = false
    }
    @IBAction func eightButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "8"
        firstDigit = false
    }
    @IBAction func sevenButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "7"
        firstDigit = false
    }
    @IBAction func sixButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "6"
        firstDigit = false
    }
    @IBAction func fiveButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "5"
        firstDigit = false
    }
    @IBAction func fourButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "4"
        firstDigit = false
    }
    @IBAction func threeButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "3"
        firstDigit = false
    }
    @IBAction func twoButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "2"
        firstDigit = false
    }
    @IBAction func oneButton(_ sender: Any) {
        if (clear == true) {
            numberLabel.text = ""
            clear = false
        }
        numberLabel.text = numberLabel.text! + "1"
        firstDigit = false
    }
    @IBAction func zeroButton(_ sender: Any) {
        if (firstDigit == false) {
            if (clear == true) {
                numberLabel.text = ""
                clear = false
            }
            numberLabel.text = numberLabel.text! + "0"
        }
    }
    // ================================================= //
    @IBAction func equalButton(_ sender: Any) {
        let maxInt32 = Int32.max  // 2147483647
        let minInt32 = Int32.min + 1  // -2147483648
        if (numberLabel.text != "0") {
            if (lastOpperatorPressed != "") {
                let one = (firstNum as NSString).integerValue
                let two = (numberLabel.text! as NSString).integerValue
                if (one > maxInt32 || one < minInt32 || two > maxInt32 || two < minInt32) {
                    print("Overflow/Underflow error")
                } else {
                    var result = 0
                    if (lastOpperatorPressed == "+") {
                        result = one + two
                    } else if (lastOpperatorPressed == "-") {
                        result = one - two
                    } else if (lastOpperatorPressed == "/") {
                        result = one / two
                    } else if (lastOpperatorPressed == "x") {
                        result = one * two
                    }
                    if (result > maxInt32 || result < minInt32) {
                        print("OverFlow/UnderFlow error")
                    } else {
                        numberLabel.text = String(result)
                    }
                }
                lastOpperatorPressed = ""
            }
        } else {
            lastOpperatorPressed = ""
            numberLabel.text = "Error"
        }
    }
    
    @IBAction func changeType(_ sender: Any) {
        if (numberLabel.text != "") {
        if (numberLabel.text!.first == "-") {
                numberLabel.text!.remove(at: numberLabel.text!.startIndex)
            } else {
                let newValue = "-" + numberLabel.text!
                numberLabel.text = newValue
            }
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

