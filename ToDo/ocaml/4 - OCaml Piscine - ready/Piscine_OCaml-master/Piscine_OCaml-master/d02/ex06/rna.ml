type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type nucleotide = phosphate * deoxyribose * nucleobase
type helix = nucleotide list
type rna = nucleobase list

let generate_nucleotide (base) : nucleotide =
	match base with
	| 'A'-> ("phosphate", "deoxyribose", A)
	| 'T'-> ("phosphate", "deoxyribose", T)
	| 'C'-> ("phosphate", "deoxyribose", C)
	| 'G'-> ("phosphate", "deoxyribose", G)
	| 'U'-> ("phosphate", "deoxyribose", U)
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
		| U -> "U"
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
			| U -> generate_nucleotide 'A' (* Shouldn't be called *)
			| None -> generate_nucleotide ' '
				in new_elem::(complementary_helix tail)
	| [] -> []

let rec generate_rna (helix:helix) : rna = match helix with
	| (a,b,c)::tail ->
		let new_elem = match c with
			| A -> U
			| T -> A
			| C -> G
			| G -> C
			| U -> A (* Shouldn't be called *)
			| None -> None
		in new_elem::(generate_rna tail)
	| [] -> []

let main () =
	Random.self_init(); (* Note : Le main doit initialiser le moteur de random. C'aurait pu etre le generate_helix mais le seed aurait ete reset a chaque appel. C'est un choix d'implementation. *)
	let rec print_rna rna = match rna with
		| head::tail when head = A -> print_string "A " ; print_rna tail
		| head::tail when head = T -> print_string "T " ; print_rna tail
		| head::tail when head = C -> print_string "C " ; print_rna tail
		| head::tail when head = G -> print_string "G " ; print_rna tail
		| head::tail when head = U -> print_string "U " ; print_rna tail
		| head::tail when head = None -> print_string "None " ; print_rna tail
		| _ -> print_char '\n' in


	let helix_1 = generate_helix 10 in
	print_endline (helix_to_string helix_1);
	let rna_1 = generate_rna helix_1 in
	print_rna rna_1;

	print_endline "";

	let helix_2 = complementary_helix helix_1 in
	print_endline (helix_to_string helix_2);
	let rna_2 = generate_rna helix_2 in
	print_rna rna_2

let () = main ()
