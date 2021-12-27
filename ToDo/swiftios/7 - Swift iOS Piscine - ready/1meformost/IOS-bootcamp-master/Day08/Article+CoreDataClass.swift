//
//  Article+CoreDataClass.swift
//  
//
//  Created by Marco FERNANDES on 2018/10/12.
//
//

import Foundation
import CoreData

@objc(Article)
public class Article: NSManagedObject {
    override var description {
        return "Title: \(self.title)\nLanguage: \(self.language)"
    }
}
