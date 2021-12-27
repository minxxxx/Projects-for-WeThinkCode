import AppKit

class Card : NSObject {
    var color: Color
    var value: Value
    
    init (color: Color, value: Value) {
        self.color = color
        self.value = value
    }
    
    override var description: String {
        return "(\(value.hashValue + 1), \(color))"
    }
    
    override func isEqual(_ object: Any?) -> Bool {
        if (object is Card) {
            let obj = object as! Card
            if (obj.value != self.value || obj.color != self.color) {
                return false
            } else {
                return true
            }
        }
        return false
    }
    
    static func ==(lhs: Card, rhs: Card) -> Bool {
        return (lhs.isEqual(rhs))
    }
    
}
