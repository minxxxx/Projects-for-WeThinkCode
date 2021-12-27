(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 11:39:13 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 16:47:33 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let p = new People.people in
	p#talk;
	print_endline ("Whiiii... " ^ (p#to_string));
	print_endline "Now die";
	p#die;
	let d = new Doctor.doctor in
	d#talk;
	print_endline (d#to_string);
	print_endline ((d#travel_in_time 666 2014)#to_string);
	d#test_regen;
	d#use_sonic_screwdriver
