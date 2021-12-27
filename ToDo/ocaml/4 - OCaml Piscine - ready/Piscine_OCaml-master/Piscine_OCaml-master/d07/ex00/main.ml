let () =
	let p1 = new People.people "Donna Noble" in
	print_endline ("p1#to_string = " ^ p1#to_string) ; print_char '\n';
	print_endline "p1#talk" ; p1#talk ; print_char '\n';
	print_endline "p1#die" ; p1#die
