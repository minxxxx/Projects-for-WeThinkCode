(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_countdown.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:33:09 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/16 17:53:55 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_countdown i = 
	if i <= 0 then
		begin
			print_char '0';
			print_char '\n'
		end
	else
		begin
			print_int i;
			print_char '\n';
			ft_countdown (i - 1)
		end

(*
** Test
*)
let test a =
	print_string "Test with ["; print_int(a); print_string "]: ";
	ft_countdown a

let () = test 5;
	test 1;
	test 0;
	test (-1)
