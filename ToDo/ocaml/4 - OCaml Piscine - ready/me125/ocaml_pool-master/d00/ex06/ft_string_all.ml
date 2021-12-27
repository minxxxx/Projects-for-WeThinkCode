(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_string_all.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 15:35:09 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 16:00:16 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec string_all f str i =
	if String.length(str) <= i then
		true
	else if (f (String.get str i)) then
		string_all f str (i + 1)
	else
		false

let ft_string_all f str = string_all f str 0

(*
** Test
*)
let is_digit c = c >= '0' && c <= '9'

let print_bool b = print_string (if b then "true\n" else "false\n")

let () =
	print_bool (ft_string_all is_digit "Hello world !");
	print_bool (ft_string_all is_digit "0123456789");
	print_bool (ft_string_all is_digit "O12EAS67B9");
	print_bool (ft_string_all is_digit "")
