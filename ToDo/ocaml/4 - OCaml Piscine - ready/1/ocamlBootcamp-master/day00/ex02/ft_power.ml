(*
 * function that takes 1st para
 * to the power of the 2nd para
 * and returns an int
 *)
let rec ft_power x y =
    if (y < 1) then
    begin
        1
    end
    else
    begin
        x * ft_power x (y - 1)
    end
 
let main() = 
    print_endline "Test with [11] [2]" ;
    print_int (ft_power 11 2) ;
    print_char '\n' ;
    print_endline "Test with [0] [9]" ;
    print_int (ft_power 0 9) ;
    print_char '\n';
    print_endline "Test with [7] [4]" ;
    print_int (ft_power 7 4) ;
    print_char '\n' ;
    print_endline "Test with [4] [0]" ;
    print_int (ft_power 4 0) ;
    print_char '\n'
let () = main()
