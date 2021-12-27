type radar = float array * string

let eu_dist a b =
	let rez = ref 0. in
	for i = 0 to Array.length a - 1 do
		rez := !rez +. ((a.(i) -. b.(i)) ** 2.)
	done ;
	sqrt(!rez)

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


let one_nn rlist radar =
	let getType (_, t) = t in
	let getLst (t, _) = t in
	if List.length rlist <= 1 then
		getType (List.nth rlist 0)
	else
		getType (List.fold_left
				(fun elem1 elem2 -> if eu_dist radar (getLst elem1) < (eu_dist radar (getLst elem2)) then elem1 else elem2)
				(List.hd rlist)
				(List.tl rlist))

let main () =
	if Array.length Sys.argv <= 1 then
		()
	else
		let rlist_opt =
			try
				Some (examples_of_file Sys.argv.(1))
			with
				| _ -> None
		in
		try
			match rlist_opt with
			| None -> print_endline "Error 2"
			| Some (rlist) ->
				List.iter (fun elem ->
					let (p1, p2) = elem in
					print_string "([|" ;
					Array.iter (fun t -> Printf.printf "%f ;" t) p1;
					print_string "|], ";
					Printf.printf "%s)\n" p2
					) rlist;
				print_string "one_nn rlist [|1.4;1.4|] : "; print_endline (one_nn rlist [|1.4;1.4|]);
				print_string "one_nn rlist [|1.6;1.6|] : "; print_endline (one_nn rlist [|1.6;1.6|]);
				print_string "one_nn rlist [|150.;150.|] : "; print_endline (one_nn rlist [|150.;150.|])
		with
			| _ -> print_endline "Error"

let () = main ()
