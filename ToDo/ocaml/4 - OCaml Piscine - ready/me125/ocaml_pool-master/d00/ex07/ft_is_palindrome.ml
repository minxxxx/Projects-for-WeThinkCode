(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_is_palindrome.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 16:14:12 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 16:20:15 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec palindrome str i j =
	if i >= j then
		true
	else if (String.get str i) <> (String.get str j) then
		false
	else
		palindrome str (i + 1) (j - 1)

let ft_is_palindrome str = palindrome str 0 ((String.length str) - 1)

(*
** Test
*)
let print_bool b = print_string (if b then "true\n" else "false\n")

let () =
	print_bool (ft_is_palindrome "radar");
	print_bool (ft_is_palindrome "madam");
	print_bool (ft_is_palindrome "car");
	print_bool (ft_is_palindrome "Bob");
	print_bool (ft_is_palindrome "a");
	print_bool (ft_is_palindrome "")
