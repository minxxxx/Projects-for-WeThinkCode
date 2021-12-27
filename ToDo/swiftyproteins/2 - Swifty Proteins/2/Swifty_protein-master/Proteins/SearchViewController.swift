//
//  SearchViewController.swift
//  Proteins
//
//  Created by Marco FERNANDES on 2018/10/17.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit

var selectedProtien: String?

class SearchViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate {
    
    @IBOutlet weak var infoTable: UITableView!
    @IBOutlet weak var searchBar: UISearchBar!
    var FilterData: [String]!
    var reloadTimer: Any?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        infoTable.dataSource = self
        searchBar.delegate = self
        FilterData = protiens
    }

    override func viewWillAppear(_ animated: Bool) {
        reloadTimer = Timer.scheduledTimer(timeInterval: 0.1, target: self, selector: #selector(self.checkBackground), userInfo: nil, repeats: true)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    @IBAction func goBack(_ sender: Any) {
        self.dismiss(animated: false, completion: nil)
    }
    
    // run this every second
    @objc func checkBackground() {
        let state = UIApplication.shared.applicationState
        if state == .background {
            self.view.window?.rootViewController?.dismiss(animated: false, completion: nil)
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return FilterData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "protienCell") as! LigandsTableViewCell
        cell.protienLabel.text = FilterData[indexPath.row]
        return cell
    }
    
    func bestMatchFilterdStringArray(inputArray: [String], searchTerm: String) -> [String] {
        let matchingTerms = inputArray
            .filter { $0.range(of: searchTerm, options: .caseInsensitive) != nil }
            .sorted { ($0.hasPrefix(searchTerm) ? 0 : 1) < ($1.hasPrefix(searchTerm) ? 0 : 1) }
        return matchingTerms
    }
    
    // This method updates filteredData based on the text in the Search Box
    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        // When there is no text, filteredData is the same as the original data
        // When user has entered text into the search box
        // Use the filter method to iterate over all items in the data array
        // For each item, return true if the item should be included and false if the
        // item should NOT be included
        FilterData = searchText.isEmpty ? protiens : protiens.filter { (item: String) -> Bool in
            // If dataItem matches the searchText, return true to include it
            return item.range(of: searchText, options: .caseInsensitive, range: nil, locale: nil) != nil
        }
        infoTable.reloadData()
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        selectedProtien = FilterData[indexPath.row]
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
        let protienView = self.storyboard?.instantiateViewController(withIdentifier: "DisplayView") as! ViewController
        self.present(protienView, animated: false, completion: nil)
    }
}
