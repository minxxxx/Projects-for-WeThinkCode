type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
type nucleotide = phosphate * deoxyribose * nucleobase

let generate_nucleotide (base) : nucleotide =
	match base with
	| 'A'-> ("phosphate", "deoxyribose", A)
	| 'T'-> ("phosphate", "deoxyribose", T)
	| 'C'-> ("phosphate", "deoxyribose", C)
	| 'G'-> ("phosphate", "deoxyribose", G)
	| _ -> ("phosphate", "deoxyribose", None)

let main () =
	let nucleobase_to_string base = match base with
		| A -> "A"
		| T -> "T"
		| C -> "C"
		| G -> "G"
		| None -> "None"
	in
	let print_nucleotide (nucl:nucleotide) =
		match nucl with
		| (a, b, c) -> print_endline ("phosphate : [" ^ a ^ "] - deoxyribose : [" ^ b ^ "] - nucleobase : " ^ nucleobase_to_string c)
	in
	let example_A = generate_nucleotide 'A' in
	let example_T = generate_nucleotide 'T' in
	let example_C = generate_nucleotide 'C' in
	let example_G = generate_nucleotide 'G' in
	let example_None = generate_nucleotide ' ' in

	print_nucleotide (example_A);
	print_nucleotide (example_T);
	print_nucleotide (example_C);
	print_nucleotide (example_G);
	print_nucleotide (example_None)



let () = main ()
