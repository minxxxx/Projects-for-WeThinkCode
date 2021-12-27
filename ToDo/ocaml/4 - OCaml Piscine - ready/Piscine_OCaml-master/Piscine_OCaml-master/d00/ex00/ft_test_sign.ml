let ft_test_sign param = 
    if param >= 0 then
        print_endline "positive"
    else
        print_endline "negative"


let main () = 
    ft_test_sign 2 ;
    ft_test_sign 5 ;
    ft_test_sign (-9) ;
    ft_test_sign 0

let () = main ()