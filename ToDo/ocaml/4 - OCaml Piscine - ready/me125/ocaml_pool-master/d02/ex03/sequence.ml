(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sequence.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 16:18:20 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/17 18:25:30 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec seq_len l e i =
	match l with
	| head::tail when head = e -> seq_len tail e (i + 1)
	| _ -> i

let rec seq_skip l e =
	match l with
	| head::tail when head = e -> seq_skip tail e
	| _ -> l

let rec seq_next l =
	match l with
	| [] -> []
	| head::tail ->
		let len = seq_len tail head 1 in
		len :: head :: seq_next (seq_skip tail head)

let rec seq l n =
	match n with
	| _ when n <= 0 -> l
	| _ -> seq (seq_next l) (n - 1)

let rec seq_str str l =
	match l with
	| [] -> str
	| head::tail -> seq_str (str ^ (string_of_int head)) tail

let sequence n = seq_str "" (seq [1] n)

(*
** Test
*)
let test n =
	print_int n; print_string ": "; print_string (sequence n); print_char '\n'

let () =
	test 0;
	test 1;
	test 2;
	test 3;
	test 4;
	test 5;
	test 6;
	test 7;
