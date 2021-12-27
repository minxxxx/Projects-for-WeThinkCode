let card1: Card = Card(color: Color.hearts, value: Value.King)
let card2: Card = Card(color: Color.spades, value: Value.King)
let card3: Card = Card(color: Color.clubs, value: Value.King)
let card4: Card = Card(color: Color.spades, value: Value.King)

print(card1)
print(card2)
print(card3)
print(card4)
print("Card1 = king of hearts, Card2 = king of spades which is... ", String(card1 == card2))
print("Card2 = king of spades, Card4 = king of spades which is ...", String(card2 == card4))


