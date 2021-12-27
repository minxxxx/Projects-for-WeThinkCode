let rec addToTupleList element tupleList =
    match tupleList with
    | [] -> [(1, element)]
    | (count, elem)::next -> if elem == element then
                                let rec loop nlist = match nlist with
                                    | [] -> []
                                    | (a, b)::tail -> (a, b)::(loop tail) in
                                    (count + 1, elem)::(loop next)
                            else (count, elem)::(addToTupleList element next)

let rec printTupleList mlist =
    match mlist with
    | [] -> print_endline "------"
    | (count, element)::next -> 
            (fun x y -> print_int x;
                        print_char y; 
                        print_char '\n') count element;
             printTupleList next

let rec printTupleListInt mlist =
    match mlist with
    | [] -> print_endline "------";
    | (count, element)::next -> 
            (fun x y -> print_int x;
                        print_char ':';
                        print_int y; 
                        print_char '\n') count element;
             printTupleListInt next

let encode mlist =
    let nlist = [] in
    let rec loop vlist tupList =
        match vlist with
        | [] -> tupList
        | elem::next -> loop next (addToTupleList elem tupList)
    in loop mlist nlist

let () =
    printTupleList (encode ['a';'a';'a';'b';'b';'f';'s';'z';'a';'f';'z']);
    printTupleList (encode ['-';'a';'+';'b';'b';'f';'s';'z';'a';'+';'z']);
    printTupleListInt (encode [1;2;2;2;4;5;1;4;1;4;10])

