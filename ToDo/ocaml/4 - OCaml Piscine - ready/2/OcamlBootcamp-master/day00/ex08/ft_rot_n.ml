let ft_rot_n n str =
    let rot_n = n mod 26 in
    let int_of_a = int_of_char 'a' in
    let int_of_A = int_of_char 'A' in
    let rot_char c = 
        if (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') then
            begin
                if c >= 'A' && c <= 'Z' then
                    char_of_int (((((int_of_char c) - int_of_A) + rot_n) mod 26) + int_of_A)
                else
                    char_of_int (((((int_of_char c) - int_of_a) + rot_n) mod 26) + int_of_a)
            end
        else
            c
    in String.map rot_char str

let () =
    print_endline (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz") ;
    print_endline (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz") ;
    print_endline (ft_rot_n 42 "0123456789") ;
    print_endline (ft_rot_n 2 "OI2EAS67B9") ;
    print_endline (ft_rot_n 0 "Damned !") ;
    print_endline (ft_rot_n 42 "") ;
    print_endline (ft_rot_n 1 "NBzlk qnbjr !")
