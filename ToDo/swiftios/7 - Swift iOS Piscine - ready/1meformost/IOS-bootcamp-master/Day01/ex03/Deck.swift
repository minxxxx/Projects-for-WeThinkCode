import AppKit

class Deck : NSObject {
    static let allSpades = Value.allValues.map{Card(color: Color.spades, value: $0)}
    static let allDiamonds = Value.allValues.map{Card(color: Color.diamonds, value: $0)}
    static let allHearts = Value.allValues.map{Card(color: Color.hearts, value: $0)}
    static let allClubs = Value.allValues.map{Card(color: Color.clubs, value: $0)}
    
    static let allCards = [allSpades.map{$0}, allDiamonds.map{$0}, allHearts.map{$0}, allClubs.map{$0}]
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
