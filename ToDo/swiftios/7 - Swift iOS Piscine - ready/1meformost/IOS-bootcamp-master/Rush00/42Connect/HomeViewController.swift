//
//  HomeViewController.swift
//  42Connect
//
//  Created by Marco FERNANDES on 2018/10/06.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit

var currentTopic : Int?

class HomeViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // get number of topics
        return Topics.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // create topic cell and return it to table
        let cell = tableView.dequeueReusableCell(withIdentifier: "topicCell") as! topicTableViewCell
        cell.authourLabel.text = Topics[indexPath.row].user
        cell.topicLabel.text = Topics[indexPath.row].name
        cell.dateLabel.text = Topics[indexPath.row].date
        cell.id = Topics[indexPath.row].id
        return cell
    }
    

    @IBOutlet weak var topicTable: UITableView!
    
    @IBAction func logoutButton(_ sender: Any) {
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
        Topics.removeAll()
        apiCall.getTopics()
        topicTable.reloadData()
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(false)
        self.navigationController?.popViewController(animated: false)
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        //Topics[indexPath.row].id
        Messages.removeAll()
        currentTopic = Topics[indexPath.row].id
        apiCall.getMessages(id: Topics[indexPath.row].id)
        let messageTable:messageViewController = self.storyboard?.instantiateViewController(withIdentifier: "messageView") as! messageViewController
        self.present(messageTable, animated: true, completion: nil)        
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
