(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   micronap.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 12:38:15 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/22 12:41:41 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let my_sleep () = Unix.sleep 1

let main argc argv =
	if argc < 2 then
		invalid_arg "Not enougth argument"
	else
		let n = int_of_string argv.(1) in
		for i = 1 to n do
			my_sleep ()
		done

let () =
	try main (Array.length Sys.argv) Sys.argv with
	| _				-> ()
