//
//  ViewController.swift
//  Navigator
//
//  Created by Melissa NAIDOO on 2018/10/12.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation
import MapboxDirections
import MapboxCoreNavigation
import MapboxNavigation

class ViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate, UISearchBarDelegate{

    //VARS WE'LL NEED
    var locationManager : CLLocationManager!
    var usersRegion : MKCoordinateRegion!
    @IBOutlet weak var destination: UITextField!
    @IBOutlet weak var departure: UITextField!
    @IBOutlet weak var MAP: MKMapView!

    @IBOutlet weak var changeText: UIButton!
    var DepartureLat: Double!
    var DepartureLng: Double!
    var DestinationLat: Double!
    var DestinationLng: Double!
    var currentRoute: MKRoute!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        //get users location using CL location manager
        locationManager = CLLocationManager()
        self.locationManager.requestWhenInUseAuthorization()
        if CLLocationManager.locationServicesEnabled() {
            locationManager.delegate = self
            locationManager.desiredAccuracy = kCLLocationAccuracyBest
            locationManager.startUpdatingLocation()
        }
        MAP.delegate = self
    }
    
    
    @IBAction func searchBar(_ sender: Any) {
        let searchContrl = UISearchController(searchResultsController: nil)
        searchContrl.searchBar.delegate = self
        present(searchContrl, animated: true, completion: nil)
    }
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        //ignoring user
        UIApplication.shared.beginIgnoringInteractionEvents()
        
        //hide search bar
        searchBar.resignFirstResponder()
        dismiss(animated: true, completion: nil)
        
        self.searchLocation(depOrDest: searchBar.text!)
        UIApplication.shared.endIgnoringInteractionEvents()
    }
    
    @IBAction func Navigate(_ sender: Any) {
        if (self.DepartureLat != nil && self.DepartureLng != nil && self.DestinationLat != nil && self.DestinationLng != nil)
        {
            let origin = Waypoint(coordinate: CLLocationCoordinate2D(latitude: self.DepartureLat, longitude: self.DepartureLng), name: self.departure.text)
            let destination = Waypoint(coordinate: CLLocationCoordinate2D(latitude: self.DestinationLat, longitude: self.DestinationLng), name: self.destination.text)
            
            let options = NavigationRouteOptions(waypoints: [origin, destination])
            
            Directions.shared.calculate(options) { (waypoints, routes, error) in
                guard let route = routes?.first else { return }
                
                let viewController = NavigationViewController(for: route)
                self.present(viewController, animated: true, completion: nil)
            }
        }
        else
        {
            creatAlert(title: "Error", message: "Please enter a location for departure and destination")
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let location = locations[0]
        
        let span:MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01)
        let myLoc:CLLocationCoordinate2D = CLLocationCoordinate2DMake(location.coordinate.latitude, location.coordinate.longitude)
        let region:MKCoordinateRegion = MKCoordinateRegion(center: myLoc, span: span)
        self.usersRegion = region
    }
    
    //set region to users location and show the location when "My Location" button is clicked
    @IBAction func ShowUsersLocation(_ sender: Any) {
        self.MAP.removeAnnotations(self.MAP.annotations)
        self.MAP.setRegion(self.usersRegion, animated: true)
        self.MAP.showsUserLocation = true
    }
    
    @IBAction func showRoute(_ sender: Any) {
        //removing annotations
        changeText.setTitle("Show Route", for: .normal)
        let annotations = self.MAP.annotations
        self.MAP.removeAnnotations(annotations)
        self.MAP.removeOverlays(self.MAP.overlays)
        
        searchLocation(depOrDest: "dep")
        searchLocation(depOrDest: "des")
        
        print("first \(self.DepartureLat)")
        print("first \(self.DepartureLng)")
        print("================")
        print(self.DestinationLat)
        print(self.DestinationLng)
        //create a route and draw the pin
        if (self.DepartureLat != nil  && self.DepartureLng != nil && self.DestinationLat != nil && self.DestinationLng != nil)
        {
            
            let departureCoordinates = CLLocationCoordinate2DMake(self.DepartureLat, self.DepartureLng)
            let destinationCoordinates = CLLocationCoordinate2DMake(self.DestinationLat, self.DestinationLng)

            let departurePlacemark = MKPlacemark(coordinate: departureCoordinates)
            let destinationPlacemark = MKPlacemark(coordinate: destinationCoordinates)

            let departureItem = MKMapItem(placemark: departurePlacemark)
            let destinationItem = MKMapItem(placemark: destinationPlacemark)

            let directionRequest = MKDirectionsRequest()
            directionRequest.source = departureItem
            directionRequest.destination = destinationItem
            directionRequest.transportType = .automobile

            let directions = MKDirections(request: directionRequest)
            directions.calculate(completionHandler: {
                response, error in

                guard let resp = response else {
                    if let err = error {
                        print(err.localizedDescription)
                    }
                    return
                }

                let route = resp.routes[0]
                self.MAP.add(route.polyline, level: .aboveRoads)

                let rekt = route.polyline.boundingMapRect
                self.MAP.setRegion(MKCoordinateRegionForMapRect(rekt), animated: true)

                self.changeText.setTitle("Get Location", for: .normal)
            })
        }
        else if (destination.text == "" && departure.text == "")
        {
            creatAlert(title: "Cannot Find Location", message: "Please enter a location for the departure and destination")
            self.changeText.setTitle("Get Location", for: .normal)
        }
    }
    
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        let renderer = MKPolylineRenderer(overlay: overlay)
        renderer.strokeColor = UIColor.black
        renderer.lineWidth = 3.0
        
        return renderer
    }
    
    func searchLocation(depOrDest: String) {
        //removing users location
        self.MAP.showsUserLocation = false
        
        //Create Departure Search Request
        let searchRequestOne = MKLocalSearchRequest()
        if (depOrDest == "dep")
        {
            searchRequestOne.naturalLanguageQuery = self.departure.text
        }
        else if (depOrDest == "des")
        {
            searchRequestOne.naturalLanguageQuery = self.destination.text
        }
        else
        {
            searchRequestOne.naturalLanguageQuery = depOrDest
        }
        
        let activateSearch = MKLocalSearch(request: searchRequestOne)
        
        activateSearch.start { (response, error) in
            if response == nil
            {
                self.creatAlert(title: "Cannot Find Location", message: "Please enter locations")
            }
            else
            {
                if (depOrDest == "dep")
                {
                    //Getting data
                    self.DepartureLat = Double((response?.boundingRegion.center.latitude)!)
                    self.DepartureLng = Double((response?.boundingRegion.center.longitude)!)
                    
                    print(self.DepartureLat)
                    print(self.DepartureLng)
                    //Create annotation
                    let annotation = MKPointAnnotation()
                    annotation.title = self.departure.text
                    annotation.coordinate = CLLocationCoordinate2DMake(self.DepartureLat, self.DepartureLng)
                    self.MAP.addAnnotation(annotation)
                }
                else if (depOrDest == "des")
                {
                    //Getting data
                    self.DestinationLat = Double((response?.boundingRegion.center.latitude)!)
                    self.DestinationLng = Double((response?.boundingRegion.center.longitude)!)
                    
                    print(self.DestinationLat)
                    print(self.DestinationLng)
                   // Create annotation
                    let annotation = MKPointAnnotation()
                    annotation.title = self.destination.text
                    annotation.coordinate = CLLocationCoordinate2DMake(self.DestinationLat, self.DestinationLng)
                    self.MAP.addAnnotation(annotation)
                }
                else
                {
                    //remove annotations
                    self.MAP.removeAnnotations(self.MAP.annotations)
                    
                    let tempLAT = Double((response?.boundingRegion.center.latitude)!)
                    let tempLNG  = Double((response?.boundingRegion.center.longitude)!)
                    // Create annotation
                    let annotation = MKPointAnnotation()
                    annotation.title = depOrDest
                    annotation.coordinate = CLLocationCoordinate2DMake(tempLAT, tempLNG)
                    self.MAP.addAnnotation(annotation)
                    
                    let span = MKCoordinateSpanMake(0.0002, 0.0002)
                    let region = MKCoordinateRegion(center: annotation.coordinate, span: span)
                    self.MAP.setRegion(region, animated: true)
                }
            }
        }
    }
    @IBAction func changeMapView(_ sender: UISegmentedControl)
    {
        if sender.selectedSegmentIndex == 0{
            MAP.mapType = MKMapType.standard
        }
        else if sender.selectedSegmentIndex == 1{
            MAP.mapType = MKMapType.satellite
        }
        else if sender.selectedSegmentIndex == 2{
            MAP.mapType = MKMapType.hybrid
        }
    }
    
    func creatAlert(title:String, message:String)
    {
        let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: { (action) in
            alert.dismiss(animated: true, completion: nil)
        }))
        
        self.present(alert, animated: true, completion: nil)
    }
    
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
