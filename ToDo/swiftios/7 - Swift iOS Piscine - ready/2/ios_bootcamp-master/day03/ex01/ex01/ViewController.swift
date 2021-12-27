//
//  ViewController.swift
//  ex00
//
//  Created by Melissa NAIDOO on 2018/10/05.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate {

    @IBOutlet weak var myCollectionView: UICollectionView!
    
    let array : [String] = ["https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22724_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22484_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22768_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22766_hires.jpg",
        "https://www.nasa.gov/sites/default/files/styles/full_width_feature/public/thumbnails/image/iss056e096896_0.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/mediumsize/PIA18249_ip.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22689_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22482_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22766_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22766_hires.jpg",
        "https://www.jpl.nasa.gov/spaceimages/images/mediumsize/PIA18249_ip.jpg",
         "https://www.jpl.nasa.gov/spaceimages/images/largesize/PIA22689_hires.jpg"
        ]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let itemSize = UIScreen.main.bounds.width/2-2
        let layout = UICollectionViewFlowLayout()
        layout.sectionInset = UIEdgeInsetsMake(20, 0, 10, 0)
        layout.itemSize = CGSize(width: itemSize, height: itemSize)
        layout.minimumInteritemSpacing = 3
        layout.minimumLineSpacing = 3
        
        myCollectionView.collectionViewLayout = layout
        

    }

    
    //number of views
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return array.count
    }
    
    //populate views
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath) as! myCell
        if let url = URL(string: array[indexPath.row]){
            
            cell.spinner(shouldSpin: true)
            URLSession.shared.dataTask(with: url) { (data, response, error) in

                if (error != nil)
                {
                    print (error!)
                    return
                }
                DispatchQueue.main.async {
                    cell.myImageView.image = UIImage(data: data!)
                    cell.spinner(shouldSpin: false)
                    
                }
               
            
        }.resume()
        }
        return cell


}

}

