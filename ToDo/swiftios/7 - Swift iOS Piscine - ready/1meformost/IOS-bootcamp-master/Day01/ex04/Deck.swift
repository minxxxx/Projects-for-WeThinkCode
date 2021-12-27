import AppKit

class Deck : NSObject {
    static let allSpades = Value.allValues.map{Card(color: Color.spades, value: $0)}
    static let allDiamonds = Value.allValues.map{Card(color: Color.diamonds, value: $0)}
    static let allHearts = Value.allValues.map{Card(color: Color.hearts, value: $0)}
    static let allClubs = Value.allValues.map{Card(color: Color.clubs, value: $0)}
    
    static let allCards = allHearts.map{$0} + allDiamonds.map{$0} + allSpades.map{$0} + allClubs.map{$0}
    
    var cards = [Card]()
    var discards = [Card]()
    var outs = [Card]()

    init (shuffleDeck: Bool) {
        if (shuffleDeck == true) {
            cards = Deck.allCards
            cards.shuffle()
        } else {
            cards = Deck.allCards
        }
    }
    
    override var description: String {
        return "\(cards)"
    }
    
    func draw() -> Card? {
        let card = cards[0]
        outs.append(card)
        cards.removeFirst(1)
        return (card)
    }

	func fold(c: Card) {
		if let foundCard = outs.index(of: c) {
			outs.remove(at: foundCard)
			discards.append(c)
		}
	}
    
}

extension Array {
    mutating func shuffle() {
        let c = count
        guard c > 1 else { return }

        for (firstUnshuffled , unshuffledCount) in zip(indices, stride(from: c, to: 1, by: -1)) {
            let d: Int = numericCast(arc4random_uniform(numericCast(unshuffledCount)))
            guard d != 0 else { continue }
            let i = index(firstUnshuffled, offsetBy: d)
            self.swapAt(firstUnshuffled, i)
        }
    }
}
