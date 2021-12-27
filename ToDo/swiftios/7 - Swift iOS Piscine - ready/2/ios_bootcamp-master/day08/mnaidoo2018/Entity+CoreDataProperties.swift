//
//  Entity+CoreDataProperties.swift
//  
//
//  Created by Melissa NAIDOO on 2018/10/12.
//
//

import Foundation
import CoreData


extension Entity {/goinfre/mnaidoo/Desktop/mnaidoo2018/Example/article.xcdatamodeld

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Entity> {
        return NSFetchRequest<Entity>(entityName: "Entity")
    }

    @NSManaged public var title: String?
    @NSManaged public var content: String?
    @NSManaged public var language: String?
    @NSManaged public var image: NSData?
    @NSManaged public var creationDate: NSDate?
    @NSManaged public var modificationDate: NSDate?

    override public var description: String {
        return "Title : \(title)\ncontent : \(content)\nLanguage : \(language)\nDate of creation : \(creationDate)"
        
    }
}
