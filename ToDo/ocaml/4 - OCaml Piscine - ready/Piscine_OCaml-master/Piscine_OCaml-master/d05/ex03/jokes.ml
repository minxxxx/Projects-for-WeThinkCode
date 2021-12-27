let main () =
	Random.self_init ();
	if Array.length (Sys.argv) <= 1 then
		print_endline "Error ! Please enter an argument."
	else
	begin
		let ar = ref (Array.make 0 "") in
		try
			let file = open_in (Sys.argv.(1)) in
			while (true) do
				let str = input_line file in
			 		ar := Array.append !ar (Array.make 1 str)
			done
		with
		| End_of_file -> print_endline !ar.(Random.int (Array.length !ar))
		| _ -> ()
	end

let () = main ()
