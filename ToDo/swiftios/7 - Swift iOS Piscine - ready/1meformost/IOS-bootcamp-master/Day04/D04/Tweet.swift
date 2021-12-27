//
//  Tweet.swift
//  D04
//
//  Created by Marco on 2018/10/05.
//  Copyright © 2018 Marco. All rights reserved.
//

import Foundation

struct Tweet : CustomStringConvertible
{
    var description: String
    {
        return "\(name) \(text) \(date)"
    }
    
    let name : String
    let text : String
    let date : String
    
}
