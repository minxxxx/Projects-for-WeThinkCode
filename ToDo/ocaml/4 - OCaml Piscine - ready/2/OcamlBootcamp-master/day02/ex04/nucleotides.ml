type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
type nucleotide = {
    a : phosphate;
    b : deoxyribose;
    c : nucleobase
}

let printNucleotide elem =
    print_string (elem.a ^ " ");
    print_string (elem.b ^ " ");
    match elem.c with
    | A -> print_endline "A"
    | T -> print_endline "T"
    | C -> print_endline "C"
    | G -> print_endline "G"
    | _ -> print_endline "None"

let generate_nuleotide c = match c with
    | 'A' -> { a = "phosphate"; b = "deoxyribose"; c = A}
    | 'T' -> { a = "phosphate"; b = "deoxyribose"; c = T}
    | 'C' -> { a = "phosphate"; b = "deoxyribose"; c = C}
    | 'G' -> { a = "phosphate"; b = "deoxyribose"; c = G}
    | _ -> { a = "phosphate"; b = "deoxyribose"; c = None}

let () =
    printNucleotide (generate_nuleotide 'A');
    printNucleotide (generate_nuleotide 'G');
    printNucleotide (generate_nuleotide '+');
    printNucleotide (generate_nuleotide 'T');
    printNucleotide (generate_nuleotide 'a')

