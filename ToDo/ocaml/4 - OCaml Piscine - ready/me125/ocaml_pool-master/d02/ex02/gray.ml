(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gray.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 11:35:26 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/17 17:00:38 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec list_concat l1 l2 =
	match l1 with
	| [] -> l2
	| head::tail -> head :: (list_concat tail l2)

let list_reverse l =
	let rec loop l acc =
		match l with
		| [] -> acc
		| head::tail -> loop tail (head :: acc)
	in
	loop l []

let rec shade_prefix prefix shade =
	match shade with
	| [] -> []
	| head::tail ->
		(prefix ^ head) :: shade_prefix prefix tail

let rec shades_of_gray shade n =
	match n with
	| 0 -> shade
	| _ ->
		let left = shade_prefix "0" shade in
		let right = shade_prefix "1" (list_reverse shade) in
		shades_of_gray (list_concat left right) (n - 1)

let rec print_shade shade =
	match shade with
	| [] -> print_char '\n'
	| head::sec::tail -> print_string head; print_string ", "; print_shade (sec::tail)
	| head::tail -> print_string head; print_char '\n'

let gray n = print_shade (if n > 0 then shades_of_gray ["0"; "1"] (n - 1) else [])

(*
** Test
*)
(* let print_string_list l =
	print_char '[';
	let rec loop l =
		match l with
		| [] -> ()
		| head::sec::tail -> print_string head; print_string "; "; loop (sec :: tail)
		| head::tail -> print_string head; loop tail
	in
	loop l;
	print_char ']'
 *)
let () =
	gray (-1);
	gray 0;
	gray 1;
	gray 2;
	gray 3;
	gray 4;
