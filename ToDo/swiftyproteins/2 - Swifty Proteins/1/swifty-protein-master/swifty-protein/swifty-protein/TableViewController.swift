//
//  TableViewController.swift
//  swifty-protein
//
//  Created by Antoine JOUANNAIS on 5/26/17.
//  Copyright © 2017 Antoine JOUANNAIS. All rights reserved.
//

import UIKit

class TableViewController: UITableViewController, UISearchResultsUpdating, UISearchBarDelegate {

    var ligands : [String] = []
    var filteredData:[String] = []
    var searchController:UISearchController = UISearchController(searchResultsController: nil)
    var shouldShowSearchResults = false
    
    func populateLigands() {
        
        do {
            // This solution assumes  you've got the file in your bundle
            if let path = Bundle.main.path(forResource: "ligands", ofType: "txt"){
                let data = try String(contentsOfFile:path, encoding: String.Encoding.utf8)
                ligands = data.components(separatedBy: "\n")
                print(ligands)
            }
        } catch let err as NSError {
            // do something with Error
            print(err)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
        populateLigands()
    
        searchController.searchResultsUpdater = self
        searchController.dimsBackgroundDuringPresentation = false
        definesPresentationContext = true // permet de ne pas afficher le champ de recherche si on change de vue
        searchController.searchBar.placeholder = NSLocalizedString("Search here...", comment:"search bar placeholder")
        searchController.searchBar.delegate = self
        searchController.searchBar.sizeToFit()
        tableView.tableHeaderView = searchController.searchBar
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if shouldShowSearchResults {
            return filteredData.count
        }
        else {
            return ligands.count
        }
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "ligandCellId", for: indexPath)

        // Configure the cell...

        if shouldShowSearchResults {
            cell.textLabel?.text = filteredData[indexPath.row]
        }
        else {
            cell.textLabel?.text = ligands[indexPath.row]
        }
        
        return cell
    }

       
    func searchBarTextDidBeginEditing(_ searchBar: UISearchBar) {
        shouldShowSearchResults = true
        tableView.reloadData()
    }
    
    func searchBarCancelButtonClicked(_ searchBar: UISearchBar) {
        shouldShowSearchResults = false
        tableView.reloadData()
    }
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        if !shouldShowSearchResults {
            shouldShowSearchResults = true
            tableView.reloadData()
        }
        
        searchController.searchBar.resignFirstResponder()
    }

    func updateSearchResults(for: UISearchController) {
        let searchString = searchController.searchBar.text
        
        // Filter the data array and get only those strings that match the search text.
        filteredData = ligands.filter({ (lig) -> Bool in
            let ligText: String = lig
            
            return (ligText.lowercased().range(of: searchString!.lowercased()) != nil)
        })
        
        // Reload the tableview.
        tableView.reloadData()
    }
    


    
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        print("prepare for segue")
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
        if let cell = sender as? UITableViewCell, let gameViewController = segue.destination as? GameViewController {
            // zoomedPhotoViewController.photoName = galleryItems[indexPath.row].itemImage
            gameViewController.ligand = (cell.textLabel?.text!)!
        }
    }
    

}
