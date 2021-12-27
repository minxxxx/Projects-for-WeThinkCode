let main () =
	let deck1 = Deck.newDeck () in
	let deck2 = Deck.newDeck () in

	print_endline "Deck1 : ";
	List.iter (function item -> print_string (item ^ " ")) (Deck.toStringListVerbose deck1); print_char '\n';
	print_endline "\nDeck2 : ";
	List.iter (function item -> print_string (item ^ " ")) (Deck.toStringListVerbose deck2); print_char '\n';

	print_endline "Deck1 : ";
	List.iter (function item -> print_string (item ^ " ")) (Deck.toStringList deck1); print_char '\n';
	print_endline "\nDeck2 : ";
	List.iter (function item -> print_string (item ^ " ")) (Deck.toStringList deck2); print_char '\n';

	let nbrPerHands = 3 in
	let drawHand deck =
		let rec loop n deckn hand = match n with
		| 0 -> (hand, deckn)
		| _ -> let (card, remaining) = (Deck.drawCard deckn) in loop (n - 1) remaining (card::hand)
		in loop nbrPerHands deck []
	in

	print_endline ("Drawing a hand of " ^ (string_of_int nbrPerHands) ^ " cards from deck1");
	let (hand, newDeck1) = drawHand deck1 in
	List.iter (function item -> print_string (Deck.Card.toStringVerbose item ^ " ")) (hand); print_char '\n';
	print_endline "Remaing in deck1 : ";
	List.iter (function item -> print_string (item ^ " ")) (Deck.toStringList newDeck1); print_char '\n';
	print_endline ("Best card in hand : " ^ (Deck.Card.toStringVerbose (Deck.Card.best hand)))

let () = main ()
