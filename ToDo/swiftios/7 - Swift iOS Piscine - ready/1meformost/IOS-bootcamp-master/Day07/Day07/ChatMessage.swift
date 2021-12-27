//
//  ChatMessage.swift
//  Day07
//
//  Created by Marco FERNANDES on 2018/10/10.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

//import Foundation
//import MessageKit
//import CoreLocation
//
//struct ChatMessage: MessageType {
//
//    var kind: MessageKind
//    var messageId: String
//    var sender: Sender
//    var sentDate: Date
//
//    init(kind: MessageKind, sender: Sender, messageId: String, date: Date) {
//        self.kind = kind
//        self.sender = sender
//        self.messageId = messageId
//        self.sentDate = date
//    }
//
//    init(attributedText: NSAttributedString, sender: Sender, messageId: String, date: Date) {
//        self.init(kind: .attributedText(attributedText), sender: sender, messageId: messageId, date: date)
//    }
//}

import Foundation
import MessageKit
import CoreLocation

struct ChatMessage: MessageType {
    
    var messageId: String
    var sender: Sender
    var sentDate: Date
    var data: MessageData
    
    init(data: MessageData, sender: Sender, messageId: String, date: Date) {
        self.data = data
        self.sender = sender
        self.messageId = messageId
        self.sentDate = date
    }
    
    init(attributedText: NSAttributedString, sender: Sender, messageId: String, date: Date) {
        self.init(data: .attributedText(attributedText), sender: sender, messageId: messageId, date: date)
    }
}
