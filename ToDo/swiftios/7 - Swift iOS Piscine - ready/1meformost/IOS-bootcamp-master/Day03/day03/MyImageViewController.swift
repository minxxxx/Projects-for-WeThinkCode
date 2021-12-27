//
//  MyImageViewController.swift
//  day03
//
//  Created by Marco FERNANDES on 2018/10/04.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

class MyImageViewController: UIViewController, UIScrollViewDelegate {

    var image:UIImage? = nil
    var myImageView : UIImageView?
    
    @IBOutlet weak var scrollView: UIScrollView!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        myImageView = UIImageView(image: image)
        scrollView.addSubview(myImageView!)
        scrollView.contentSize = (myImageView?.frame.size)!
        
        scrollView.maximumZoomScale = 100
        scrollView.minimumZoomScale = 0.1
        
    }

    func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return myImageView
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
