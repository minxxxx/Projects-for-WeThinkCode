let examples_of_file filename =
	let example_of_line line =
		let split = String.split_on_char ',' line in
		let ar = Array.make (List.length split - 1) 0. in
		for i = 0 to List.length split - 2 do
			ar.(i) <- float_of_string (List.nth split i)
		done;
		(ar, List.nth split (List.length split - 1))
	in
	let ar = ref (Array.make 0 ([|1.|], "g")) in
	try
		let channel = open_in filename in
		while (true) do
			ar := Array.append !ar (Array.make 1 (example_of_line (input_line channel)))
		done;
		[]
	with
		| End_of_file -> Array.to_list !ar
		| _ -> []

let main () =
	if (Array.length Sys.argv <= 1) then
		()
	else
		let rez = examples_of_file Sys.argv.(1) in
		List.iter (fun elem ->
			let (p1, p2) = elem in
			print_string "([|" ;
			Array.iter (fun t -> Printf.printf "%f ;" t) p1;
			print_string "|], ";
			Printf.printf "%s)\n" p2
			) rez

let () = main ()
