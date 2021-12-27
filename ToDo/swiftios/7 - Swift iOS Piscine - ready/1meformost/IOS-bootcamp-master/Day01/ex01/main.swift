let card1 = Card(color:Color.spades, value:Value.Five)
let card2 = Card(color:Color.spades, value:Value.Five)
let card3 = Card(color:Color.clubs, value:Value.Four)

print(card1)
print(card2)
print(card3)

print(card1.description)
print(card2.description)
print(card3.description)

print(card1.isEqual(card2))
print(card1.isEqual(card3))

print(card1 == card2)
print(card1 == card3)
