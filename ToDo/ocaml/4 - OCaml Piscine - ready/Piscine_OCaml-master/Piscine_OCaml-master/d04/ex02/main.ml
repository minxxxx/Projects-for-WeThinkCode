let main () =
	List.iter (function item -> print_endline (Card.toStringVerbose item)) Card.allSpades;
	List.iter (function item -> print_endline (Card.toStringVerbose item)) Card.allHearts;
	List.iter (function item -> print_endline (Card.toStringVerbose item)) Card.allDiamonds;
	List.iter (function item -> print_endline (Card.toStringVerbose item)) Card.allClubs;
	print_endline "";
	List.iter (function item -> print_endline (Card.toStringVerbose item)) Card.all;
	print_endline "";

	let card1 = Card.newCard T2 Heart in
	let card2 = Card.newCard Queen Spade in
	let card3 = Card.newCard T8 Diamond in
	let card4 = Card.newCard T8 Club in
	print_endline ("Card1 : " ^ (Card.toStringVerbose card1));
	print_endline ("Card2 : " ^ (Card.toStringVerbose card2));
	print_endline ("Card3 : " ^ (Card.toStringVerbose card3));
	print_endline ("Card4 : " ^ (Card.toStringVerbose card4));
	if Card.compare card1 card2 < 0 then
		print_endline "card1 < card2"
	else if Card.compare card1 card2 == 0 then
		print_endline "card1 = card2"
	else
		print_endline "card1 > card2";

	if Card.compare card3 card1 < 0 then
		print_endline "card3 < card1"
	else if Card.compare card3 card1 == 0 then
		print_endline "card3 = card1"
	else
		print_endline "card3 > card1";

	if Card.compare card3 card4 < 0 then
		print_endline "card3 < card4"
	else if Card.compare card3 card4 == 0 then
		print_endline "card3 = card4"
	else
		print_endline "card3 > card4";

	print_endline ("Max of card1 and card2 : " ^ (Card.toStringVerbose (Card.max card1 card2)));
	print_endline ("Min of card1 and card2 : " ^ (Card.toStringVerbose (Card.min card1 card2)));

	print_endline ("Max of card3 and card4 : " ^ (Card.toStringVerbose (Card.max card3 card4)));
	print_endline ("Min of card3 and card4 : " ^ (Card.toStringVerbose (Card.min card3 card4)));

	print_endline ("Best of card1, card2, card3 and card4 : " ^ (Card.toStringVerbose (Card.best [card1;card2;card3;card4])));
	print_endline ("Best of allDiamonds : " ^ (Card.toStringVerbose (Card.best Card.allDiamonds)));
	print_endline ("Best of all : " ^ (Card.toStringVerbose (Card.best Card.all)));

	if (Card.isSpade card1) then
		print_endline "card1 is Spade"
	else
		print_endline "card1 isn't Spade";

	if (Card.isSpade card2) then
		print_endline "card2 is Spade"
	else
		print_endline "card2 isn't Spade";

	if (Card.isSpade card3) then
		print_endline "card3 is Spade"
	else
		print_endline "card3 isn't Spade";

	if (Card.isOf card4 Spade) then
		print_endline "card4 is Spade"
	else
		print_endline "card4 isn't Spade"

let () = main ()
