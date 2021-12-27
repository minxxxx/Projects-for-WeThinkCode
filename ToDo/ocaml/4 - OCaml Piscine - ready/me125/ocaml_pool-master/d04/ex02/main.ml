(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 15:31:46 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 16:48:49 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let test_card c =
	Printf.printf "[%s] %s cmp:%d Spade:%B\n" (Card.toString c) (Card.toStringVerbose c)
		(Card.compare c (Card.newCard Card.Value.T10 Card.Color.Heart))
		(Card.isOf c Card.Color.Spade)

let rec all = function
	| []			-> ()
	| head::tail	-> test_card head; all tail

let () =
	all Card.all;
	print_string "best spade: "; test_card (Card.best Card.allSpades)
