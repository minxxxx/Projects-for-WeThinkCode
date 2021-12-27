type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type nucleotide = {
    a : phosphate;
    b : deoxyribose;
    c : nucleobase
}
type helix = nucleotide list
type rna = nucleobase list
type generateHelix = int -> helix
type generateRNA = helix -> rna
type aminoacid = Ala | Arg | Asn | Asp | Cys | Gln | Glu | Gly | His | Ile | Leu | Lys |
                Met | Phe | Pro | Ser | Thr | Trp | Tyr | Val | Stop
type protein = aminoacid list

let matchTable = [
        (Stop, (U,A,A));(Stop, (U,A,G));(Stop, (U,G,A));
        (Ala, (G,C,A));(Ala, (G,C,C));(Ala, (G,C,G));(Ala, (G,C,U));
        (Arg, (A,G,A));(Arg, (A,G,G));(Arg, (C,G,A));(Arg, (C,G,C));(Arg, (C,G,G));(Arg, (C,G,U));
        (Asn, (A,A,C));(Asn, (A,A,U));
        (Asp, (G,A,C));(Asp, (G,A,U));
        (Cys, (U,G,C));(Cys, (U,G,U));
        (Gln, (C,A,A));(Gln, (C,A,G));
        (Glu, (G,A,A));(Glu, (G,A,G));
        (Gly, (G,G,A));(Gly, (G,G,C));(Gly, (G,G,G));(Gly, (G,G,U));
        (His, (C,A,C));(His, (C,A,U));
        (Ile, (A,U,A));(Ile, (A,U,C));(Ile, (A,U,U));
        (Leu, (C,U,A));(Leu, (C,U,C));(Leu, (C,U,G));(Leu, (C,U,U));(Leu, (U,U,A));(Leu, (U,U,G));
        (Lys, (A,A,A));(Lys, (A,A,G));
        (Met, (A,U,G));
        (Phe, (U,U,C));(Phe, (U,U,U));
        (Pro, (C,C,C));(Pro, (C,C,A));(Pro, (C,C,G));(Pro, (C,C,U));
        (Ser, (U,C,A));(Ser, (U,C,C));(Ser, (U,C,G));(Ser, (U,C,U));(Ser, (A,G,U));(Ser, (A,G,C));
        (Thr, (A,C,A));(Thr, (A,C,C));(Thr, (A,C,G));(Thr, (A,C,U));
        (Trp, (U,G,G));
        (Tyr, (U,A,C));(Tyr, (U,A,U));
        (Val, (G,U,A));(Val, (G,U,C));(Val, (G,U,G));(Val, (G,U,U));
    ]

let rec string_of_protein : (protein -> string) = fun (elem : protein) ->
    match elem with
    | [] -> ""
    | head::next -> match head with
                    | Stop -> "End of translation" ^ (string_of_protein next)
                    | Ala -> "Alanie "  ^ (string_of_protein next)
                    | Arg -> "Arginine "  ^ (string_of_protein next)
                    | Asn -> "Asparagine " ^ (string_of_protein next)
                    | Asp -> "Aspartique "  ^ (string_of_protein next)
                    | Cys -> "Cysteine "  ^ (string_of_protein next)
                    | Gln -> "Glutamine "  ^ (string_of_protein next)
                    | Glu -> "Glutamique " ^ (string_of_protein next)
                    | Gly -> "Glycine "  ^ (string_of_protein next)
                    | His -> "Histidine "  ^ (string_of_protein next)
                    | Ile -> "Isoleucine "  ^ (string_of_protein next)
                    | Leu -> "Leucine " ^ (string_of_protein next)
                    | Lys -> "Lysine "  ^ (string_of_protein next)
                    | Met -> "Methionine "  ^ (string_of_protein next)
                    | Phe -> "Phenylalanine "  ^ (string_of_protein next)
                    | Pro -> "Proline "  ^ (string_of_protein next)
                    | Ser -> "Serine "  ^ (string_of_protein next)
                    | Thr -> "Threonine "  ^ (string_of_protein next)
                    | Trp -> "Tryptophane " ^ (string_of_protein next)
                    | Tyr -> "Tyrosine "  ^ (string_of_protein next)
                    | Val -> "Valine " ^ (string_of_protein next)

