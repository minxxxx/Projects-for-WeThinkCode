let ft_test_sign x =
    if x < 0 then
        print_endline "negative"
    else
        print_endline "positive"

let () =
    ft_test_sign 42 ;
    ft_test_sign 0 ;
    ft_test_sign (-42)
