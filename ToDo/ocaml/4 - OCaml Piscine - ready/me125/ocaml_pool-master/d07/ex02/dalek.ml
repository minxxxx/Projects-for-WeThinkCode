(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   dalek.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 16:49:10 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 17:20:13 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rand_name () =
	"Dalek" ^ (String.init 3 (fun i ->
		char_of_int (if i = 0 then
			(Random.int 26) + (int_of_char 'A')
		else
			(Random.int 26) + (int_of_char 'a'))
	))

class dalek = object
	val name = rand_name ()
	val hp = 100
	val mutable shield = true
	method to_string = "dalek ( name = " ^ name ^ " ; hp = " ^ (string_of_int hp) ^ " ; shield = " ^ (string_of_bool shield) ^ " )"
	method talk =
		let msg = [|"Explain! Explain!";
			"Exterminate! Exterminate!";
			"I obey!";
			"You are the Doctor! You are the enemy of the Daleks!";|]
		in
		print_endline (msg.(Random.int 4))
	method exterminate (p:People.people) =
		shield <- if shield then false else true;
		p#die
	method die = print_endline "Emergency Temporal Shift!"
end
