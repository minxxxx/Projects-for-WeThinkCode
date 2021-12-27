(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   helix.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 18:47:00 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/17 19:36:52 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
type nucleotide = phosphate * deoxyribose * nucleobase

let generate_nucleotide base:nucleotide =
	match base with
	| 'A' -> "phosphate", "deoxyribose", A
	| 'T' -> "phosphate", "deoxyribose", T
	| 'C' -> "phosphate", "deoxyribose", C
	| 'G' -> "phosphate", "deoxyribose", G
	| _ -> "phosphate", "deoxyribose", None

type helix = nucleotide list

let get_nucleobase = function
	| 0 -> 'A'
	| 1 -> 'T'
	| 2 -> 'C'
	| 3 -> 'G'
	| _ -> '0'

let base_str = function
	| A -> "A"
	| T -> "T"
	| C -> "C"
	| G -> "G"
	| None -> "None"

let complementary_base = function
	| A -> T
	| T -> A
	| C -> G
	| G -> C
	| None -> None

let nucleotide_str ((p, d, b):nucleotide) =
	p ^ " - " ^ d ^ " - " ^ (base_str b) ^ " <=> " ^
	(base_str (complementary_base b)) ^
	" - " ^ d ^ " - " ^ p

let generate_helix n =
	let rec rand_helix n (helix:helix) =
		match n with
		| n when n <= 0 -> helix
		| _ ->
			rand_helix (n - 1) (generate_nucleotide (get_nucleobase (Random.int 3)) :: helix)
	in
	rand_helix n []

let helix_to_string (h:helix) =
	let rec helix_str str h =
		match h with
		| [] -> str
		| head::sec::tail -> helix_str (str ^ (nucleotide_str head) ^ ", ") (sec::tail)
		| head::tail -> helix_str (str ^ (nucleotide_str head)) tail
	in
	helix_str "" h

let rec complementary_helix (h:helix) :helix =
	match h with
	| [] -> []
	| (p, d, b)::tail ->
		(p, d, (complementary_base b)) :: complementary_helix tail

(*
** Test
*)
let test n =
	let h = generate_helix n in
	let comp = complementary_helix h in
	print_string "Test with ["; print_int n; print_string "]\n";
	print_string (helix_to_string h); print_char '\n';
	print_string (helix_to_string comp); print_char '\n'

let () =
	Random.self_init ();
	test 2;
	test 3;
	test 4;
	test 5;
