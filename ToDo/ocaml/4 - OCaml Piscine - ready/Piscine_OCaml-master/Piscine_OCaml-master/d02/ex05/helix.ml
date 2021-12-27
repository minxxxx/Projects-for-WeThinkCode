type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
type nucleotide = phosphate * deoxyribose * nucleobase
type helix = nucleotide list

let generate_nucleotide (base) : nucleotide =
	match base with
	| 'A'-> ("phosphate", "deoxyribose", A)
	| 'T'-> ("phosphate", "deoxyribose", T)
	| 'C'-> ("phosphate", "deoxyribose", C)
	| 'G'-> ("phosphate", "deoxyribose", G)
	| _ -> ("phosphate", "deoxyribose", None)

let rec generate_helix n : helix =
	if n <= 0 then
		[]
	else
		begin
		let base = match Random.int 4 with
			| 0 -> 'A'
			| 1 -> 'T'
			| 2 -> 'C'
			| 3 -> 'G'
			| _ -> ' '
		in
		generate_nucleotide(base) :: (generate_helix (n - 1))
		end

let rec helix_to_string (lst:helix) =
	let nucleobase_as_string c = match c with
		| A -> "A"
		| T -> "T"
		| C -> "C"
		| G -> "G"
		| None -> "None"
	in
	match  lst with
		| (a,b,c)::something::tail -> (nucleobase_as_string c) ^ " " ^ (helix_to_string (something::tail))
		| (a,b,c)::tail -> (nucleobase_as_string c)
		| [] -> ""

let rec complementary_helix (helix_1:helix) : helix =
	match helix_1 with
	| (a, b, c)::tail ->
		let new_elem = match c with
			| A -> generate_nucleotide 'T'
			| T -> generate_nucleotide 'A'
			| C -> generate_nucleotide 'G'
			| G -> generate_nucleotide 'C'
			| None -> generate_nucleotide ' '
				in new_elem::(complementary_helix tail)
	| [] -> []

let main () =
	Random.self_init(); (* Note : Le main doit initialiser le moteur de random. C'aurait pu etre le generate_helix mais le seed aurait ete reset a chaque appel. C'est un choix d'implementation. *)
	let helix_1 = generate_helix 10 in
	print_endline (helix_to_string helix_1);
	let helix_2 = complementary_helix helix_1 in
	print_endline (helix_to_string helix_2);

	let helix_3 = generate_helix 0 in
	print_endline (helix_to_string helix_3);
	let helix_4 = complementary_helix helix_3 in
	print_endline (helix_to_string helix_4);

	let helix_5 = generate_helix 20 in
	print_endline (helix_to_string helix_5);
	let helix_6 = complementary_helix helix_5 in
	print_endline (helix_to_string helix_6)


let () = main ()
