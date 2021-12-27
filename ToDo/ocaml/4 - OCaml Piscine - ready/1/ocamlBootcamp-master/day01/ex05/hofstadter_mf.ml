let rec ft_hfs_f n = 
    if n = 0 then
        1
    else if n > 0 then
        n - ft_hfs_m (ft_hfs_f(n-1))
    else
        (-1)
and ft_hfs_m n =
    if n = 0 then
        0
    else if n > 0 then
        n - ft_hfs_f (ft_hfs_m(n-1))
    else
        (-1)

let () = 
    print_string "test hfs_m with [0]: " ;
    print_int (ft_hfs_m 0) ;
    print_char '\n' ;
    print_string "test hfs_f with [0]: " ;
    print_int (ft_hfs_f 0) ;
    print_char '\n' ;
    print_string "test hfs_m with [-1]: " ;
    print_int (ft_hfs_m (-1)) ;
    print_char '\n' ;
    print_string "test hfs_f with [2]: " ;
    print_int (ft_hfs_f 2) ;
    print_char '\n' ;
    print_string "test hfs_m with [4]: " ;
    print_int (ft_hfs_m 4) ;
    print_char '\n' ;
    print_string "test hfs_f with [4]: " ;
    print_int (ft_hfs_f 4) ;
    print_char '\n' ;
