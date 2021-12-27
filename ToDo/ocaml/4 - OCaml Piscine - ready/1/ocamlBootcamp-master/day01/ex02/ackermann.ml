let rec ft_ackermann m n = 
    if (m = 0) then
        n + 1
    else if (m > 0 && n = 0) then
        ft_ackermann (m - 1) 1
    else if (m > 0 && n > 0) then
        ft_ackermann (m - 1) (ft_ackermann m (n - 1))
    else
        (-1)
let () =
    print_string ("Test with [-1] [7]: ");
    print_int (ft_ackermann (-1) 7);
    print_char '\n';
    print_string ("Test with [0] [0]: ");
    print_int (ft_ackermann 0 0);
    print_char '\n';
    print_string ("Test with [2] [3]: ");
    print_int (ft_ackermann 2 3);
    print_char '\n';
    print_string ("Test with [4] [1]: ");
    print_int (ft_ackermann 4 1);
    print_char '\n'
