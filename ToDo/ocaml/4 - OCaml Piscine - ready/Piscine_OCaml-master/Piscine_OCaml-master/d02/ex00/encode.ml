let encode lst =
	let rec loop n templst =
		match templst with
		| [] -> []
		| tete::next::queue ->
			if tete = next then
				loop (n + 1) (next::queue)
			else
				(n + 1, tete) :: (loop 0 (next::queue))
		| tete::queue ->
			[(n + 1), tete]
	in
		loop 0 lst

let main () =
	let print_list lst = print_char '[' ; List.iter (Printf.printf "%d;") lst ; print_char ']' in
	let print_pair (x, y) = Printf.printf("(%d,%d) ") x y in
	let print_rez lst = print_char '[' ; List.iter print_pair lst ; print_char ']' in

	let print_list_char lst = print_char '[' ; List.iter (Printf.printf "%c;") lst ; print_char ']' in
	let print_pair_char (x, y) = Printf.printf("(%d,%c) ") x y in
	let print_rez_char lst = print_char '[' ; List.iter print_pair_char lst ; print_char ']' in


	let a = [1;2;2;0;1;2] in
	let b = [1;2;2;0;1;3;2;2;2] in
	let c = [] in
	let d = [1] in
	let e = ['a';'a';'a';'b';'b';'b'] in
	let f = ['c';'o';'u';'c';'o';'u';' ';] in

	print_list a ; print_string " -> " ; print_rez (encode a) ; print_char '\n';
	print_list b ; print_string " -> " ; print_rez (encode b) ; print_char '\n';
	print_list c ; print_string " -> " ; print_rez (encode c) ; print_char '\n';
	print_list d ; print_string " -> " ; print_rez (encode d) ; print_char '\n';
	print_list_char e ; print_string " -> " ; print_rez_char (encode e) ; print_char '\n';
	print_list_char f ; print_string " -> " ; print_rez_char (encode f) ; print_char '\n'


let () = main ()
