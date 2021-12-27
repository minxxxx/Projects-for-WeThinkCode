let ft_print_comb () =
    let first = 0 in
    let second = 1 in
    let third = 2 in
    let rec print_comb first second third =
        if third <= 9 then
            begin
                if first != second && first != third && second != third then
                    print_int first ;
                if first != second && first != third && second != third then
                    print_int second ;
                if first != second && first != third && second != third then
                    print_int third ;
                if first != second && first != third && second != third then
                    print_string ", ";
                    print_comb first second (third + 1)
            end
         else
             begin
                 let third = 0 in
                 if second < 9 then
                     begin
                         print_comb first (second + 1) third
                     end
                  else
                      begin
                          let second = 0 in
                          if first < 9 then
                              print_comb (first + 1) second third
                      end
             end
      in print_comb first second third;
      print_string "\n"

let main() = ft_print_comb()
let () = main()
