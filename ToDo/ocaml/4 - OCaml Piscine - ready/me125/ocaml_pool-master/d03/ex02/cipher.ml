(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   cipher.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 19:23:35 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 19:01:05 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rot42 str = String.map (Uncipher.rotc 42) str

let caesar n str = String.map (Uncipher.rotc n) str

let xor key str =
	let xorc key c = char_of_int ((int_of_char c) lxor key) in
	String.map (xorc key) str

let rec ft_crypt (str:string) fn =
	match fn with
	| []				-> str
	| head::tail		-> ft_crypt (head str) tail

(*
** Test
*)
let test str fn unfn =
	print_string "------------------\n";
	print_string ("str: " ^ str ^ "\n");
	let crpt = ft_crypt str fn in
	print_string ("crypt: " ^ crpt ^ "\n");
	print_string ("uncrypt: " ^ (Uncipher.ft_uncrypt crpt unfn) ^ "\n")

let () =
	test "lal" [] [];
	test "lal" [rot42] [Uncipher.unrot42];
	test "yo mama is so fat" [caesar 5] [Uncipher.uncaesar 5];
	test "yo mama is so fat" [xor 18; rot42; caesar 5] [xor 18; Uncipher.unrot42; Uncipher.uncaesar 5];
	print_string "------------------\n";
