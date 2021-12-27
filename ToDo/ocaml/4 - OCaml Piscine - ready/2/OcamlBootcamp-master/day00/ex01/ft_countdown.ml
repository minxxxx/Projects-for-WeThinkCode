let rec ft_countdown x =
    if x < 1 then
        begin 
            print_int 0 ; print_char '\n'
        end            
    else
        begin
            print_int x ; print_char '\n' ; ft_countdown (x - 1)
        end            

let () =
    ft_countdown 3 ;
    ft_countdown (-1) ;
    ft_countdown 0 ;
    ft_countdown 10
