(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_alphabet.ml                               :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:58:42 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 14:09:34 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_print_alphabet () =
	let rec print_alpha c =
		print_char c;
		if c = 'z' then
			print_char '\n'
		else
			print_alpha (char_of_int ((int_of_char c) + 1))
	in
	print_alpha 'a'

(*
** Test
*)
let () = ft_print_alphabet ()
