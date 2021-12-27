let ft_print_comb =
    let rec loop a b c =
        if a == 7 && b == 8 && c == 9 then
            print_string "789\n"
        else
            begin
                if a < b && b < c then
                    begin
                        print_int a ; print_int b ; print_int c ;
                        print_string ", " ;
                        if c == 9 then
                            loop a (b + 1) 0
                        else
                            loop a b (c + 1)
                    end
                else
                    begin
                        if a > b then
                            loop a (a + 1) (a + 2)
                        else
                            begin
                                if b == 9 then
                                    loop (a + 1) 0 0
                                else
                                    loop a b (b + 1)
                            end
                    end
            end
    in loop 0 1 2

let () =
    ft_print_comb

