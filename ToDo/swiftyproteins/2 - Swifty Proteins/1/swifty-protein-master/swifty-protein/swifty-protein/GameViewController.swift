//
//  GameViewController.swift
//  swifty-protein
//
//  Created by Antoine JOUANNAIS on 5/26/17.
//  Copyright © 2017 Antoine JOUANNAIS. All rights reserved.
//

import UIKit
import SceneKit
import Foundation



class GameViewController: UIViewController, UIGestureRecognizerDelegate {
    @IBOutlet weak var scnView: SCNView!
    var scnScene: SCNScene!
    var cameraNode: SCNNode!
    var ligand: String = ""
    var atoms : [Int: Atom] = [:]
    @IBAction func share(_ sender: UIBarButtonItem) {
        userDidTapShare()
    }
    
    @IBOutlet weak var msg: UILabel! // pour afficher le nom du ligand ou de l'atome
    
    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldRecognizeSimultaneouslyWith otherGestureRecognizer: UIGestureRecognizer) -> Bool {
        return true
    }
 
    func userDidTapShare()
    {
        //Set the default sharing message.
        let message = NSLocalizedString("Hello! This is a beautifull 3D view of ligand ", comment: "Message for picture") + ligand
        let link = NSURL(string: "http://www.42.fr//")
        // Screenshot:
        UIGraphicsBeginImageContextWithOptions(self.view.frame.size, true, 0.0)
        self.view.drawHierarchy(in: self.view.frame, afterScreenUpdates: false)
        let img = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        
        //Set the link, message, image to share.
        if let link = link, let img = img {
            let objectsToShare = [message,link,img] as [Any]
            let activityVC = UIActivityViewController(activityItems: objectsToShare, applicationActivities: nil)
            activityVC.excludedActivityTypes = [UIActivityType.airDrop, UIActivityType.addToReadingList]
            self.present(activityVC, animated: true, completion: nil)
        }
    }
    
    func addLinks(conect:String) {
        /*
         The CONECT records specify connectivity between atoms for which coordinates are supplied.
         The connectivity is described using the atom serial number as shown in the entry. 
         CONECT records are mandatory for HET groups (excluding water) and for other bonds not specified in the standard residue connectivity table. 
         These records are generated automatically.
         
         Record Format
         
         COLUMNS       DATA  TYPE      FIELD        DEFINITION
         -------------------------------------------------------------------------
         1 -  6        Record name    "CONECT"
         7 - 11       Integer        serial       Atom  serial number
         12 - 16        Integer        serial       Serial number of bonded atom
         17 - 21        Integer        serial       Serial  number of bonded atom
         22 - 26        Integer        serial       Serial number of bonded atom
         27 - 31        Integer        serial       Serial number of bonded atom
         */
        let atomSerial = Int(conect.substring(from: 6, to: 10).trimmingCharacters(in: .whitespaces))!
        let firstBondedAtom = Int(conect.substring(from: 11, to: 15).trimmingCharacters(in: .whitespaces))!
        if let atom = atoms[atomSerial] {
            atom.addLink(firstBondedAtom)
            if let secondBondedAtom = Int(conect.substring(from: 16, to: 20).trimmingCharacters(in: .whitespaces)) {
                atoms[atomSerial]?.addLink(secondBondedAtom)
            }
            if let thirdBondedAtom = Int(conect.substring(from: 21, to: 25).trimmingCharacters(in: .whitespaces)) {
                atom.addLink(thirdBondedAtom)
            }
            if let fourthBondedAtom = Int(conect.substring(from: 26, to: 30).trimmingCharacters(in: .whitespaces)) {
                atom.addLink(fourthBondedAtom)
            }
        }
        else {
            print("Bizarre, j'ai trouvé un lien pour un atom inconnu... Il est donc ignoré")
        }
    }

    // initialisation de la reconnaissance d'un clic sur un objet graphique pour afficher son nom
    func initTapGestures() {
        let tapRecognizer = UITapGestureRecognizer()
        tapRecognizer.numberOfTapsRequired = 1
        tapRecognizer.numberOfTouchesRequired = 1
        tapRecognizer.addTarget(self, action: #selector(sceneTapped(recognizer:)))
        
        var gestureRecognizers = [tapRecognizer as UIGestureRecognizer]
        if let arr = scnView.gestureRecognizers { // il existe deja des gestes
            gestureRecognizers = arr + gestureRecognizers // je mets mon geste en dernier (sinon il n'est pa reconnu)
        }
        scnView.gestureRecognizers = gestureRecognizers
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        msg.text = "Ligand : " + ligand + NSLocalizedString(", please click on atom for description", comment: "Instructions")
        setupView()
        setupScene()
        getLigandFile()
        initTapGestures()
        
        // ajout d'un bouton share par programme
        /*
        let shareBar: UIBarButtonItem = UIBarButtonItem.init(barButtonSystemItem:.action, target: self, action: #selector(GameViewController.userDidTapShare))
        self.navigationItem.rightBarButtonItem = shareBar
 */
       }
   
    func sceneTapped(recognizer: UITapGestureRecognizer) {
        let location = recognizer.location(in: scnView)
        print("sceneTapped : location = \(location)")
        let hitResults = scnView.hitTest(location, options: nil)
        if hitResults.count > 0 {
            let result = hitResults[0] 
            let node = result.node
            if let name = node.name {
                msg.text = NSLocalizedString("Atom: ", comment:"Atom") + name
                return
            }
        }
        msg.text = NSLocalizedString("Click on an atom to display its name", comment:"Message when click is not on an atom")
    }
    
    func processLigandFile(_ data : String) {
        print(data)
        let records : [String] = data.components(separatedBy: "\n")
        // je recupere tous les records de type ATOM
        var searchString = "ATOM"
        let atomRecords = records.filter({ (record) -> Bool in
            let recordText: String = record
            return (recordText.range(of: searchString) != nil)
        })
        
        // on remet la liste a zero
        self.atoms = [:]
        // on charge la liste des atomes
        for atom in atomRecords {
            print("atom : \(atom)")
            let index = Int(atom.substring(from: 6, to: 10).trimmingCharacters(in: .whitespaces))!
            self.atoms[index] = Atom(record: atom)
        }
        // je recupere tous les records de type CONECT
        searchString = "CONECT"
        let conectRecords = records.filter({ (record) -> Bool in
            let recordText: String = record
            return (recordText.range(of: searchString) != nil)
        })
        for conect in conectRecords {
            print("conect : \(conect)")
            self.addLinks(conect: conect)
        }
        
        // debug
        for atom in self.atoms {
            print(atom)
        }
    }
   
    func getLigandFile() {
        print("getLigang \(self.ligand)")
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
        
        let urlString = "https://files.rcsb.org/ligands/view/\(self.ligand)_model.pdb"
        guard let requestUrl = URL(string:urlString) else {
            print("url is incorrect : \(urlString)")
            return
        }
        let request = URLRequest(url:requestUrl)
        let task = URLSession.shared.dataTask(with: request) {
            (data, response, error) in
            UIApplication.shared.isNetworkActivityIndicatorVisible = false
            if let err = error {
                // DispatchQueue.main.async
                let errMsg = NSLocalizedString("Network error", comment: "An error message")
                print("\(errMsg) : \(err)")
                let alert = UIAlertController(title: "Error", message: errMsg, preferredStyle: .alert)
                let alertAction = UIAlertAction(title: "Ok", style: .destructive, handler: nil)
                alert.addAction(alertAction)
                
                self.present(alert, animated: true, completion: nil)
            }
            else if let usableData = data {
                let returnData = String(data: usableData, encoding: .utf8)
                if let resp = response as? HTTPURLResponse {
                    print("Status code de la reponse : \(resp.statusCode)")
                }
                self.processLigandFile(returnData!)
                self.displayLigands()
            }
        }
        task.resume()
    }
    
    // je veux garder la status bar pour pouvoir afficher la roue d'activité réseau
    override var shouldAutorotate: Bool {
        return true
    }
    
    override var prefersStatusBarHidden: Bool {
        return false
    }
    
    func setupView() {
        // scnView = self.view as! SCNView
        scnView.showsStatistics = true
        scnView.allowsCameraControl = true
        scnView.autoenablesDefaultLighting = true
    }

    func setupScene() {
        scnScene = SCNScene()
        scnView.scene = scnScene
    }
    
    func setupCamera(_ position : SCNVector3) {
        cameraNode = SCNNode()
        cameraNode.camera = SCNCamera()
        cameraNode.position = position
        scnScene.rootNode.addChildNode(cameraNode)

    }
    
    func displayLigands() {
        print("displayLigands")
        var cameraOn = false

        // dessiner les differents atoms
        for (_, atom) in self.atoms {
            if cameraOn == false {
                cameraOn = true
                let camPos = SCNVector3(atom.x, atom.y, 15 + atom.z)
                setupCamera(camPos)
            }
            drawAtom(atom)
        }
    }
    
    func drawAtom(_ atom : Atom) {
        let sphere = SCNSphere(radius: CGFloat(0.35))
        sphere.materials.first?.diffuse.contents = atom.color
        let sphereNode = SCNNode(geometry: sphere)
        sphereNode.name = atom.element // le nom de l'atome est stocke ici
        scnScene.rootNode.addChildNode(sphereNode)
        sphereNode.position = SCNVector3(atom.x, atom.y, atom.z)
        for linked in atom.linkedAtoms {
            if let b = self.atoms[linked] {
                let stick = CylinderLine(
                    parent: scnScene.rootNode,
                    v1: SCNVector3(atom.x, atom.y, atom.z),
                    v2:SCNVector3(b.x, b.y, b.z),
                    radius: 0.1,
                    radSegmentCount: 10,
                    color:UIColor.white)
                stick.name = NSLocalizedString("link", comment: "Name of link")
                scnScene.rootNode.addChildNode(stick)
            }
        }
    }
}

// extension pour se simplifier la lecture d'une sous-chaine
extension String {
    
    subscript (i: Int) -> Character {
        return self[index(startIndex, offsetBy: i)]
    }
    
    subscript (i: Int) -> String {
        return String(self[i] as Character)
    }
    
    func substring(from: Int?, to: Int?) -> String {
        if let start = from {
            guard start < self.characters.count else {
                return ""
            }
        }
        
        if let end = to {
            guard end >= 0 else {
                return ""
            }
        }
        
        if let start = from, let end = to {
            guard end - start >= 0 else {
                return ""
            }
        }
        
        let startIndex: String.Index
        if let start = from, start >= 0 {
            startIndex = self.index(self.startIndex, offsetBy: start)
        } else {
            startIndex = self.startIndex
        }
        
        let endIndex: String.Index
        if let end = to, end >= 0, end < self.characters.count {
            endIndex = self.index(self.startIndex, offsetBy: end + 1)
        } else {
            endIndex = self.endIndex
        }
        
        return self[startIndex ..< endIndex]
    }
}
