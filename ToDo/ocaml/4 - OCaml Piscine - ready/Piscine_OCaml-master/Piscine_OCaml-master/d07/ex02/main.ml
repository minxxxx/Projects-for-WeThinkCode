let () =
	let p1 = new People.people "Donna Noble" in
	let d = new Doctor.doctor "JustTheDoctor" 951 p1 in
	let dalek = new Dalek.dalek in
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


	print_endline dalek#to_string;

	print_endline "Dalek talks : ";
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
		dalek#talk;
	print_endline "Dalek talks end";


	print_endline "\n\nBattle begins....";
	let d = d#travel_in_time 1020 1030 in
	print_endline ("The doctor just traveled in time to year 1030, here is a proof : " ^ d#to_string ^ ". Oh god, he just saw a broken dalek !") ;
	print_endline "The doctor try to uses his sonic screwdrier on the broken dalek.";
	d#use_sonic_screwdriver ;
	print_endline "Oh, the dalek is coming back to life, and he isn't happy !" ;
	print_endline dalek#to_string ;
	dalek#talk ;
	dalek#talk ;
	dalek#talk ;
	print_endline "The dalek starts to look at the doctor's companion.. which is :";
	print_endline p1#to_string ;
	print_endline "The dalek shoots at it !" ;
	dalek#exterminate p1 ;
	print_endline "Looks like the doctor's companion is dead, that's awful !" ;
	print_endline p1#to_string ;
	print_endline "The doctor is mad, he attacks the dalek and kills it !" ;
	dalek#die
