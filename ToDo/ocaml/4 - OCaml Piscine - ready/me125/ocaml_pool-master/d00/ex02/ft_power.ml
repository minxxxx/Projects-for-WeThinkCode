(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_power.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:44:48 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 13:58:10 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_power n pow =
	if pow <= 0 then
		1
	else
		n * (ft_power n (pow - 1))

(*
** Test
*)
let test a b =
	print_string "Test with ["; print_int(a);
	print_string ", "; print_int(b); print_string "]: ";
	print_int (ft_power a b); print_char '\n'

let () = test 2 4;
	test 3 0;
	test 0 5;
	test (-2) 5;
	test 2 8
