let fibonacci n =
    let rec loop num a b =
        if num < 0 then
            -1
        else if num == 0 then
            a
        else if num == 1 then
            b
        else
            loop (num - 1) b (a + b)
    in loop n 0 1        
       
let () =
    print_endline (string_of_int (fibonacci (-42)));
    print_endline (string_of_int (fibonacci 1));
    print_endline (string_of_int (fibonacci 3));
    print_endline (string_of_int (fibonacci 6))
