//
//  TwitterProtocol.swift
//  D04
//
//  Created by Marco FERNANDES on 2018/10/05.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import Foundation

protocol APITwitterDelegate : class
{
    func Tweets(tweet: Tweet)
    func TwitterError(error: NSError)
}
