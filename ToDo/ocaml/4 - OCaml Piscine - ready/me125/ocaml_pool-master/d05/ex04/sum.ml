(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sum.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 14:44:26 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 17:44:16 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let sum = ( +. )

(*
** Test
*)
let test_sum a b =
	print_float a;
	print_string " + ";
	print_float b;
	print_string " = ";
	print_float (sum a b);
	print_newline ()

let () =
	test_sum 10. 42.;
	test_sum 10. nan;
	test_sum nan 42.;
	test_sum nan (-.nan);
	test_sum nan 0.;
	test_sum 10. infinity;
	test_sum infinity 42.;
	test_sum 10. (-.infinity);
	test_sum nan nan;
	test_sum (-80.) (-10.);
	test_sum (-80.) 42.;
	test_sum 0. nan;
	test_sum 0. 0.;
