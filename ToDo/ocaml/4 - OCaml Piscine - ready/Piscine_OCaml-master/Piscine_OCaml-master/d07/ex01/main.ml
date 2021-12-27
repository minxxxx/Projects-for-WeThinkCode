let () =
	let p1 = new People.people "Donna Noble" in
	let d = new Doctor.doctor "JustTheDoctor" 951 p1 in
	print_endline ("p1#to_string = " ^ p1#to_string) ; print_char '\n';
	print_endline "p1#talk" ; p1#talk ; print_char '\n';
	print_endline "p1#die" ; p1#die; print_char '\n';

	print_endline ("d#to_string = " ^ d#to_string) ; print_char '\n';
	let d = d#travel_in_time 100 20  in
	print_endline ("After travel from year 100 to year 20 : " ^ d#to_string) ; print_char '\n';
	let d = d#travel_in_time 20 1020 in
	print_endline ("After travel from year 20 to year 1020 : " ^ d#to_string) ; print_char '\n';
	print_endline "d#use_sonic_screwdriver" ; d#use_sonic_screwdriver;

	(* Just for the defense session : *)
	let d = d#get_hurt_but_just_for_the_defense_session in
	print_endline ("After get_hurt_but_just_for_the_defense_session : " ^ d#to_string);
	let d = d#public_regenerate_but_just_for_the_defense_session in
	print_endline ("After public_regenerate_but_just_for_the_defense_session : " ^ d#to_string) ;
