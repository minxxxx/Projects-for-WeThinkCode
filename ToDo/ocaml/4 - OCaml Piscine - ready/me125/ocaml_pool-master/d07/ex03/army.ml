(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   army.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 17:22:22 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 17:38:32 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a] army = object
	initializer print_endline "armyy"
	val member = ([]:'a list)
	method add a = {< member = member @ [a] >}
	method delete =
		match member with
		| []			-> {<>}
		| head::tail	-> {< member = tail >}
	method print =
		let rec lol = function
			| head::tail		->
				print_endline (head#to_string);
				lol tail
			| []				-> ()
		in
		lol member
end
