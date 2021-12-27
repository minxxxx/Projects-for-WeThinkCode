let sequence n =
	let next lst =
		let rec next_loop current_lst =
			match current_lst with
			| a::b::c::tail when a = b && b = c -> 3::a::(next_loop tail)
			| a::b::tail when a = b -> 2::a::(next_loop tail)
			| a::tail -> 1::a::(next_loop tail)
			| [] -> []
		in
		next_loop lst
	in
	let rec list_as_string lst =
		match lst with
		| head::tail -> string_of_int head ^ list_as_string tail
		| _ -> ""
	in
	let rec get_next current_lst i =
		if i = n then
			list_as_string current_lst
		else
			get_next (next current_lst) (i + 1)
	in
		if n <= 0 then
			""
		else
			get_next [1] 1


let main () =
	print_endline (sequence 1);
	print_endline (sequence 2);
	print_endline (sequence 3);
	print_endline (sequence 4);
	print_endline (sequence 5);
	print_endline (sequence 6);
	print_endline (sequence 7);
	print_endline (sequence 8);
	print_endline (sequence 9);
	print_endline (sequence 10)

let () = main ()

(* (1,1) -> "11" ; -> (2,1) -> "21" -> (1,2);(1;1) -> 1211 -> (1,1);(1,2);(2,1) *)
