(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 13:13:20 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/22 14:29:40 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let random_joke jokes =
	Random.self_init ();
	print_endline (jokes.(Random.int (Array.length jokes)))

let main argc argv =
	if argc < 2 then
		failwith "Not enougth argument"
	else
		let c_in = open_in argv.(1) in
		let jokes_tmp = ref [] in
		try
			while true do
				jokes_tmp := !jokes_tmp @ [input_line c_in]
			done
		with
		| End_of_file		->
			let joke_array = Array.of_list !jokes_tmp in
			random_joke joke_array

let () =
	try main (Array.length Sys.argv) Sys.argv with
	| Sys_error (msg)
	| Failure (msg)			-> print_endline ("Error: " ^ msg)
	| _						-> print_endline "Error occur"
