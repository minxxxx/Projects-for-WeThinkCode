type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
type nucleotide = {
    a : phosphate;
    b : deoxyribose;
    c : nucleobase
}
type helix = nucleotide list
type generateHelix = int -> helix

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
                    | None -> "None " ^ (helix_to_string next)

let  complementary_helix elem =
    match elem.c with
    | A -> { a = "phosphate"; b = "deoxyribose"; c = T};
    | T -> { a = "phosphate"; b = "deoxyribose"; c = A}
    | C -> { a = "phosphate"; b = "deoxyribose"; c = G}
    | G -> { a = "phosphate"; b = "deoxyribose"; c = C}
    | None -> elem

let () =
    print_endline (helix_to_string (generate_helix 3));
    print_endline (helix_to_string (generate_helix 0));
    print_endline (helix_to_string (generate_helix 9));
    print_endline (helix_to_string (generate_helix (-1)));
    print_endline (helix_to_string (generate_helix 15));
    let lHelix = generate_helix 5 
    in let rec getComplementary l = match l with
        | [] -> []
        | elem::next -> (complementary_helix elem)::(getComplementary next)
     in let cHelix = getComplementary lHelix
     in (fun listA listB ->
         print_string (helix_to_string listA) ; print_string " -> " ;
         print_endline (helix_to_string listB)) lHelix cHelix


