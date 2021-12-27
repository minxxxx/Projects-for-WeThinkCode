var deck = Deck(shuffleDeck: true)

print("outs: ")

print(deck.outs)

print("\nshow cards:")

print(deck.cards)

print("\nDraw:")

var card = deck.draw()

print("\nshow cards:")

print(deck.cards)

print("\nshow outs:")

print(deck.outs)

print("Lets remove the card from outs and into discards")

deck.fold(c: card!)

print("Print out then discard")

print(deck.outs)

print(deck.discards)



