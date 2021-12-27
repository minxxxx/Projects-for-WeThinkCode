(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 11:39:13 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 17:21:33 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	Random.self_init ();
	let p = new People.people in
	p#talk;
	print_endline ("Whiiii... " ^ (p#to_string));
	print_endline "Now die";
	let d = new Doctor.doctor in
	d#talk;
	print_endline (d#to_string);
	print_endline ((d#travel_in_time 666 2014)#to_string);
	d#test_regen;
	d#use_sonic_screwdriver;
	print_endline "Dalek";
	let dalek = new Dalek.dalek in
	dalek#talk;
	print_endline (dalek#to_string);
	p#talk;
	dalek#exterminate p;
	print_endline (dalek#to_string);
	dalek#exterminate p;
	dalek#talk;
	d#use_sonic_screwdriver;
	dalek#die
