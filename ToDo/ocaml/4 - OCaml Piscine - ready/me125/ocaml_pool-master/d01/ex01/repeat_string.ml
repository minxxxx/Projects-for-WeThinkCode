(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   repeat_string.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 09:55:49 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/16 09:58:42 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec repeat_string ?(str="x") n =
	if n < 0 then
		"Error"
	else if n = 0 then
		""
	else
		str ^ repeat_string ~str:str (n - 1)

(*
** Test
*)
let () =
	print_endline (repeat_string (-1));
	print_endline (repeat_string 0);
	print_endline (repeat_string 1);
	print_endline (repeat_string ~str:"to" 2);
	print_endline (repeat_string ~str:"y" 5)
