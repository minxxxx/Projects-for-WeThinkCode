let rec ft_iter func x n = 
    if n < 0 then
        (-1)
    else if n = 0 then
        x
    else if n = 1 then
        func x
    else
        func (ft_iter func x (n -1))
let () =
    print_string "Testing with [2] and [4]: " ;
    print_int (ft_iter (fun x -> x * x) 2 4) ;
    print_char '\n' ;
    print_string "Testing with [2] and [4]: " ;
    print_int (ft_iter (fun x -> x * 2) 2 4) ;
    print_char '\n' ;
    print_string "Testing with [2] and [-1]: " ;
    print_int (ft_iter (fun x -> x * x) 2 (-1)) ;
    print_char '\n' ;
    print_string "Testing with [3] and [0]: " ;
    print_int (ft_iter (fun x -> x * x) 3 0) ;
    print_char '\n'
