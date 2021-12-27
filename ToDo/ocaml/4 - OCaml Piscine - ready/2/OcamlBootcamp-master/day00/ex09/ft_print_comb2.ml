
let ft_print_num a b c d =
    print_int a ; print_int b ; print_char ' ' ;
    print_int c ; print_int d

let ft_print_comb2 () = 
    let rec loop a b c d =
        if a = 9 && b == 8 && c == 9 && d == 9 then
            begin
                ft_print_num a b c d ; print_char '\n'
            end
        else
            begin
                ft_print_num a b c d ; print_char ',' ; print_char ' ' ;
            if d < 9 then
                loop a b c (d + 1)
            else
                begin
                    if c < 9 then
                        loop a b (c + 1) 0
                    else
                        begin
                            if b < 9 then
                                loop a (b + 1) a (b + 2)
                            else
                                loop (a + 1) 0 (a + 2) 1
                        end
                end
            end
    in loop 0 0 0 1

let () =
    ft_print_comb2 ()
