//
//  ViewController.swift
//  ex02
//
//  Created by Melissa NAIDOO on 2018/10/01.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var lab: UILabel!
    var sign: String = ""
    var num1: Int = 0
    
    @IBAction func numButtons(_ sender: UIButton) {
        handleInput(input: sender.tag)
    }
    
    func handleInput(input:Int)
    {
        switch input
        {
            case 11:
                print("Equal")
                calculate(num2: Int(lab.text!)!)
            case 12:
                print("Subtraction")
                signPressed(operation: "-")
            case 13:
                print("Addition")
                signPressed(operation: "+")
            case 14:
                print("Clear")
                clear()
            case 15:
                print("Neg")
                lab.text = String(Int(lab.text!)! * (-1))
            case 16:
                print("Multiply")
                signPressed(operation: "*")
            case 17:
                print("Division")
                signPressed(operation: "/")
            default:
                print("Number " + String(input - 1) + " pressed")
                lab.text = lab.text! + String(input - 1)
        }
    }
    
    func signPressed(operation:String)
    {
        num1 = Int(lab.text!)!
        sign = operation
        lab.text = ""
    }
    
    func calculate (num2:Int)
    {
        if (sign == "*")
        {
           lab.text = String(num1 * num2)
        }
        else if (sign == "+")
        {
            lab.text = String(num1 + num2)
        }
        else if (sign == "-")
        {
            lab.text = String(num1 - num2)
        }
        else if (sign == "/")
        {
            if (num2 == 0)
            {
                lab.text = String(num1)
            }
            else
            {
                lab.text = String(Double(num1) / Double(num2))
            }
        }
    }
    
    func clear()
    {
        sign = ""
        num1 = 0
        lab.text = "0"
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

