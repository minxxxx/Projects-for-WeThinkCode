(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   iter.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 10:34:00 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/16 10:52:36 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec iter f x n =
	if n = 0 then
		x
	else if n > 0 then
		f (iter f x (n - 1))
	else
		-1

(*
** Test
*)
let () =
	print_int (iter (fun x -> x * x) 2 4); print_char '\n';
	print_int (iter (fun x -> x * 2) 2 4); print_char '\n';
	print_int (iter (fun x -> x + 1) 2 1); print_char '\n';
	print_int (iter (fun x -> x + 1) 2 2); print_char '\n';
	print_int (iter (fun x -> x + 1) 2 4); print_char '\n';
