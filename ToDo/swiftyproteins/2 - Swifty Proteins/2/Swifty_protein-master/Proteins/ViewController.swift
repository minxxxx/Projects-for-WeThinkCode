 //
//  ViewController.swift
//  Proteins
//
//  Created by Leslie DE JAGER on 2018/10/17.
//  Copyright © 2018 Leslie DE JAGER. All rights reserved.
//

import UIKit
import SceneKit
import Photos
 
struct Atoms{
    var index: Int
    var x: Float
    var y: Float
    var z: Float
    var name : String
    var connectedTo: [Int]
}

 
 


class ViewController: UIViewController {

    @IBOutlet weak var label: UILabel!
    @IBOutlet weak var gameView: SCNView!
    var gameScene:SCNScene!
    var atoms:[Atoms] = []
    var reloadTimer: Any?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        initView()
        initScene()
        label.layer.masksToBounds = true
        label.layer.cornerRadius = 5
        //createScene(ligand: selectedProtien!)
        reloadTimer = Timer.scheduledTimer(timeInterval: 0.1, target: self, selector: #selector(self.checkBackground), userInfo: nil, repeats: true)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        createScene(ligand: selectedProtien!)
    }
    
    @IBAction func shareButton(_ sender: Any) {
        
        let photos = PHPhotoLibrary.authorizationStatus()
        if photos == .notDetermined {
            PHPhotoLibrary.requestAuthorization({status in
                if status == .authorized{
                    self.sendAlertMessage(message: "you can now press share again!")
                } else {
                    self.sendAlertMessage(message: "Not authorized to save photos please check settings permissions")
                }
            })
        } else if photos == .authorized {
            let image = self.gameView.snapshot()
            let shareView = UIActivityViewController(activityItems: [image], applicationActivities: nil)
            present(shareView, animated: true, completion: nil)
        }
        
        
    }
    
    @objc func checkBackground() {
        let state = UIApplication.shared.applicationState
        if state == .background {
            self.view.window?.rootViewController?.dismiss(animated: false, completion: nil)
        }
    }
    
    @IBAction func goBack(_ sender: Any) {
        self.dismiss(animated: false, completion: nil)
    }
    
    func initView(){
        gameView.allowsCameraControl = true;
        gameView.autoenablesDefaultLighting = true;
    }
    
    func createAtom(x: Float, y :Float, z :Float, color :UIColor, name: String)
    {
        let atom:SCNGeometry = SCNSphere(radius: 0.5);
        atom.materials.first?.diffuse.contents = color;
        
        let atomNode = SCNNode(geometry: atom);
        atomNode.position = SCNVector3(x:x, y:y, z:z);
        atomNode.name = name
        
        gameScene.rootNode.addChildNode(atomNode);
        
    }
    
    func createConnection(v1: SCNVector3, v2 :SCNVector3)
    {
        let connection:SCNNode = CylinderLine(parent: gameScene.rootNode, v1: v1, v2: v2, radius: 0.1, radSegmentCount: 10, color: .gray)
        gameScene.rootNode.addChildNode(connection)
    }
    
    func initScene()
    {
        gameScene = SCNScene();
        gameView.scene = gameScene;
        gameView.isPlaying = true;
        let cameraNode = SCNNode()
        cameraNode.camera = SCNCamera()
        cameraNode.position = SCNVector3(x: 0, y: 0, z: 30)
        gameScene.rootNode.addChildNode(cameraNode)
    }
    
    func extractData(urlContent : NSString)
    {
        DispatchQueue.main.async {
            UIApplication.shared.isNetworkActivityIndicatorVisible = false
            var sentenceLines:[String] = []
            let string = urlContent as String
            string.enumerateLines { (line, _) in
                sentenceLines.append(line)
            }
            
            self.generateScene(lines: sentenceLines)
            self.generateModels()
        }
    }
    
