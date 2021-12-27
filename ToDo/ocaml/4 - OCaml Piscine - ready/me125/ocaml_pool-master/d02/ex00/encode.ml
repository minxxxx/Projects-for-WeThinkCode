(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   encode.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 10:30:36 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/17 11:09:17 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec tuplelist l =
	match l with
	| [] -> []
	| head::tail -> (1, head) :: tuplelist tail

let rec encodelist l =
	let can_compress (_, first) (_, sec) = first = sec in
	let compress (first, e) (sec, _) = (first + sec, e) in
	match l with
	| [] -> []
	| head::sec::tail when can_compress head sec -> encodelist (compress head sec :: tail)
	| head::tail -> head :: encodelist tail

let encode l = encodelist (tuplelist l)

(*
** Test
*)
let print_tuple (n, e) =
	if n > 1 then
		print_int n;
	print_char e

let rec printlist l =
	match l with
	| [] -> print_char '\n'
	| head::tail -> print_tuple head; printlist tail

let () =
	printlist (encode []);
	printlist (encode ['a']);
	printlist (encode ['a'; 'a']);
	printlist (encode ['a'; 'b']);
	printlist (encode ['a'; 'b'; 'a'; 'a'; 'a'; 'b'; 'b']);
	printlist (encode ['a'; 'b'; 'c'; 'd'; 'e'; 'f']);
	printlist (encode ['a'; 'a'; 'a'; 'a'; 'b'; 'b']);
