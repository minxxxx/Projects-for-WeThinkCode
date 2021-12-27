let rec crossover l1 l2 =
	let rec elem_in_l2 elem l2 =
		match l2 with
		| head::tail -> elem = head || (elem_in_l2 elem tail)
		| [] -> false
	in
	if l1 = [] || l2 = [] then
		[]
	else
		match l1 with
		| head1::tail1 -> if elem_in_l2 head1 l2
						then head1::(crossover tail1 l2)
						else crossover tail1 l2
		| [] -> []
let main () =
	let print_list lst = print_char '[' ; List.iter (Printf.printf "%d;") lst ; print_char ']' in
	let a1 = [1;2;3] in
	let a2 = [1;2;3;4] in
	print_list a1 ; print_string " and " ; print_list a2 ; print_string " -> " ; print_list (crossover a1 a2) ; print_char '\n';
	let b1 = [] in
	let b2 = [1;2;3;4] in
	print_list b1 ; print_string " and " ; print_list b2 ; print_string " -> " ; print_list (crossover b1 b2) ; print_char '\n';
	let c1 = [1;2;3] in
	let c2 = [] in
	print_list c1 ; print_string " and " ; print_list c2 ; print_string " -> " ; print_list (crossover c1 c2) ; print_char '\n';
	let b1 = [1;2;3;123] in
	let b2 = [123;2;3;4] in
	print_list b1 ; print_string " and " ; print_list b2 ; print_string " -> " ; print_list (crossover b1 b2) ; print_char '\n';
	let b1 = [] in
	let b2 = [] in
	print_list b1 ; print_string " and " ; print_list b2 ; print_string " -> " ; print_list (crossover b1 b2) ; print_char '\n';
	let b1 = [123] in
	let b2 = [123;4] in
	print_list b1 ; print_string " and " ; print_list b2 ; print_string " -> " ; print_list (crossover b1 b2) ; print_char '\n';
	let b1 = [1;2;3] in
	let b2 = [4;6;5] in
	print_list b1 ; print_string " and " ; print_list b2 ; print_string " -> " ; print_list (crossover b1 b2) ; print_char '\n'

let () = main ()
