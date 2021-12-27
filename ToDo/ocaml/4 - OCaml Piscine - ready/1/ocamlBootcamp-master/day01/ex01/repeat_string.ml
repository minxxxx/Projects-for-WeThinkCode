let rec ft_repeat_string ?str:(s="x") num = 
    if (num < 0) then
        "Error"
    else if (num = 0) then
        ""
    else
        s ^ ft_repeat_string ~str:s (num - 1) (*^ means concatenation*)
let () = 
    print_endline (ft_repeat_string ~str:"reuben" 3) ;
    print_endline (ft_repeat_string 20);
    print_endline (ft_repeat_string 0);
    print_endline (ft_repeat_string (-10))
