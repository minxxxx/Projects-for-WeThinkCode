(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   repeat_x.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 09:51:22 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/16 09:54:31 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec repeat_x n =
	if n < 0 then
		"Error"
	else if n = 0 then
		""
	else
		"x" ^ repeat_x (n - 1)

(*
** Test
*)
let () =
	print_endline (repeat_x (-1));
	print_endline (repeat_x 0);
	print_endline (repeat_x 1);
	print_endline (repeat_x 2);
	print_endline (repeat_x 5)
