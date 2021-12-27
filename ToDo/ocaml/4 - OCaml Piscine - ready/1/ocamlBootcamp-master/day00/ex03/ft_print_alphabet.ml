let ft_print_alphabet () =
    let ascii_a = int_of_char 'a' in
    let ascii_z = int_of_char 'z' in
    let rec print_loop ascii_a =
        if ascii_a <= ascii_z then
            let char_to_print = char_of_int ascii_a in
            print_char char_to_print;
            print_loop (ascii_a + 1)
    in print_loop ascii_a;
    print_char '\n'
    
let main() = ft_print_alphabet ()
let () = main()
