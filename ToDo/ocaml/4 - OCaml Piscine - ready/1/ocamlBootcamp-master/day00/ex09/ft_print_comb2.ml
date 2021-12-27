let ft_print_comb2 () =
    let one_f_comb = 0 in
    let two_f_comb = 0 in
    let one_sec_comb = 0 in
    let two_sec_comb = 1 in
    let rec print_comb one_f_comb two_f_comb one_sec_comb two_sec_comb =
        if two_sec_comb <= 9 then
            begin
                print_int one_f_comb ; 
                print_int two_f_comb ;
                print_string  ", " ;
                print_int one_sec_comb ;
                print_int two_sec_comb ;
                print_string  ", " ;
                print_comb one_f_comb two_f_comb one_sec_comb (two_sec_comb + 1)
            end
        else
            begin
                let two_sec_comb = 0 in
                if one_sec_comb < 9 then
                    print_comb one_f_comb two_f_comb (one_sec_comb + 1) two_sec_comb
                else
                    begin
                        let one_sec_comb = 0 in
                        if two_f_comb < 9 then
                            print_comb one_f_comb (two_f_comb + 1) one_sec_comb
                            two_sec_comb
                        else
                            begin
                                let two_f_comb = 0 in
                                if one_f_comb < 9 then
                                    print_comb (one_f_comb + 1) two_f_comb
                                    one_sec_comb two_sec_comb
                            end
                    end
            end
    in print_comb one_f_comb two_f_comb one_sec_comb two_sec_comb;
    print_char '\n'
let () = ft_print_comb2()
