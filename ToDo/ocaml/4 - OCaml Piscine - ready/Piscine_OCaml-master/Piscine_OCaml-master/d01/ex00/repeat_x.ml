let rec repeat_x n =
	if n < 0 then
		"Error"
	else if n = 0 then
	 	""
	else
	 	"x" ^ repeat_x (n - 1)

let main () =
	print_endline (repeat_x 1);
	print_endline (repeat_x 3);
	print_endline (repeat_x (-1));
	print_endline (repeat_x (0))

let () = main ()
