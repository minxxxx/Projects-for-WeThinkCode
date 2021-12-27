(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_test_sign.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 12:23:47 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 13:28:48 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_test_sign a = print_endline (if a < 0 then "negative" else "positive")

(*
** Test
*)
let test a =
	print_string "Test with ["; print_int(a); print_string "]: ";
	ft_test_sign a

let () = test 5;
	test 1;
	test 0;
	test (-1);
	test (-42)
