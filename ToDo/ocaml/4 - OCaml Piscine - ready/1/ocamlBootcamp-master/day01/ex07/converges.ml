let rec ft_converges func x n =
    if n < 0 then
        false
    else if n = 0  && x = func x then
        true
    else
        ft_converges func (func x) (n - 1)
let () =
    print_string "Testing with [2] [5]: " ;
    print_string (string_of_bool(ft_converges (( * ) 2) 2 5)) ;
    print_char '\n' ;
    print_string "Testing with [2] [3]: " ;
    print_string (string_of_bool(ft_converges (fun x -> x / 2) 2 3)) ;
    print_char '\n' ;
    print_string "Testing with [2] [2]: " ;
    print_string (string_of_bool(ft_converges (fun x -> x / 2) 2 2)) ;
    print_char '\n' 
