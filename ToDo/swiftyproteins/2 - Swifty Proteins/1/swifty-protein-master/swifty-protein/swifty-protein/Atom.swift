//
//  Atom.swift
//  swifty-protein
//
//  Created by Antoine JOUANNAIS on 6/8/17.
//  Copyright © 2017 Antoine JOUANNAIS. All rights reserved.
//

import Foundation
import UIKit

// cette classe stocke les donnees d'un atome à partir d'une chaine de caractere lue dans un fichier pdb
class Atom : NSObject {
    /*
     Record Format
     
     COLUMNS        DATA  TYPE    FIELD        DEFINITION
     -------------------------------------------------------------------------------------
     1 -  6        Record name   "ATOM  "
     7 - 11        Integer       serial       Atom  serial number.
     13 - 16        Atom          name         Atom name.
     17             Character     altLoc       Alternate location indicator.
     18 - 20        Residue name  resName      Residue name.
     22             Character     chainID      Chain identifier.
     23 - 26        Integer       resSeq       Residue sequence number.
     27             AChar         iCode        Code for insertion of residues.
     31 - 38        Real(8.3)     x            Orthogonal coordinates for X in Angstroms.
     39 - 46        Real(8.3)     y            Orthogonal coordinates for Y in Angstroms.
     47 - 54        Real(8.3)     z            Orthogonal coordinates for Z in Angstroms.
     55 - 60        Real(6.2)     occupancy    Occupancy.
     61 - 66        Real(6.2)     tempFactor   Temperature  factor.
     77 - 78        LString(2)    element      Element symbol, right-justified.
     79 - 80        LString(2)    charge       Charge  on the atom.
     */
    var serial : Int
    var name : String
    var chainID : Character
    var x : Float
    var y : Float
    var z : Float
    var element : String
    var color : UIColor
    
    var linkedAtoms : [Int] = []
    init(record : String) {
        // on recupere un "record" complet et on le transforme en objet
        print("init : record = \(record)")
        self.serial = Int(record.substring(from: 6, to: 10).trimmingCharacters(in: .whitespaces))!
        self.name = record.substring(from: 12, to: 15)
        self.chainID = record[21]
        self.x = Float(record.substring(from: 30, to: 37).trimmingCharacters(in: .whitespaces))!
        self.y = Float(record.substring(from: 38, to: 45).trimmingCharacters(in: .whitespaces))!
        self.z = Float(record.substring(from: 46, to: 53).trimmingCharacters(in: .whitespaces))!
        self.element = record.substring(from: 76, to: 77)
        // couleurs definies ici : https://en.wikipedia.org/wiki/CPK_coloring
        switch element {
        case " H":
            color = UIColor.white
        case " C":
            color = UIColor.black
        case " N":
            color = UIColor(red: 0, green: 0, blue: 0xFF, alpha:1) // dark blue
        case " O":
            color = UIColor.red
        case " F", "Cl":
            color = UIColor.green
        case "Br":
            color = UIColor(red: 0x99, green: 0, blue: 0, alpha:1) // dark red
        case " I":
            color = UIColor(red: 0x33, green: 0x00, blue: 0x99, alpha:1) // dark violet
        case "He", "Ne","Ar","Xe", "Kr":
            color = UIColor.cyan
        case " P":
            color = UIColor.orange
        case " S":
            color = UIColor.yellow
        case " B":
            color = UIColor(red: 0xFF, green: 0x99, blue: 0x66, alpha:1) // peach
        case "Li", "Na"," K", "Rb", "Cs", "Fr":
            color = UIColor.purple
        case "Be", "Mg", "Ca", "Sr", "Ba", "Ra":
            color = UIColor(red: 0x00, green: 0x66, blue: 0x00, alpha:1) // dark green
        case "Ti":
            color = UIColor.gray
        case "Fe":
            color = UIColor(red: 0xFF, green: 0x66, blue: 0x00, alpha:1) // dark orange
        default:
            color = UIColor(red: 0xFF, green: 0x33, blue: 0xFF, alpha:1) // pink
        }
    }
    
    func addLink(_ atomSerial : Int) {
        self.linkedAtoms.append(atomSerial)
    }
    
    override var description : String {
        var str = "serial: \(serial), name: \(name), x: \(x), y: \(y), z: \(z), element: \(element), links: "
        for link in self.linkedAtoms {
            str += "\(link) "
        }
        return str
    }
}
