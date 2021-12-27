(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   crossover.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 11:09:42 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/17 11:26:56 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec list_contains l1 e =
	match l1 with
	| [] -> false
	| head::tail when head = e -> true
	| head::tail -> list_contains tail e

let rec crossover l1 l2 =
	match l1 with
	| [] -> []
	| head::tail when list_contains l2 head -> head :: crossover tail l2
	| head::tail -> crossover tail l2

(*
** Test
*)
let printlist l =
	print_char '[';
	let rec printl l =
		match l with
		| [] -> ()
		| head::sec::tail -> print_int head; print_string "; "; printl (sec :: tail)
		| head::tail -> print_int head; printl tail
	in
	printl l;
	print_char ']'

let test l1 l2 =
	printlist l1;
	print_string "  x  ";
	printlist l2;
	print_string "  =  ";
	printlist (crossover l1 l2);
	print_char '\n'

let () =
	test [1; 2; 3; 4; 5; 6] [2; 2; 8; 4];
	test [1; 2; 3; 4; 5; 6] [7; 8; 9; 10];
	test [2; 2; 3; 3; 4; 4] [2; 4];
	test [2; 2; 3; 3; 4; 4] [2; 4; 4];
	test [] [1; 2; 5; 3; 7; 4];
	test [1; 2; 5; 3; 7; 4] [];
	test [] [];
