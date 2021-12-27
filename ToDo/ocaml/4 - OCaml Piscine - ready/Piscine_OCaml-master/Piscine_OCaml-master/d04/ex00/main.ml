let main () =
	let color_list = Color.all in
	print_endline "Not verbose : ";
	List.iter (function item -> print_endline (Color.toString item)) color_list;
	print_endline "\nVerbose : ";
	List.iter (function item -> print_endline (Color.toStringVerbose item)) color_list

let () = main ()
