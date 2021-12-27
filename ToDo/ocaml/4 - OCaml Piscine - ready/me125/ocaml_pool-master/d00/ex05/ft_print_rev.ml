(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_rev.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 15:20:15 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/15 15:33:22 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec print_rev s i =
	if i < 0 then
		print_char '\n'
	else begin
		print_char (String.get s i);
		print_rev s (i - 1)
	end

let ft_print_rev s = print_rev s (String.length(s) - 1)

(*
** Test
*)
let () =
	ft_print_rev "Hello world !";
	ft_print_rev "a";
	ft_print_rev "ab";
	ft_print_rev "abc";
	ft_print_rev ""
