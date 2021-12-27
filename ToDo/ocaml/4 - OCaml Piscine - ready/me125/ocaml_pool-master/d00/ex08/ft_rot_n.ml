(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_rot_n.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 17:00:15 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 17:26:05 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rot_mod min max c =
	if c > max then
		char_of_int (((c - min) mod (max - min)) + min - 1)
	else
		char_of_int c

let rot n c =
	if c >= 'a' && c <= 'z' then
		rot_mod (int_of_char 'a') (int_of_char 'z') ((int_of_char c) + n)
	else if c >= 'A' && c <= 'Z' then
		rot_mod (int_of_char 'A') (int_of_char 'Z') ((int_of_char c) + n)
	else
		c

let ft_rot_n n str = String.map (rot n) str

(*
** Test
*)
let () =
	print_endline (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
	print_endline (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz");
	print_endline (ft_rot_n 42 "0123456789");
	print_endline (ft_rot_n 2 "OI2EAS67B9");
	print_endline (ft_rot_n 0 "Damned !");
	print_endline (ft_rot_n 21 "");
	print_endline (ft_rot_n 1 "NBzlk qnbjr !");
