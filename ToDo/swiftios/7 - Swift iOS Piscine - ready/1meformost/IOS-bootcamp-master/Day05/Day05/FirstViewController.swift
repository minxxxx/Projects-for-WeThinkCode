//
//  FirstViewController.swift
//  Day05
//
//  Created by Marco FERNANDES on 2018/10/08.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

var pins:[MyPinClass] = []
var pickedLocation: MKPointAnnotation?
var selected = false

class MyPinClass : MKPointAnnotation {
    var pinColor: UIColor?
}

class FirstViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {

    @IBOutlet weak var mapView: MKMapView!
    
    var locationManager = CLLocationManager()
    
    @IBAction func changeView(_ sender: UISegmentedControl) {
        switch sender.selectedSegmentIndex {
        case 0:
            mapView.mapType = .standard
            break
        case 1:
            mapView.mapType = .satellite
            break
        case 2:
            mapView.mapType = .hybrid
            break
        default:
            mapView.mapType = .standard
            break
        }
    }
    
    @IBAction func findMe(_ sender: Any) {
        if CLLocationManager.authorizationStatus() == .authorizedWhenInUse {
            // set zoom here
            let span = MKCoordinateSpanMake(0.005, 0.005)
            let location = CLLocationCoordinate2DMake(mapView.userLocation.coordinate.latitude, mapView.userLocation.coordinate.longitude)
            let region = MKCoordinateRegionMake(location, span)
            mapView.setRegion(region, animated: false)
            // center map
            mapView.setCenter(mapView.userLocation.coordinate, animated: true)
            // show user icon
            mapView.showsUserLocation = true;
        } else {
            mapView.showsUserLocation = false
            locationManager.requestAlwaysAuthorization()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.

        // background use
        locationManager.requestAlwaysAuthorization()
        // foreground use
        locationManager.requestWhenInUseAuthorization()
        
        // set location settings
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.distanceFilter = 10
        locationManager.startUpdatingLocation()
        
        // set map settings
        mapView.delegate = self
        mapView.mapType = .standard
        mapView.isZoomEnabled = true
        mapView.isScrollEnabled = true
        
        // Create three default pins for the table
        createPin(name: "42 school", sub: "42 School in france", longitude: 2.318489, latitude: 48.896618, color: .orange)
        createPin(name: "WeThinkCode_", sub: "Software engineering school", longitude:28.040191 , latitude: -26.204611, color: .blue)
        createPin(name: "RMB", sub: "Rand Merchant Bank Santon", longitude:28.057986 , latitude:-26.099751, color: .green)
        centerMapOnLocation(location: (pins.first?.coordinate)!)
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // center map!
    let regionRadius: CLLocationDistance = 1000
    func centerMapOnLocation(location: CLLocationCoordinate2D) {
        let coordinateRegion = MKCoordinateRegionMakeWithDistance(location,
                                                                  regionRadius, regionRadius)
        mapView.setRegion(coordinateRegion, animated: true)
    }
    
    // create annotations and append to array(pins) which table view will access
    func createPin(name: String, sub: String, longitude: Double, latitude: Double, color: UIColor) {
        let annotation = MyPinClass()
        annotation.coordinate = CLLocationCoordinate2D(latitude: latitude, longitude:longitude)
        annotation.title = name
        annotation.subtitle = sub
        mapView.addAnnotation(annotation)
        annotation.pinColor = color
        pins.append(annotation)
    }
    
    // update location
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        print("Updated!")

    }
    
    // update to location picked!
    override func viewWillAppear(_ animated: Bool) {
        if (selected == true) {
            // set zoom here
            let span = MKCoordinateSpanMake(0.005, 0.005)
            let location = CLLocationCoordinate2DMake(mapView.userLocation.coordinate.latitude, mapView.userLocation.coordinate.longitude)
            let region = MKCoordinateRegionMake(location, span)
            mapView.setRegion(region, animated: false)
            // center map on location picked
            print("going to load picked location!")
            centerMapOnLocation(location: (pickedLocation?.coordinate)!)
            selected = false
        }
    }
    
    // changes pin color when map loads
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        let annotationView = MKMarkerAnnotationView()
        guard let annotation = annotation as? MyPinClass else {return nil}
        annotationView.markerTintColor = annotation.pinColor
        annotationView.clusteringIdentifier = annotation.title
        return annotationView
    }
}
