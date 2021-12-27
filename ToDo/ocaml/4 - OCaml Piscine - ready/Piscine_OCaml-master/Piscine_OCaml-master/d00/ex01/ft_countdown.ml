let rec ft_countdown param = 
    if param <= 0 then
    begin
        print_char '0' ;
        print_char '\n'
    end
    else
        begin
            print_int param ;
            print_char '\n' ;
            ft_countdown (param - 1)
        end

let main () =
    ft_countdown 3

let () = main ()
