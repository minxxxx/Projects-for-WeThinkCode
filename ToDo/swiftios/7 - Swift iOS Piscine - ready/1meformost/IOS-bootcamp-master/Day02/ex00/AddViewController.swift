//
//  AddViewController.swift
//  ex00
//
//  Created by Marco FERNANDES on 2018/10/03.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

class AddViewController: UIViewController, UITextFieldDelegate {

    @IBOutlet weak var descriptionField: UITextView!
    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var datePicker: UIDatePicker!
    
    
    
    @IBAction func doneButton(_ sender: Any) {
        if (nameField.text != "")
        {
            if (datePicker.date > Date()) {
                let formatter = DateFormatter()

                formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
                let getDate = formatter.string(from: datePicker.date)
                let formatted = formatter.date(from: getDate)
                let dateFormatted = formatter.string(from: formatted!)
                
                let detail = (nameField.text!, dateFormatted , descriptionField.text!)
                Data.Names.append(detail)
                print("Name: " + nameField.text! + "\nDate: " + dateFormatted + "\nDescription: " + descriptionField.text!)
                nameField.text = ""
                descriptionField.text = ""
                self.navigationController?.popViewController(animated: true)
            } else {
                print("Past dates not allowed")
            }
        } else {
            print("Name field is empty")
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
