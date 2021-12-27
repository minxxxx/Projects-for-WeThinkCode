let rec repeat_string ?(str="x") n =
    if n < 0 then
        "Error"
    else if n == 0 then
        ""
    else
        str ^ (repeat_string ~str:str (n - 1))

let () =
    print_endline (repeat_string (-1));
    print_endline (repeat_string 0);
    print_endline (repeat_string ~str:"Toto" 1);
    print_endline (repeat_string 2);
    print_endline (repeat_string ~str:"a" 5);
    print_endline (repeat_string ~str:"what" 3);
    print_endline (repeat_string ~str:"To" 15)
