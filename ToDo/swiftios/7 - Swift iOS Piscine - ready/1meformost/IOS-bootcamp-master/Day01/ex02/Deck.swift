import AppKit

class Deck : NSObject {
    static let allSpades = Value.allValues.map{Card(color: Color.spades, value: $0)}
    static let allDiamonds = Value.allValues.map{Card(color: Color.diamonds, value: $0)}
    static let allHearts = Value.allValues.map{Card(color: Color.hearts, value: $0)}
    static let allClubs = Value.allValues.map{Card(color: Color.clubs, value: $0)}
    
    static let allCards = [allSpades.map{$0}, allDiamonds.map{$0}, allHearts.map{$0}, allClubs.map{$0}]
}
