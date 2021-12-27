//
//  responseViewController.swift
//  42Connect
//
//  Created by Marco FERNANDES on 2018/10/07.
//  Copyright © 2018 Kuzivakwashe MUVEZWA. All rights reserved.
//

import UIKit

class responseViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // get the number of reponses and return it here
        return Responses.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        //create the table and append the cells here
        let cell = tableView.dequeueReusableCell(withIdentifier: "response") as! responseTableViewCell
        cell.nameLabel.text = Responses[indexPath.row].user
        cell.dateLabel.text = Responses[indexPath.row].date
        cell.responseLabel.text = Responses[indexPath.row].content
        return cell
    }
    

    @IBOutlet weak var responseTable: UITableView!
    
    @IBAction func backButton(_ sender: Any) {
        self.dismiss(animated: false, completion: nil)
    }
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewWillAppear(_ animated: Bool) {
        responseTable.reloadData()
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
