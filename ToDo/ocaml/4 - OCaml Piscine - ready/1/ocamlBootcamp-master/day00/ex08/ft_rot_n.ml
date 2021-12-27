let ft_rotation_of_char str_char =
    if (str_char < 'a' && str_char < 'A') || (str_char > 'z' && str_char > 'Z') then
        str_char
    else if (str_char = 'Z' || str_char = 'z') then
        char_of_int ((int_of_char str_char) - 25)
    else
        char_of_int ((int_of_char str_char) + 1)

let rec ft_rot_n num str =
    if num > 0 then
        let str1 = String.map ft_rotation_of_char str 
        in ft_rot_n (num -1) str1
    else
        str
        
let () =
	print_endline (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
	print_endline (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz");
    print_endline (ft_rot_n 42 "0123456789");
    print_endline  (ft_rot_n 2 "OI2EAS6789");
    print_endline (ft_rot_n 0 "Damned !");
    print_endline (ft_rot_n 42 "");
    print_endline (ft_rot_n 1 "NBzlk qnbjr !");
    print_endline (ft_rot_n 5 "HelloWorld !")
