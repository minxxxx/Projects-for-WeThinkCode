let rec ft_print_alphabet x =
    if x > 96 then
        begin
            if x < 123 then
                begin
                    print_char (char_of_int x) ; ft_print_alphabet (x + 1)
                end
            else
                print_char '\n'
        end
    else
        print_char '\n'

let () = 
    ft_print_alphabet 97 ;
