let rec ft_fibonacci n =
    if n < 0 then
        (-1)
    else if n = 0 then
        0
    else if n = 1 then
        1
    else
        ft_fibonacci (n - 2) + ft_fibonacci (n -1)

let () = 
    print_string "Test with [-42]: " ;
    print_int (ft_fibonacci(-42)) ;
    print_char '\n' ;
    print_string "Test fibonacci with [1]: " ;
    print_int (ft_fibonacci 1) ;
    print_char '\n' ;
    print_string "Test fibonacci with [3]: " ;
    print_int (ft_fibonacci 3) ;
    print_char '\n' ;
    print_string "Test fibonacci with [6]: " ;
    print_int (ft_fibonacci 6) ;
    print_char '\n' 
