let rec repeat_string ?(str="x") n =
	if n < 0 then
		"Error"
	else if n = 0 then
		""
	else
		str ^ repeat_string ~str:str (n - 1)


let main () =
	print_endline (repeat_string 3);
	print_endline (repeat_string ~str:"abc" 3);
	print_endline (repeat_string ~str:"abc" (-1));
	print_endline (repeat_string ~str:"toto" (2));
	print_endline (repeat_string ~str:"toto" (1));
	print_endline (repeat_string (-1))


let () = main ()
