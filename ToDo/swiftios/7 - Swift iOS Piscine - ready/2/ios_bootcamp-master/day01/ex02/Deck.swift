import Foundation

//NSObject is the base class for most ObjC objects. In Swift you would inherit from it if you want your Swift object to be an ObjC object
class Deck: NSObject{

    
    //map loops over operation and applies the same operation to each element in collection
    static let allSpades = Value.allValues.map{ (v) -> Card in
        return (Card(color: Color.spades, value:v))
        }

    static let allDiamonds = Value.allValues.map{ (v) -> Card in
        return (Card(color: Color.diamonds, value:v))
        }

     static let allHearts = Value.allValues.map{ (v) -> Card in
        return (Card(color: Color.hearts, value:v))
        }

    static let allClubs = Value.allValues.map{ (v) -> Card in
        return (Card(color: Color.clubs, value:v))
        }


        static let allCards : [[Card]] = [allClubs + allHearts + allSpades + allDiamonds]
}
 
