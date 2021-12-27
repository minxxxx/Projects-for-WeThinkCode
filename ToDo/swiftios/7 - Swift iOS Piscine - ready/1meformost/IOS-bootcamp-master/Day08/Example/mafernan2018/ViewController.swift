//
//  ViewController.swift
//  mafernan2018
//
//  Created by Moondog360 on 10/12/2018.
//  Copyright (c) 2018 Moondog360. All rights reserved.
//

import UIKit
import mafernan2018

@available(iOS 10.0, *)
class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        print("View did load from controller")
        let articleManager = ArticleManager()
        
        print("creating first article")
        let article1 = articleManager.newArticle()
        article1.title = "Article 1"
        article1.content = "some content goes here"
        article1.creationDate = Date()
        article1.modificationDate = Date()
        article1.language = "fr"
        articleManager.save()
        
        print("creating second article")
        let article2 = articleManager.newArticle()
        article2.title = "Article 2"
        article2.content = "some more content goes here"
        article2.creationDate = Date()
        article2.modificationDate = Date()
        article2.language = "en"
        articleManager.save()
        
        print(articleManager.getAllArticles())
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