    func getColor(name : String) -> UIColor
    {
        if name == "H"
        {
            return UIColor.white
        }
        else if name == "C"
        {
            return UIColor.lightGray
        }
        else if name == "N"
        {
            return UIColor.init(red: (143 / 225), green: (143 / 255), blue: 1, alpha: 1)
        }
        else if name == "O"
        {
            return UIColor.red
        }
        else if name == "Cl" || name == "F"
        {
            return UIColor.green
        }
        else if name == "P" || name == "Fe"
        {
            return UIColor.orange
        }
        else if name == "S"
        {
            return UIColor.yellow
        }
        else if name == "Br" || name == "Zn"
        {
            return UIColor.brown
        }
        else if name == "Na"
        {
            return UIColor.blue
        }
        else if name == "Mg"
        {
            return UIColor.init(red: (42/255), green: 0.5, blue: (42 / 255), alpha: 1)
        }
        else if name == "Ca"
        {
            return UIColor.init(red: 0.5, green: 0.5, blue: 0.5, alpha: 1)
        }
        return UIColor.init(red: 1, green: (20 / 255), blue: 0.5, alpha: 1)
    }
    
    func generateModels()
    {
        for atom in self.atoms
        {
            createAtom(x: atom.x, y: atom.y, z: atom.z, color: getColor(name: atom.name), name: atom.name)
            if atom.connectedTo.count > 0
            {
                for ind in atom.connectedTo
                {
                    let v1 = SCNVector3(x: atom.x, y: atom.y, z: atom.z)
                    let temp = self.atoms[ind - 1] as Atoms
                    let v2 = SCNVector3(x: temp.x, y: temp.y, z: temp.z)
                    createConnection(v1: v1, v2: v2)
                }
            }
        }
    }
    
    func generateScene(lines: [String])
    {
        self.atoms.removeAll()
        for line in lines
        {
            if line.range(of: "ATOM") != nil
            {
                let words = line.split(separator: " ")
                let index = Int(String(words[1]))
                let x = Float(String(words[6]))
                let y = Float(String(words[7]))
                let z = Float(String(words[8]))
                let temp =  Atoms(index: index!, x: x!, y: y!, z: z!, name: String(words[11]), connectedTo: [])
                self.atoms.append(temp)
            }
            else if line.range(of: "CONECT") != nil
            {
                let words = line.split(separator: " ")
                let index = Int(String(words[1]))
                var i = 0
                for word in words
                {
                    if i >= 2
                    {
                        let temp = Int(String(word))
                        if index! < temp!
                        {
                            self.atoms[index! - 1].connectedTo.append(temp!)
                        }
                    }
                    i += 1
                }
            }
        }
    }
    
    func createScene(ligand : String)
    {
        let url = URL(string: "https://files.rcsb.org/ligands/view/\(ligand)_ideal.pdb")
        let request = NSMutableURLRequest(url: url!)
        
        
        let activity: UIActivityIndicatorView = UIActivityIndicatorView()
        activity.center = self.view.center
        activity.hidesWhenStopped = true
        activity.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.gray
        self.view.addSubview(activity)
        activity.startAnimating()
        let group = DispatchGroup();
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            let HttpResponse = response as? HTTPURLResponse
            if let err = error{
                print(err)
            }
            else if (HttpResponse?.statusCode)! >= 200 && (HttpResponse?.statusCode)! <= 299{
                self.extractData(urlContent: (NSString(data: data!, encoding: String.Encoding.ascii.rawValue) as NSString?)!)
            }
            else
            {
                self.sendAlertMessage(message: "Failed to download PDB file for \(ligand)")
            }
            DispatchQueue.main.async {
                activity.stopAnimating()
            }
            group.leave()
        }
        group.enter()
        task.resume()
        group.wait()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touch = touches.first!
        
        let location = touch.location(in: gameView)
        
        let hitList = gameView.hitTest(location, options: nil)
        
        if let object =  hitList.first
        {
            let node = object.node
            self.label.text = "  Type : \(node.name!)"
        }
    }
    
    func sendAlertMessage(message: String)
    {
        let alert = UIAlertController(title: "Alert", message:  message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
        
        self.present(alert, animated: true, completion: nil)
    }
}

