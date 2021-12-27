//
//  Article+CoreDataProperties.swift
//  
//
//  Created by Marco FERNANDES on 2018/10/12.
//
//

import Foundation
import CoreData


extension Article {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Article> {
        return NSFetchRequest<Article>(entityName: "Article")
    }

    @NSManaged public var content: String?
    @NSManaged public var creationDate: NSDate?
    @NSManaged public var image: NSData?
    @NSManaged public var language: String?
    @NSManaged public var modificationDate: NSObject?
    @NSManaged public var title: String?
    
   
}
