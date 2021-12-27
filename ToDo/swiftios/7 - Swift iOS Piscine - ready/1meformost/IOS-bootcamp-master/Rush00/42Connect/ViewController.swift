//
//  ViewController.swift
//  42Connect
//
//  Created by Marco FERNANDES on 2018/10/06.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

var code: String = "code"
let apiCall = ApiController();


class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad();
        apiCall.getAccessToken();
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning();
        // Dispose of any resources that can be recreated.
    }

    @IBAction func loginButtonClick(_ sender: UIButton) {
        
    }
    
    @IBAction func browseButton(_ sender: Any) {
        let HomeViewPage:HomeViewController = self.storyboard?.instantiateViewController(withIdentifier: "Home") as! HomeViewController;
        apiCall.getTopics()
        self.present(HomeViewPage, animated: true, completion: nil)        
    }
}