let generate_helix : generateHelix = fun i ->
    Random.self_init ();
    let rec loop n r =
        if n < 1 then
            []
        else
            begin
                match r with
                | 0 -> { a = "phosphate";
                        b = "deoxyribose"; 
                        c = A}::(loop (n -1) (Random.int 4))
                | 1 -> { a = "phosphate";
                        b = "deoxyribose"; 
                        c = T}::(loop (n -1) (Random.int 4))
                | 2 -> { a = "phosphate";
                        b = "deoxyribose"; 
                        c = C}::(loop (n -1) (Random.int 4))
                | 3 -> { a = "phosphate";
                        b = "deoxyribose"; 
                        c = G}::(loop (n -1) (Random.int 4))
                | _ -> { a = "phosphate";
                        b = "deoxyribose"; 
                        c = None}::(loop (n -1) (Random.int 4))
            end
        in loop i (Random.int 4)

let rec helix_to_string lHelix =
    match lHelix with
    | [] -> ""
    | head::next -> match head.c with
                    | A -> "A " ^ (helix_to_string next)
                    | T -> "T " ^ (helix_to_string next)
                    | C -> "C " ^ (helix_to_string next)
                    | G -> "G " ^ (helix_to_string next)
                    | _ -> "None " ^ (helix_to_string next)

let  complementary_helix elem =
    match elem.c with
    | A -> { a = "phosphate"; b = "deoxyribose"; c = T};
    | T -> { a = "phosphate"; b = "deoxyribose"; c = A}
    | C -> { a = "phosphate"; b = "deoxyribose"; c = G}
    | G -> { a = "phosphate"; b = "deoxyribose"; c = C}
    | _ -> elem

let rec generate_rna : generateRNA = fun (elems : helix) ->
    match elems with
    | [] -> []
    | head::next -> match head.c with
                    | A -> U::(generate_rna next)
                    | T -> A::(generate_rna next)
                    | C -> G::(generate_rna next)
                    | G -> C::(generate_rna next)
                    | _ -> None::(generate_rna next)

let nucleobase_to_string base =
    match base with
    | A -> "A "
    | T -> "T "
    | U -> "U "
    | C -> "C "
    | G -> "G "
    | _ -> "None "

let rec generate_bases_triplets : (rna -> (nucleobase * nucleobase * nucleobase) list) =
    fun (elems : rna) ->
        match elems with
        | first::second::third::next -> (first, second, third)::(generate_bases_triplets next)
        | _ -> []


let rec print_triplets lTriplets =
    match lTriplets with
    | [] -> print_string "]\n"
    | (a, b, c)::next -> print_string 
                        ("(" ^ (nucleobase_to_string a) ^ (nucleobase_to_string b) 
                        ^ (nucleobase_to_string c) ^ ")");
                        print_triplets next

let getAminoAcid : ((nucleobase * nucleobase * nucleobase) -> aminoacid) = fun elem ->
    let rec loop matchList =
        match matchList with
        | [] -> Stop
        | (aminAcid, triplt)::next -> if triplt = elem then
                                         aminAcid
                                      else
                                          loop next
    in loop matchTable

let decode_arn : (rna -> protein) = fun (elem : rna) ->
    let rnaTriplets = generate_bases_triplets elem 
    in let rec decodeTriplets elems =
        match elems with
        | [] -> []
        | head::next -> let amino = getAminoAcid head in
                        match amino with
                        | Stop -> [amino]
                        | _ -> amino::(decodeTriplets next)
    in decodeTriplets rnaTriplets

let test ()  =
    let rna1 = generate_rna (generate_helix 5) in
    let rna2 = generate_rna (generate_helix 3) in
    let rna3 = generate_rna (generate_helix 9) in
    (fun () -> print_string "[" ; print_triplets (generate_bases_triplets rna1); 
               print_string "[" ;print_triplets (generate_bases_triplets rna2); 
               print_string "[" ;print_triplets (generate_bases_triplets rna3)
    ) ()
                        
let test2 () =
    print_endline (string_of_protein (decode_arn (generate_rna (generate_helix 2))));
    print_endline (string_of_protein (decode_arn (generate_rna (generate_helix 5))));
    print_endline (string_of_protein (decode_arn (generate_rna (generate_helix 8))));
    print_endline (string_of_protein (decode_arn (generate_rna (generate_helix 15))));
    print_endline (string_of_protein (decode_arn (generate_rna (generate_helix 25))));
    print_endline (string_of_protein (decode_arn (generate_rna (generate_helix 35))))

let () =
    test2 ();

