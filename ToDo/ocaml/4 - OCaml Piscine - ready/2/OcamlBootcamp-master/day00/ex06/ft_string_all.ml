let is_digit c = 
    c >= '0' && c <= '9'

let ft_string_all func1 str =
    let rec loop func rev index =
        if index < 0 then
            true
        else
            begin
                if func (String.get rev index) == true then
                    loop func rev (index - 1)
                else
                    false
            end
    in loop func1 str ((String.length str) - 1)

let () =
    print_endline (string_of_bool (ft_string_all is_digit "0123456789")) ;
    print_endline (string_of_bool (ft_string_all is_digit "O12EAS67B9"))
