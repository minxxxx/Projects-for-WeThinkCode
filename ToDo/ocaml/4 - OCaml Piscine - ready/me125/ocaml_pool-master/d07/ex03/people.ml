(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   people.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 11:39:15 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 15:34:25 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class people = object
	initializer print_endline "Hey you"
	val name = "default"
	val hp = 100
	method talk = print_endline ("I'm " ^ name ^ "! Do you know the Doctor?")
	method to_string = "people ( name = " ^ name ^ " ; hp = " ^ (string_of_int hp) ^ " )"
	method die = print_endline "Aaaarghh!"
end
