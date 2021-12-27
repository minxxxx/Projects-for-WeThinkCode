//
//  WebViewController.swift
//  42Connect
//
//  Created by Marco FERNANDES on 2018/10/06.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit
import WebKit

class WebViewController: UIViewController, WKNavigationDelegate{

    
    @IBOutlet weak var authWebView: WKWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad();
        // Do any additional setup after loading the view, typically from a nib.
        let url = URL(string: "https://api.intra.42.fr/oauth/authorize?client_id=cf646bd3b744848776ae359d4c513e8bfb367acd7df45298c90af04f6f0c8171&redirect_uri=http%3A%2F%2Fsignin.intra.42.fr%2F&response_type=code");
        let request = URLRequest(url: url!);
        authWebView.load(request);
        authWebView.navigationDelegate = self;
    }

    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        
        print("no link")
        var link: String = (authWebView.url?.absoluteString)!;
        print("Link : \(link)")
        if (link.contains("http://signin.intra.42.fr/"))
        {
            print("link \((authWebView.url?.absoluteString)!)")
            let str  = (authWebView.url?.absoluteString)!;
            let array = str.components(separatedBy: "=");
            code = array[array.count - 1];
            print("my code is \(code)");
            let HomeViewPage:HomeViewController = self.storyboard?.instantiateViewController(withIdentifier: "Home") as! HomeViewController;
            self.present(HomeViewPage, animated: true, completion: nil)
        }
        link = "";
        decisionHandler(WKNavigationActionPolicy.allow)
    }

}
