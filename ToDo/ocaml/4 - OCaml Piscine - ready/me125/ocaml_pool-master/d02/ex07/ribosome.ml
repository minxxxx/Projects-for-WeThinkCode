(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ribosome.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 20:04:32 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/18 19:57:31 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
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
	| U -> "U"
	| None -> "None"

let complementary_base = function
	| A -> T
	| T -> A
	| C -> G
	| G -> C
	| _ -> None

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

type rna = nucleobase list

let rna_base = function
	| A -> U
	| T -> A
	| C -> G
	| G -> C
	| _ -> None

let rec generate_rna (h:helix) :rna =
	match h with
	| [] -> []
	| (_, _, b)::tail -> (rna_base b) :: generate_rna tail

let rec generate_bases_triplets (r:rna) =
	match r with
	| a::b::c::tail -> (a, b, c) :: generate_bases_triplets tail
	| _ -> []

type aminoacid = Stop | Ala | Arg | Asn | Asp | Cys | Gln | Glu | Gly | His | Ile | Leu | Lys | Met | Phe | Pro | Ser | Thr | Trp | Tyr | Val
type protein = aminoacid list

let string_of_aminoacid = function
	| Stop				-> "End of translation"
	| Ala				-> "Alanine"
	| Arg				-> "Arginine"
	| Asn				-> "Asparagine"
	| Asp				-> "Aspartique"
	| Cys				-> "Cysteine"
	| Gln				-> "Glutamine"
	| Glu				-> "Glutamique"
	| Gly				-> "Glycine"
	| His				-> "Histidine"
	| Ile				-> "Isoleucine"
	| Leu				-> "Leucine"
	| Lys				-> "Lysine"
	| Met				-> "Methionine"
	| Phe				-> "Phenylalanine"
	| Pro				-> "Proline"
	| Ser				-> "Serine"
	| Thr				-> "Threonine"
	| Trp				-> "Tryptophane"
	| Tyr				-> "Tyrosine"
	| Val				-> "Valine"

let rec string_of_protein(p:protein) =
	match p with
	| []				-> ""
	| head::sec::tail	->
		(string_of_aminoacid head) ^ ", " ^ (string_of_protein (sec::tail))
	| head::tail		->
		(string_of_aminoacid head) ^ (string_of_protein tail)

let decode_triplet = function
	| G, C, A | G, C, C | G, C, G | G, C, U						-> Ala
	| A, G, A | A, G, G | C, G, A | C, G, C | C, G, G | C, G, U	-> Arg
	| A, A, C | A, A, U											-> Asn
	| G, A, C | G, A, U											-> Asp
	| U, G, C | U, G, U											-> Cys
	| C, A, A | C, A, G											-> Gln
	| G, A, A | G, A, G											-> Glu
	| G, G, A | G, G, C | G, G, G | G, G, U						-> Gly
	| C, A, C | C, A, U											-> His
	| A, U, A | A, U, C | A, U, U								-> Ile
	| C, U, A | C, U, C | C, U, G | C, U, U | U, U, A | U, U, G	-> Leu
	| A, A, A | A, A, G											-> Lys
	| A, U, G													-> Met
	| U, U, C | U, U, U											-> Phe
	| C, C, C | C, C, A | C, C, G | C, C, U						-> Pro
	| U, C, A | U, C, C | U, C, G | U, C, U | A, G, U | A, G, C	-> Ser
	| A, C, A | A, C, C | A, C, G | A, C, U						-> Thr
	| U, G, G													-> Trp
	| U, A, C | U, A, U											-> Tyr
	| G, U, A | G, U, C | G, U, G | G, U, U						-> Val
	| U, A, A | U, A, G | U, G, A | _							-> Stop

let decode_arn (r:rna) :protein =
	let rec loop = function
		| []											-> []
		| head::tail when (decode_triplet head) = Stop	->
			(decode_triplet head) :: []
		| head::tail									->
			(decode_triplet head) :: (loop tail)
	in
	loop (generate_bases_triplets r)
(*
** Test
*)
let rec print_rna r =
	match r with
	| [] -> print_char '\n'
	| head::tail -> begin
		print_string (base_str head);
		print_rna tail
	end

let rec print_triplet t =
	match t with
	| []					-> print_char '\n'
	| (a, b, c)::sec::tail	->
		print_string (base_str a);
		print_string (base_str b);
		print_string (base_str c);
		print_string ", ";
		print_triplet (sec::tail)
	| (a, b, c)::tail		->
		print_string (base_str a);
		print_string (base_str b);
		print_string (base_str c);
		print_triplet tail


let test n =
	let h = generate_helix n in
	let comp = complementary_helix h in
	let rna = generate_rna h in
	print_string "Test with ["; print_int n; print_string "]\n";
	print_string (helix_to_string h); print_char '\n';
	print_string (helix_to_string comp); print_char '\n';
	print_string "rna: ";
	print_rna rna;
	print_string "tiplets: ";
	print_triplet (generate_bases_triplets rna);
	print_string "protein: ";
	print_string (string_of_protein (decode_arn rna));
	print_char '\n'

let () =
	Random.self_init ();
	test 3;
	test 4;
	test 5;
	test 6;
	test 20;
