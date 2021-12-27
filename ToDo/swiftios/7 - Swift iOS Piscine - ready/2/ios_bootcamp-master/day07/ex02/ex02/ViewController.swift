//
//  ViewController.swift
//  ex02
//
//  Created by Melissa NAIDOO on 2018/10/11.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit
import RecastAI
import ForecastIO


class ViewController: UIViewController {

    
    @IBOutlet weak var responseLabel: UILabel!
    @IBOutlet weak var requestText: UITextField!
    @IBAction func submitRequestButton(_ sender: Any) {
        self.RequestText()
    }
    var bot : RecastAIClient?
    let client = DarkSkyClient(apiKey: "ba544639ae8cc8e675c94659a2ac6904")

    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("loaded view")
        
        self.requestText.delegate = self as? UITextFieldDelegate
        self.bot = RecastAIClient(token : "3c11a0bd9bfbb06bac7ef9f007bf2186", language: "en")
        client.language = .english
    }
    
    func TextFieldAction(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        self.RequestText()
        return true
    }
    
    func RequestText() {
        print (requestText.text as Any)
        if (requestText.text != nil && requestText.text != "") {
            self.makeRequest(request: requestText.text!)
        }
    }

    func makeRequest(request: String)
    {
        self.bot?.textRequest(request, successHandler: { (response) in
            let location = response.get(entity: "location")
            print("location", location as Any)
            if (location != nil) {
                let latitude = location!["lat"]?.doubleValue
                let longitude = location!["lng"]?.doubleValue
                print("lat", latitude as Any, "lng", longitude as Any)
                if (latitude != nil && longitude != nil)
                {
                    self.getWheather(latitude: latitude!, longitude: longitude!)
                }
                else
                {
                    self.responseLabel.text = "Error with Recast API try again"
                }
            }
            else
            {
                self.responseLabel.text = "Enter a valid city"
            }
        },failureHandle: { (error) in
            print("error", error)
            self.responseLabel.text = "Error with Recast call"
        })
    }
    
    
    func getWheather(latitude: Double, longitude: Double)
    {
        client.getForecast(latitude: latitude, longitude: longitude) { result in
            switch result {
            case .success(let currentForecast, _):
                let summary = currentForecast.currently?.summary
                print("summary", summary as Any)
                DispatchQueue.main.async {
                    self.responseLabel.text = summary
                }
            case .failure(let error):
                print("error", error)
                DispatchQueue.main.async {
                    self.responseLabel.text = "Error with Weather API"
                }
            }
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

