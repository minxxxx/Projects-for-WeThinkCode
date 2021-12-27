//
//  messageViewController.swift
//  42Connect
//
//  Created by Marco FERNANDES on 2018/10/07.
//  Copyright © 2018 Kuzivakwashe MUVEZWA. All rights reserved.
//

import UIKit

class messageViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // get the number of messages in topic
        return Messages.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // create message cell and return it
        let cell = tableView.dequeueReusableCell(withIdentifier: "messageCell") as! messageTableViewCell
        cell.nameLabel.text = Messages[indexPath.row].user
        cell.dateLabel.text = Messages[indexPath.row].date
        cell.messageLabel.text = Messages[indexPath.row].content
        return cell
    }
    
    @IBAction func backButton(_ sender: Any) {
        self.dismiss(animated: false, completion: nil)
    }
    
    @IBOutlet weak var messageTable: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        Responses.removeAll()
        apiCall.getReponses(topicID: currentTopic!, messageID: Messages[indexPath.row].id)
        let responseTable:responseViewController = self.storyboard?.instantiateViewController(withIdentifier: "responseView") as! responseViewController
        self.present(responseTable, animated: true, completion: nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        messageTable.reloadData()
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
