
import Foundation

class Card : NSObject {

var color : Color
var value : Value

init (color: Color, value: Value)
{
  self.color = color
  self.value = value
}

override var description: String
{
  return "\(self.value) of \(self.color)"
}

//self returns receiver 
//object needs to be compared with receiver which is the self
override func isEqual(_ object: Any?) -> Bool{
  if let obj = object as? Card{
    return (obj.value == self.value && obj.color == self.color)
  }
  return false
}

static func ==(lhs:Card, rhs:Card)
{
  return (lhs == rhs)
}

}