(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   doctor.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 15:36:17 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 16:45:16 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class doctor = object (self)
	initializer print_endline "Lal"
	val name = "who"
	val age = 0
	val hp = 50
	val sidekick = new People.people
	method talk = print_endline "Hi! I’m the Doctor!"
	method travel_in_time start arrival =
		print_endline "          _";
		print_endline "         /-\\";
		print_endline "    _____|#|_____";
		print_endline "   |_____________|";
		print_endline "  |_______________|";
		print_endline "|||_POLICE_##_BOX_|||";
		print_endline " | |¯|¯|¯|||¯|¯|¯| |";
		print_endline " | |-|-|-|||-|-|-| |";
		print_endline " | |_|_|_|||_|_|_| |";
		print_endline " | ||~~~| | |¯¯¯|| |";
		print_endline " | ||~~~|!|!| O || |";
		print_endline " | ||~~~| |.|___|| |";
		print_endline " | ||¯¯¯| | |¯¯¯|| |";
		print_endline " | ||   | | |   || |";
		print_endline " | ||___| | |___|| |";
		print_endline " | ||¯¯¯| | |¯¯¯|| |";
		print_endline " | ||   | | |   || |";
		print_endline " | ||___| | |___|| |";
		print_endline "|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|";
		print_endline " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";
		{< age = age + arrival - start >}
	method to_string = "doctor ( name = " ^ name ^ " age = " ^ (string_of_int age) ^ " ; hp = " ^ (string_of_int hp) ^ " ; sidekick = " ^ sidekick#to_string ^ " )"
	method use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"
	method private regenerate = {< hp = 100 >}
	method test_regen = print_endline ((self#regenerate)#to_string)

end
