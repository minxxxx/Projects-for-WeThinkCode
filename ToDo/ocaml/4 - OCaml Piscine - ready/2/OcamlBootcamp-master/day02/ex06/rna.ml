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

let test lHelix =
    print_string ((helix_to_string lHelix) ^ " - > ");
    let lRna = generate_rna lHelix
    in let rec printRna elems =
        match elems with
        | [] -> print_string "\n"
        | head::next -> match head with
                        | A -> print_string "A "; printRna next
                        | U -> print_string "U "; printRna next
                        | C -> print_string "C "; printRna next
                        | G -> print_string "G "; printRna next
                        | _ -> print_string "None "; printRna next
    in printRna lRna
                    
let () =
    test (generate_helix 5);
    test (generate_helix 3);
    test (generate_helix 10);
    test (generate_helix 0);

