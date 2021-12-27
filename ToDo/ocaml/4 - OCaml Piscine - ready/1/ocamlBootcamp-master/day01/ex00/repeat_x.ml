let rec ft_repeat_x num = 
    if (num < 0) then
        "Error"
    else if (num == 0) then
        ""
    else
        "x" ^ ft_repeat_x (num - 1) (*^ means concatenation*)
let () = 
    print_endline (ft_repeat_x 3) ;
    print_endline (ft_repeat_x 20)
