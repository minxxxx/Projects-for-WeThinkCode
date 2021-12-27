(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_comb.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 14:11:06 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 15:18:36 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec comb_c a b c =
	if a = 0 then begin
		print_string (if c = 2 then "0" else ", 0");
		print_int ((b * 10) + c)
	end else begin
		print_string ", ";
		print_int ((a * 100) + (b * 10) + c)
	end;
	if c < 9 then
		comb_c a b (c + 1)

let rec comb_b a b =
	let b' = b + 1 in
	comb_c a b b';
	if b < 8 then
		comb_b a b'

let rec comb_a a =
	let a' = a + 1 in
	comb_b a a';
	if a < 7 then
		comb_a a'

let ft_print_comb () = comb_a 0; print_string "\n"

(*
** Test
*)
let () = ft_print_comb ()
