//
//  UserData.swift
//  swiftyComp
//
//  Created by Melissa NAIDOO on 2018/10/17.
//  Copyright © 2018 Melissa NAIDOO. All rights reserved.
//

import Foundation


struct Users: Decodable {
    let first_name : String
    let last_name :String
    let login :String
    let email:String
    let image_url: String
    let correction_point:Int
    let wallet:Int
    let cursus_users : [Cursus_users]
    let projects_users: [Project_users]
}

struct Cursus_users: Decodable {
    let level : Double
    let skills: [Skills]
}

struct Skills: Decodable{
    let level : Double
    let name :String
}

struct Project_users: Decodable {
    let final_mark: Int?
    let project: Project
    let validated :Bool?
    
    enum CodingKeys : String, CodingKey{
        case final_mark
        case project
        case validated = "validated?"
    }
 
}
struct Project: Decodable {
    let slug: String?
}
