let rec ft_tak x y z =
    if y < x then
        ft_tak (ft_tak (x - 1) y z) (ft_tak (y - 1) z x) (ft_tak (z - 1) x y)
    else
        z

let () =
    print_string "Test with 1 2 3: " ;
    print_int (ft_tak 1 2 3) ;
    print_char '\n' ;
    print_string "Test with 5 23 7: " ;
    print_int (ft_tak 5 23 7) ;
    print_char '\n' ;
    print_string "Test with 9 1 0: " ;
    print_int (ft_tak 9 1 0) ;
    print_char '\n' ;
    print_string "Test with 1 1 1: " ;
    print_int (ft_tak 1 1 1) ;
    print_char '\n' ;
    print_string "Test with 0 42 0: " ;
    print_int (ft_tak 0 42 0) ;
    print_char '\n' ;
    print_string "Test with 23498 98734 98776: " ;
    print_int (ft_tak 23498 98734 98776) ;
    print_char '\n' 
