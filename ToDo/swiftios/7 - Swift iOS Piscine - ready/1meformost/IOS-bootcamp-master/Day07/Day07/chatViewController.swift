//
//  chatViewController.swift
//  Day07
//
//  Created by Marco FERNANDES on 2018/10/10.
//  Copyright © 2018 Marco FERNANDES. All rights reserved.
//

import UIKit
import MessageKit

// to make it easy to send the type when doing a conversation request
struct Senders {
    var you: Sender;
    var bot: Sender;
    
    init(you: Sender, bot: Sender) {
        self.you = you;
        self.bot = bot
    }
}

class chatViewController: MessagesViewController,MessageCellDelegate, WeatherBotDelegate {
    
    // store all the messages here to give to MessageKit
    var messageList: [ChatMessage] = []
    // This will allow us to refresh our view every so often when needed
    let refreshControl = UIRefreshControl();
    
    // store the last weather bot response here
    var lastBotAnswer: String?;
    // we need to access the weather bot from here
    var weatherBot: WeatherBot!;

    var senders = Senders(
        // give yourself and the bot a unique name and ID number(can be any)
        you: Sender(id: "1", displayName: "You"),
        bot: Sender(id: "2", displayName: "WeatherBot2000")
    );
    
    // Store the response text here
    var responseText: String? {
        get {
            return (lastBotAnswer);
        }
        set {
            self.handleTextMessage(text: newValue!, sender: senders.bot);
            self.lastBotAnswer = newValue;
            self.messagesCollectionView.scrollToBottom();
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // setup the data source and delegate layouts
        messagesCollectionView.messagesDataSource = self
        messagesCollectionView.messagesLayoutDelegate = self
        messagesCollectionView.messagesDisplayDelegate = self
        messagesCollectionView.messageCellDelegate = self
        messageInputBar.delegate = self
        // instantiate the weather bot to work
        weatherBot = WeatherBot(delegate: self)
        // refresh the view
        messagesCollectionView.addSubview(refreshControl);
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

// This is needed to setup the table view data of what it will do on the go
extension chatViewController: MessagesDataSource {
    
    // how many messages when reload is called
    func numberOfSections(in messagesCollectionView: MessagesCollectionView) -> Int {
        return messageList.count
    }
    
    // set sender ID to you from the Senders struct
    func currentSender() -> Sender {
        return self.senders.you
    }
    
    // update "Table" to number of messages
    func numberOfMessages(in messagesCollectionView: MessagesCollectionView) -> Int {
        return messageList.count
    }
    
    // add messages to "Table"
    func messageForItem(at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> MessageType {
        return messageList[indexPath.section]
    }
    
    // Add top label to "TableCell" of the message
    func cellTopLabelAttributedText(for message: MessageType, at indexPath: IndexPath) -> NSAttributedString? {
        let name = message.sender.displayName
        return NSAttributedString(string: name, attributes: [NSAttributedStringKey.font: UIFont.preferredFont(forTextStyle: .caption1)])
    }
    
    // Append the message to the bottom of the message Cell along with the date!
    func cellBottomLabelAttributedText(for message: MessageType, at indexPath: IndexPath) -> NSAttributedString? {
        
        // convert to proper date format
        struct ConversationDateFormatter {
            static let formatter: DateFormatter = {
                let formatter = DateFormatter()
                formatter.dateStyle = .medium
                return formatter
            }()
        }
        let formatter = ConversationDateFormatter.formatter
        let dateString = formatter.string(from: message.sentDate)
        // return the message format "Cell" for bottom of the cell
        return NSAttributedString(string: dateString, attributes: [NSAttributedStringKey.font: UIFont.preferredFont(forTextStyle: .caption2)])
    }
    
}

// We need to setup what the message bubbles will look like here. Otherwise it will complain when it tries to display a message
extension chatViewController: MessagesDisplayDelegate, MessagesLayoutDelegate {
    func heightForLocation(message: MessageType, at indexPath: IndexPath, with maxWidth: CGFloat, in messagesCollectionView: MessagesCollectionView) -> CGFloat {
        return (200);
    }


    // change color of text depending if it's from send or bot
    func textColor(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> UIColor {
        return isFromCurrentSender(message: message) ? .white : .darkText
    }

    // change detector attribute
    func detectorAttributes(for detector: DetectorType, and message: MessageType, at indexPath: IndexPath) -> [NSAttributedStringKey : Any] {
        return MessageLabel.defaultAttributes
    }

    // enable the detector attribute
    func enabledDetectors(for message: MessageType, at indexPath: IndexPath, in messagesCollectionView: MessagesCollectionView) -> [DetectorType] {
        return [.url, .address, .phoneNumber, .date]
    }


}

// Here we handle what happens to the inputbar
extension chatViewController: MessageInputBarDelegate {
    
    // We pass the message here to create a "MessageBubble" layout that we append out message to
    func handleTextMessage(text: String, sender: Sender) {
        let attributedText = NSAttributedString(string: text, attributes: [.font: UIFont.systemFont(ofSize: 15), .foregroundColor: UIColor.blue])
        let message = ChatMessage(attributedText: attributedText, sender: sender, messageId: UUID().uuidString, date: Date())
        print("What do we do with this message now!")
        messageList.append(message)
        messagesCollectionView.insertSections([messageList.count - 1])
    }
    
    // What happens to the textBar.text when send is pressed
    // we extract the message from inputTextView and send it to the function above to display user's message
    // we then send that text to the bot who will handle the request and then append it to message bubble
    func messageInputBar(_ inputBar: MessageInputBar, didPressSendButtonWith text: String) {
        for component in inputBar.inputTextView.components {
            if let res = component as? String {
                print("Message1: \(res)")
                handleTextMessage(text: res, sender: senders.you);
                weatherBot.handleRequest(request: res)
            }
        }
        inputBar.inputTextView.text = String();
        messagesCollectionView.scrollToBottom();
    }
}
