let ft_print_alphabet () = 
    let rec loop param = 
        print_char param ;
        if param != 'z' then
            loop (char_of_int (int_of_char (param) + 1))
    in
        loop 'a' ;
        print_char '\n'

let main () =
    ft_print_alphabet ()


let () = main ()
