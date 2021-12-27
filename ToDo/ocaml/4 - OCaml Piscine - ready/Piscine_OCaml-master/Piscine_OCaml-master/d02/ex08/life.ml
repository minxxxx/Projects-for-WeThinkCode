type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type nucleotide = phosphate * deoxyribose * nucleobase
type helix = nucleotide list
type rna = nucleobase list

type aminoacid = Ala | Arg | Asn | Asp | Cys | Gln | Glu | Gly | His | Ile | Leu | Lys | Met | Phe | Pro | Ser | Thr | Trp | Tyr | Val
type protein = aminoacid list

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
		| (a,b,c)::something::tail -> (nucleobase_as_string c) ^ (helix_to_string (something::tail))
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

let rec generate_bases_triplets (rna:rna) =  match rna with
	| a::b::c::tail -> (a, b, c) :: (generate_bases_triplets tail)
	| _ -> []

let rec string_of_protein (prot:protein) = match prot with
	| Arg::tail -> "Arg " ^ (string_of_protein tail)
	| Ala::tail -> "Ala " ^ (string_of_protein tail)
	| Asn::tail -> "Asn " ^ (string_of_protein tail)
	| Asp::tail -> "Asp " ^ (string_of_protein tail)
	| Cys::tail -> "Cys " ^ (string_of_protein tail)
	| Gln::tail -> "Gln " ^ (string_of_protein tail)
	| Glu::tail -> "Glu " ^ (string_of_protein tail)
	| Gly::tail -> "Gly " ^ (string_of_protein tail)
	| His::tail -> "His " ^ (string_of_protein tail)
	| Ile::tail -> "Ile " ^ (string_of_protein tail)
	| Leu::tail -> "Leu " ^ (string_of_protein tail)
	| Lys::tail -> "Lys " ^ (string_of_protein tail)
	| Met::tail -> "Met " ^ (string_of_protein tail)
	| Phe::tail -> "Phe " ^ (string_of_protein tail)
	| Pro::tail -> "Pro " ^ (string_of_protein tail)
	| Ser::tail -> "Ser " ^ (string_of_protein tail)
	| Thr::tail -> "Thr " ^ (string_of_protein tail)
	| Trp::tail -> "Trp " ^ (string_of_protein tail)
	| Tyr::tail -> "Tyr " ^ (string_of_protein tail)
	| Val::tail -> "Val " ^ (string_of_protein tail)
	| [] -> ""

let decode_arn (arn:rna) : protein =
	let rec decode_arn_from_triplets triplets =
		match triplets with
	| (U,A,A)::(U,A,G)::(U,G,A)::tail -> []
	| (G,C,A)::(G,C,C)::(G,C,G)::(G,C,U)::tail -> Ala::(decode_arn_from_triplets tail)
	| (A,G,A)::(A,G,G)::(C,G,A)::(C,G,C)::(C,G,G)::(C,G,U)::tail -> Arg::(decode_arn_from_triplets tail)
	| (A,A,C)::(A,A,U)::tail -> Asn::(decode_arn_from_triplets tail)
	| (G,A,C)::(G,A,U)::tail -> Asp::(decode_arn_from_triplets tail)
	| (U,G,C)::(U,G,U)::tail -> Cys::(decode_arn_from_triplets tail)
	| (C,A,A)::(C,A,G)::tail -> Gln::(decode_arn_from_triplets tail)
	| (G,A,A)::(G,A,G)::tail -> Glu::(decode_arn_from_triplets tail)
	| (G,G,A)::(G,G,C)::(G,G,G)::(G,G,U)::tail -> Gly::(decode_arn_from_triplets tail)
	| (C,A,C)::(C,A,U)::tail -> His::(decode_arn_from_triplets tail)
	| (A,U,A)::(A,U,C)::(A,U,U)::tail -> Ile::(decode_arn_from_triplets tail)
	| (C,U,A)::(C,U,C)::(C,U,G)::(C,U,U)::(U,U,A)::(U,U,G)::tail -> Leu::(decode_arn_from_triplets tail)
	| (A,A,A)::(A,A,G)::tail -> Lys::(decode_arn_from_triplets tail)
	| (A,U,G)::tail -> Met::(decode_arn_from_triplets tail)
	| (U,U,C)::(U,U,U)::tail -> Phe::(decode_arn_from_triplets tail)
	| (C,C,C)::(C,C,A)::(C,C,G)::(C,C,U)::tail -> Pro::(decode_arn_from_triplets tail)
	| (U,C,A)::(U,C,C)::(U,C,G)::(U,C,U)::(A,G,U)::(A,G,C)::tail -> Ser::(decode_arn_from_triplets tail)
	| (A,C,A)::(A,C,C)::(A,C,G)::(A,C,U)::tail -> Thr::(decode_arn_from_triplets tail)
	| (U,G,G)::tail -> Trp::(decode_arn_from_triplets tail)
	| (U,A,C)::(U,A,U)::tail -> Tyr::(decode_arn_from_triplets tail)
	| (G,U,A)::(G,U,C)::(G,U,G)::(G,U,U)::tail -> Val::(decode_arn_from_triplets tail)
	| head::tail -> decode_arn_from_triplets tail
	| [] -> []
	in
		decode_arn_from_triplets (generate_bases_triplets arn)

let life str =
	let rec print_rna rna = match rna with
		| head::tail when head = A -> print_string "A" ; print_rna tail
		| head::tail when head = T -> print_string "T" ; print_rna tail
		| head::tail when head = C -> print_string "C" ; print_rna tail
		| head::tail when head = G -> print_string "G" ; print_rna tail
		| head::tail when head = U -> print_string "U" ; print_rna tail
		| head::tail when head = None -> print_string "None " ; print_rna tail
		| _ -> print_char '\n' in
	let helix_1 = generate_helix 3000 in
	print_endline "First helix : ";
	print_endline (helix_to_string helix_1);
	let helix_2 = complementary_helix helix_1 in
	print_endline "Second helix : ";
	print_endline (helix_to_string helix_2);

	let rna_1 = generate_rna helix_1 in
	print_endline "First rna : ";
	print_rna rna_1 ;

	let rna_2 = generate_rna helix_2 in
	print_endline "Second rna : ";
	print_rna rna_2 ;

	let proteins_1 = decode_arn rna_1 in
	print_endline "First protein : ";
	print_endline (string_of_protein proteins_1);

	let proteins_2 = decode_arn rna_2 in
	print_endline "Second protein : ";
	print_endline (string_of_protein proteins_2)

let main () =
	Random.self_init(); (* Note : Le main doit initialiser le moteur de random. C'aurait pu etre le generate_helix mais le seed aurait ete reset a chaque appel. C'est un choix d'implementation. *)
	life " "

let () = main ()
