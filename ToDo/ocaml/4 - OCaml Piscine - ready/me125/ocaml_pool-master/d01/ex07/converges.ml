(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   converges.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 10:52:55 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/16 12:57:56 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec converges f x n =
	if n < 0 then
		false
	else if (f x) = x then (* lol *)
		true
	else
		converges f (f x) (n - 1)

(*
** Test
*)
let print_bool a =
	print_string (if a then "true" else "false")

let () =
	print_bool (converges (( * ) 2) 2 5); print_char '\n';
	print_bool (converges (fun x -> x / 2) 2 3); print_char '\n';
	print_bool (converges (fun x -> x / 2) 2 2); print_char '\n';
	print_bool (converges (fun x -> x / 2) 2 42); print_char '\n';
	print_bool (converges (fun x -> x + 2) 2 8); print_char '\n';
	print_bool (converges (fun x -> x * 2) 42 0); print_char '\n';
