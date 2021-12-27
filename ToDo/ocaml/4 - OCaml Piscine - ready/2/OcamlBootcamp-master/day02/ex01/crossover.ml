let rec elementInList element mList =
    match mList with
    | [] -> false
    | elem::next -> if elem = element  then true else elementInList element next

let rec printList nList =
    match nList with
    | [] -> print_char '\n'
    | elem::next -> print_char elem; print_string ", "; printList next

let rec printListInt nList =
    match nList with
    | [] -> print_char '\n'
    | elem::next -> print_int elem; print_string ", "; printListInt next

let rec printListFloat nList =
    match nList with
    | [] -> print_char '\n'
    | elem::next -> print_float elem; print_string ", "; printListFloat next

let crossover listA listB =
    let rec loopListA  aList =
        match aList with
        | [] -> []
        | elem::next -> 
                if ((elementInList elem listB) == true) then
                    elem::(loopListA next)
                else
                    loopListA next
    in loopListA listA 
let () =
    printList (crossover ['a';'b';'c';'d';'e'] ['a';'b';'c';'d';'e']);
    printList (crossover [] ['a';'b';'c';'d';'e']);
    printList (crossover ['a';'b';'c';'d';'e'] []);
    printList (crossover ['a';'b';'c';'d';'e'] ['f';'g';'h';'i';'j']);
    printList (crossover ['a';'b';'c';'d';'e'] ['x';'b';'g';'p';'e';'a']);
    printListInt (crossover [1;4;5;6;10;12;56] [56;5;3;9;8]);
    printListFloat (crossover [2.5;3.0;3.5;4.0;4.5;5.5] [3.4;3.5;4.5])

