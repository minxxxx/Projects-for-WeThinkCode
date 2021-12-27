let main () =
	print_endline "Not verbose : ";
	List.iter (function item -> print_endline (Value.toString item)) Value.all;
	print_endline "\nVerbose : ";
	List.iter (function item -> print_endline (Value.toStringVerbose item)) Value.all;
	begin
	match Value.all with
		| Value.T2::tail -> List.iter (function item ->
				print_endline ("Previous of " ^ (Value.toStringVerbose item) ^ " -> " ^ Value.toStringVerbose (Value.previous item))) tail;
		| _ -> ();
	end;

	print_char '\n';
	List.iter (function item ->
			match item with
			| Value.As -> ()
			| _ -> print_endline ("Next of " ^ (Value.toStringVerbose item) ^ " -> " ^ Value.toStringVerbose (Value.next item))
		) Value.all


let () = main ()
