(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_comb2.ml                                  :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 17:27:50 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 17:50:25 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let print_num n =
	print_char ' ';
	if n < 10 then
		print_char '0';
	print_int n

let rec comb_b a b first =
	if b <= 99 && a != b then begin
		if first then begin
			print_char '0';
			print_char '0';
		end else begin
			print_char ',';
			print_num a;
		end;
		print_num b;
		comb_b a (b + 1) false
	end

let rec comb_a a first =
	if a <= 99 then begin
		let a' = a + 1 in
		comb_b a a' first;
		comb_a a' false
	end

let ft_print_comb2 () = comb_a 0 true; print_char '\n'

(*
** Test
*)
let () = ft_print_comb2 ()
