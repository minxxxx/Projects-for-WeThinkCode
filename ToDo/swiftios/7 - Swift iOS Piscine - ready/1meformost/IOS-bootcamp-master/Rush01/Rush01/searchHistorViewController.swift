//
//  searchHistorViewController.swift
//  Rush01
//
//  Created by Marco FERNANDES on 2018/10/13.
//  Copyright © 2018 Thato MEKWA. All rights reserved.
//

import UIKit
import MapKit

struct searchResults {
    var title: String?
    var subtitle: String?
    var coordinate: CLLocationCoordinate2D?
}

var pickedLocation: searchResults?
var departureLocation: searchResults?
var changeScreen = false
var fromUser = true
var createRoute = false

class searchHistorViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate {
    
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var destinationText: UITextField!
    @IBOutlet weak var departureText: UITextField!
    
    // store results
    var mapSearchResults: [searchResults] = []
    var reloadTimer: Any?
    
    // counter to execute func every nth time
  
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // return search history results
        return mapSearchResults.count
    }
    
    // run this every second
    @objc func reloadTableResults() {
        tableView.reloadData()
        if (changeScreen == true) {
            print("Change screen")
            self.navigationController?.popViewController(animated: true)
        }
    }
    
    // load table cells with search results
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // return cell
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "historyCell") as! historyTableViewCell
        cell.subtitleLable.text = mapSearchResults[indexPath.row].subtitle
        cell.titleLabel.text = mapSearchResults[indexPath.row].title
        return cell
    }
    

    override func viewDidLoad() {
        super.viewDidLoad()
        // run this every seconds
        reloadTimer = Timer.scheduledTimer(timeInterval: 1.0, target: self, selector: #selector(self.reloadTableResults), userInfo: nil, repeats: true)
        
        self.destinationText.delegate = self
        // Do any additional setup after loading the view.

    }

    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // find destination results and append to table
    func textFieldShouldReturn(_ textField:UITextField) -> Bool {
        print("Enter pressed!")
        // clear search results first
        mapSearchResults.removeAll()
        print("\(String(describing: textField.text))")
        destinationText.resignFirstResponder()
        //Ignoring user
        

        UIApplication.shared.beginIgnoringInteractionEvents()

        //Activity idicator
        let activityIndicator = UIActivityIndicatorView()

        activityIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.gray
        activityIndicator.center = self.view.center
        activityIndicator.hidesWhenStopped = true
        activityIndicator.startAnimating()

        //Create the search request

        let request = MKLocalSearchRequest()
        request.naturalLanguageQuery = destinationText.text
        let activeSearch = MKLocalSearch(request: request)
        
        activeSearch.start { (response, error) in
            
            activityIndicator.stopAnimating()
            UIApplication.shared.endIgnoringInteractionEvents()
            if response == nil
            {
                print("No results found")
            } else
            {
                print("Found matching results")
                for res in (response?.mapItems)! {
                    let a = searchResults.init(title: res.placemark.name, subtitle: res.placemark.title, coordinate: res.placemark.coordinate)
                    self.mapSearchResults.append(a)
                }
            }
        }
        return true
    }
    
    func findDeparture(string: String) {
        print("Finding departure")
        UIApplication.shared.beginIgnoringInteractionEvents()
        
        //Activity idicator
        let activityIndicator = UIActivityIndicatorView()
        
        activityIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.gray
        activityIndicator.center = self.view.center
        activityIndicator.hidesWhenStopped = true
        activityIndicator.startAnimating()
        
        //Create the search request
        
        let request = MKLocalSearchRequest()
        request.naturalLanguageQuery = string
        let activeSearch = MKLocalSearch(request: request)
        
        activeSearch.start { (response, error) in
            
            activityIndicator.stopAnimating()
            UIApplication.shared.endIgnoringInteractionEvents()
            if response == nil
            {
                print("No results found")
            } else
            {
                print("Found matching results")
                for res in (response?.mapItems)! {
                    departureLocation = searchResults.init(title: res.placemark.name, subtitle: res.placemark.title, coordinate: res.placemark.coordinate)
                    changeScreen = true
                    break
                }
            }
        }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if (departureText.text == "") {
            print("From user location")
            pickedLocation = mapSearchResults[indexPath.row]
            createRoute = true
            changeScreen = true
        } else {
            print("From departure location")
            fromUser = false
            pickedLocation = mapSearchResults[indexPath.row]
            findDeparture(string: departureText.text!)
            createRoute = true
        }
    }
}
