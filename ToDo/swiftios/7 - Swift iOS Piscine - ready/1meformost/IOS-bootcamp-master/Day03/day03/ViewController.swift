//
//  ViewController.swift
//  day03
//
//  Created by Marco FERNANDES on 2018/10/04.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

let imageCache = NSCache<NSString, UIImage>()

var alert = false

var count = 0
var urlCount = 0
extension UIImageView {
    
    func imageFromServerURL(_ URLString: String) {
        
        let activity: UIActivityIndicatorView = UIActivityIndicatorView()
        self.image = nil
        activity.center = self.center
        activity.hidesWhenStopped = true
        activity.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.gray
        addSubview(activity)
        activity.startAnimating()
        
        if let cachedImage = imageCache.object(forKey: NSString(string: URLString)) {
            activity.stopAnimating()
            self.image = cachedImage
            return
        }
        
        if let url = URL(string: URLString) {
            UIApplication.shared.isNetworkActivityIndicatorVisible = true
            URLSession.shared.dataTask(with: url, completionHandler: { (data, response, error) in
                
                //print("RESPONSE FROM API: \(response)")
                if error != nil {
                    DispatchQueue.main.async {
                        activity.stopAnimating()
                    }
                    alert = true
                    // print("ERROR LOADING IMAGES FROM URL: \(String(describing: error))") = false
                    return
                }
                DispatchQueue.main.async {
                    if let data = data {
                        if let downloadedImage = UIImage(data: data) {
                            imageCache.setObject(downloadedImage, forKey: NSString(string: URLString))
                            self.image = downloadedImage
                            activity.stopAnimating()
                            count += 1
                            if (count >= urlCount) {
                                UIApplication.shared.isNetworkActivityIndicatorVisible = false
                            }
                        }
                    }
                }
            }).resume()
        }
        
    }
}

class ViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {
    
    @IBOutlet weak var myCollectionView: UICollectionView!
    
    let url:[String]! = ["https://www.nasa.gov/sites/default/files/thumbnails/image/45025340661_7b9f8f9402_k.jpg", "https://www.nasa.gov/sites/default/files/thumbnails/image/43010056595_3fc589b92d_k.jpg", "https://www.nasa.gov/sites/default/files/thumbnails/image/9458072623_5c6cf2fa3f_o.jpg", "https://www.nasa.gov/sites/default/files/thumbnails/image/s68-46603.jpg"]
    
    
    // amount of cells needed based on imageArray
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        urlCount = url.count
        return url.count
    }
    
    func sendAlertMessage(message: String)
    {
        let alert = UIAlertController(title: "ERROR LOADING IMAGE", message: "From Url " +  message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        
        self.present(alert, animated: true, completion: nil)
    }
    
    // populate the cells with the images
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "imageCell", for: indexPath) as! imageCollectionViewCell
        
        cell.imageView.imageFromServerURL(url[indexPath.row])
        
        if alert == true {
            sendAlertMessage(message: url[indexPath.row])
            alert = false
        }
        return cell
    }
    
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let myImageViewPage:MyImageViewController = self.storyboard?.instantiateViewController(withIdentifier: "imageViewController") as! MyImageViewController
        
        if let selectedImage = collectionView.cellForItem(at: indexPath) {
            let myCell = selectedImage as! imageCollectionViewCell
            if (myCell.imageView.image != nil) {
                myImageViewPage.self.image = myCell.imageView.image
                self.navigationController?.pushViewController(myImageViewPage, animated: true)
            } else {
                print ("No image found to open when tapped!")
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        let itemSize = UIScreen.main.bounds.width
        
        let layout = UICollectionViewFlowLayout()
        layout.sectionInset = UIEdgeInsetsMake(20, 0, 10, 0)
        layout.itemSize = CGSize(width: itemSize, height: itemSize)
        
        layout.minimumInteritemSpacing = 3
        layout.minimumLineSpacing = 10
        
        myCollectionView.collectionViewLayout = layout
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}
