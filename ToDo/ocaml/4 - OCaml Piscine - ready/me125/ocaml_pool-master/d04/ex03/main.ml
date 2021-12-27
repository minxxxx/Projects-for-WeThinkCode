(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 17:52:38 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 18:15:42 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec print_string_list = function
	| []				-> print_newline ()
	| head::sec::tail	-> print_string (head ^ ", "); print_string_list (sec::tail)
	| head::tail		-> print_string head; print_string_list tail

let test_card c =
	Printf.printf "[%s] %s cmp:%d Spade:%B\n" (Deck.Card.toString c) (Deck.Card.toStringVerbose c)
		(Deck.Card.compare c (Deck.Card.newCard Deck.Card.Value.T10 Deck.Card.Color.Heart))
		(Deck.Card.isOf c Deck.Card.Color.Spade)

let rec test_deck deck =
	let (card, next) = Deck.drawCard deck in
	test_card card;
	if Deck.isEmpty next then
		print_newline ()
	else
		test_deck next

let () =
	Random.self_init ();
	print_string "  ----> Deck 1 <----\n";
	print_string_list (Deck.toStringList (Deck.newDeck ()));
	print_string "  ----> Deck 2 <----\n";
	print_string_list (Deck.toStringListVerbose (Deck.newDeck ()));
	print_string "  ----> Deck 3 <----\n";
	test_deck (Deck.newDeck ());
