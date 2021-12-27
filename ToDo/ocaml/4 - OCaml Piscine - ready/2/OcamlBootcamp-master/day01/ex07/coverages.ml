let rec converges f x n =
    if (f x) == x then
        true
    else if n < 1 then
        false
    else
        converges f (f x) (n - 1)
 
let () =
    print_endline (string_of_bool (converges (( * ) 2) 2 5));
    print_endline (string_of_bool (converges (fun x -> x / 2) 2 3));
    print_endline (string_of_bool (converges (fun x -> x / 2) 2 2));
    print_endline (string_of_bool (converges (fun x -> x / 2) 2 0));
    print_endline (string_of_bool (converges (( * ) 2) 2 (-1)));
    print_endline (string_of_bool (converges (( * ) 2) 4 5))
