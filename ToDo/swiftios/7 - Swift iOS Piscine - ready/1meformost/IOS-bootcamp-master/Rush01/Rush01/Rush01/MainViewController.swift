//
//  MainViewController.swift
//  Rush01
//
//  Created by Thato MEKWA on 2018/10/13.
//  Copyright © 2018 Thato MEKWA. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class MainViewController: UIViewController, CLLocationManagerDelegate, UISearchBarDelegate {
    
    
    @IBOutlet weak var mapView: MKMapView!
    
    var previousLocation: CLLocation?
    let span = MKCoordinateSpanMake(0.002, 0.002)
    
    let manager = CLLocationManager()
    var directionsArray: [MKDirections] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("View is loaded")
        
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestWhenInUseAuthorization()
        manager.startUpdatingLocation()
        
        NotificationCenter.default.addObserver(self, selector: #selector(showNavigation), name: NSNotification.Name("showNavigation"), object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(showSignIn), name: NSNotification.Name("showSignIn"), object: nil)
        
        self.mapView.delegate = self
        checkLocationAuthoriztion()
    }
    
    func checkLocationAuthoriztion() {
        switch CLLocationManager.authorizationStatus() {
        case .authorizedWhenInUse:
            startTrackingUserLocation()
        case .denied:
            //show alert
            break
        case .notDetermined:
            manager.requestWhenInUseAuthorization()
        case .restricted:
            //show alert
            break
        case .authorizedAlways:
            break
            
        }
    }
    
    func startTrackingUserLocation() {
        mapView.showsUserLocation = true
        centerViewOnUser()
        manager.startUpdatingLocation()
        previousLocation = getCentreLocation(for: mapView)
    }
    
    func centerViewOnUser() {
        if let location = manager.location?.coordinate {
            let region = MKCoordinateRegion.init(center: location, span: span)
            mapView.setRegion(region, animated: true)
        }
    }
    
    @IBAction func mapType(_ sender: Any) {
        switch (sender as AnyObject).selectedSegmentIndex {
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
    
    @IBAction func findMeButton(_ sender: Any) {
        mapView.removeOverlays(mapView.overlays)
        if mapView.annotations.count > 0 {
            let annotations = self.mapView.annotations
            self.mapView.removeAnnotations(annotations)
        }
        startTrackingUserLocation()
    }
    
    @objc func showNavigation()
    {
        performSegue(withIdentifier: "showNavigation", sender: nil)
    }
    
    @objc func showSignIn()
    {
        performSegue(withIdentifier: "showSignIn", sender: nil)
    }
    
    @IBAction func hamburgerButton(_ sender: Any) {
        print("Toggle pressed")
        NotificationCenter.default.post(name: NSNotification.Name("ToggleSideMenu"), object: nil)
    }
    
    @IBAction func directionButton(_ sender: Any) {
        print("Directions")
    }


    @IBAction func searchButton(_ sender: Any) {

        print("Search")
        let searchController = UISearchController(searchResultsController: nil)
        searchController.searchBar.delegate = self
        present(searchController, animated: true, completion: nil)
    }
    
    // what todo when view will appear
    override func viewWillAppear(_ animated: Bool) {
        changeScreen = false
        //Remove annotations
        if (createRoute == true) {
            createRoute = false
            mapView.showsUserLocation = false
            if mapView.annotations.count > 0 {
                let annotations = self.mapView.annotations
                self.mapView.removeAnnotations(annotations)
            }
            if (fromUser == true) {
                // create route from user
                createRouteFromUser()
            } else {
                // create route from depature
                createRouteFromDep()
            }
        }
    }
    
    func createRouteFromDep() {
        // add anotations
        // create the route
        // zoom out to view route points
        
        //create annotations
        let annotation1 = MKPointAnnotation()
        annotation1.title = pickedLocation?.title
        annotation1.subtitle = pickedLocation?.subtitle
        annotation1.coordinate = CLLocationCoordinate2DMake((pickedLocation?.coordinate?.latitude)!, (pickedLocation?.coordinate?.longitude)!)
        self.mapView.addAnnotation(annotation1)
        
        let annotation2 = MKPointAnnotation()
        annotation2.title = departureLocation?.title
        annotation2.subtitle = departureLocation?.subtitle
        annotation2.coordinate = CLLocationCoordinate2DMake((departureLocation?.coordinate?.latitude)!, (departureLocation?.coordinate?.longitude)!)
        self.mapView.addAnnotation(annotation2)
        
        //self.Map.delegate = self
        let request = createDirectionRequest(from: CLLocationCoordinate2DMake((pickedLocation?.coordinate?.latitude)!, (pickedLocation?.coordinate?.longitude)!))
        let direction = MKDirections(request: request)
        resetMapView(withnew: direction)
        
        direction.calculate{ [unowned self] (response, error) in
            
            if let error = error {
                print("some error \(error)")
            }
            guard let response = response else {return} //show response not available in alert
            for route in response.routes {
                self.mapView.add(route.polyline)
                self.mapView.setVisibleMapRect(route.polyline.boundingMapRect, animated: true)
            }
        }
        
    }
    
    func createRouteFromUser() {
        // add anotations
        // create the route
        // zoom out to view route points
        
        //user location
        guard let location = manager.location?.coordinate else {
            print("dont have their location")
            //inform user we dont have their location
            return
        }
        //create annotations
        let annotation = MKPointAnnotation()
        annotation.title = "My Location"
        annotation.subtitle = "This is where we find you!"
        annotation.coordinate = CLLocationCoordinate2DMake(location.latitude, location.longitude)
        self.mapView.addAnnotation(annotation)
        
        //self.Map.delegate = self
        let request = createDirectionRequestUser(from: location)
        let direction = MKDirections(request: request)
        resetMapView(withnew: direction)
        
        direction.calculate{ [unowned self] (response, error) in
            
            if let error = error {
                print("some error \(error)")
            }
            guard let response = response else {return} //show response not available in alert
            for route in response.routes {
                // .
                
//                route.steps to say turn left then right etc
                self.mapView.add(route.polyline)
                self.mapView.setVisibleMapRect(route.polyline.boundingMapRect, animated: true)
            }
        }
        
        
    }
    
    
    // search for place
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        
        //Ignoring user
        UIApplication.shared.beginIgnoringInteractionEvents()
        mapView.showsUserLocation = false
        mapView.removeOverlays(mapView.overlays)
        
        //Activity idicator
        let activityIndicator = UIActivityIndicatorView()
        
        activityIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.gray
        activityIndicator.center = self.view.center
        activityIndicator.hidesWhenStopped = true
        activityIndicator.startAnimating()
        
        //Hide searchg Bar
        searchBar.resignFirstResponder()
        dismiss(animated: true, completion: nil)
        
        //Create the search requet
        let searchedLocation = MKLocalSearchRequest()
        searchedLocation.naturalLanguageQuery = searchBar.text
        
        let activeSearch = MKLocalSearch(request: searchedLocation)
        
        activeSearch.start { (response, error) in
            
            activityIndicator.stopAnimating()
            UIApplication.shared.endIgnoringInteractionEvents()
            if response == nil
            {
                print("Error being processed")
            }else
            {
                //Remove annotations
                let annotations = self.mapView.annotations
                self.mapView.removeAnnotations(annotations)
                
                //Getting data
                let latitude = response?.boundingRegion.center.latitude
                let longitude = response?.boundingRegion.center.longitude
                
                //create annotations
                let annotation = MKPointAnnotation()
                annotation.title = searchBar.text
                annotation.coordinate = CLLocationCoordinate2DMake(latitude!, longitude!)
                self.mapView.addAnnotation(annotation)
                
                
                //Zooming in on annotation
                let coordinate:CLLocationCoordinate2D = CLLocationCoordinate2DMake(latitude!, longitude!)
                let span = MKCoordinateSpanMake(0.01, 0.01)
                let region = MKCoordinateRegionMake(coordinate, span)
                self.mapView.setRegion(region, animated: true)
            }
        }
    }
    
    func getCentreLocation(for map: MKMapView) -> CLLocation {
        let latitude = map.centerCoordinate.latitude
        let longitude = map.centerCoordinate.longitude
        
        return CLLocation(latitude: latitude, longitude: longitude)
    }
    
    func createDirectionRequestUser(from coordinate: CLLocationCoordinate2D) -> MKDirectionsRequest {
        //let destinationCoordinate       = getCentreLocation(for: mapView).coordinate
        let startingLocation            = MKPlacemark(coordinate: coordinate)
        let destination                 = MKPlacemark(coordinate: CLLocationCoordinate2DMake((pickedLocation?.coordinate?.latitude)!, (pickedLocation?.coordinate?.longitude)!))
        
        let request                     = MKDirectionsRequest()
        request.source                  = MKMapItem(placemark: startingLocation)
        request.destination             = MKMapItem(placemark: destination)
        request.transportType           = .automobile //change to segement control to change transport methods
        request.requestsAlternateRoutes = true
        
        return request
    }
    
    func createDirectionRequest(from coordinate: CLLocationCoordinate2D) -> MKDirectionsRequest {
        //let destinationCoordinate       = getCentreLocation(for: mapView).coordinate
        let startingLocation            = MKPlacemark(coordinate: CLLocationCoordinate2DMake((departureLocation?.coordinate?.latitude)!, (departureLocation?.coordinate?.longitude)!))
        let destination                 = MKPlacemark(coordinate: CLLocationCoordinate2DMake((pickedLocation?.coordinate?.latitude)!, (pickedLocation?.coordinate?.longitude)!))
        
        let request                     = MKDirectionsRequest()
        request.source                  = MKMapItem(placemark: startingLocation)
        request.destination             = MKMapItem(placemark: destination)
        request.transportType           = .automobile //change to segement control to change transport methods
        request.requestsAlternateRoutes = true

        return request
    }
    
    func resetMapView(withnew directions: MKDirections) {
        var i = 0
        mapView.removeOverlays(mapView.overlays)
        directionsArray.append(directions)
        let cancel = directionsArray.map { $0.cancel() }
        while i < cancel.count {
            directionsArray.remove(at: i )
            i += 1
        }
        
    }
    
}

// the extensions
extension MainViewController: MKMapViewDelegate {
    public func mapView(_ mapView: MKMapView, regionDidChangeAnimated animated: Bool) {
        let centre = getCentreLocation(for: mapView)
        let geoCoder = CLGeocoder()
        
        guard let previouslocation = self.previousLocation else {return}
        
        guard centre.distance(from: previouslocation) > 30 else {return} //mabye change the 50
        self.previousLocation = centre
        
        geoCoder.cancelGeocode()
        
        geoCoder.reverseGeocodeLocation(centre) { [weak self] (placemarks, error) in
            guard case self = self else {return}
            
            if let error = error {
                //Alert.showBasicAlert(on: self!, with: "Error", message: error as! String)
                //display an alert
                print("Error over here: \(error)")
                return
            }
        }
    }
    public func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        let annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: "pin")
        annotationView.pinTintColor = UIColor.magenta
        if annotation.title! != "My Location" {
            annotationView.pinTintColor = UIColor.green
        }
        annotationView.canShowCallout = true
        return annotationView
    }
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        let renderer = MKPolylineRenderer(overlay: overlay as! MKPolyline)
        renderer.strokeColor = .blue
        
        return renderer
    }
}



