let is_palindrom letter =
    let rec loop str index c =
        if index > 9 then
            false
        else
            begin
                if c == (String.get str index) then
                    true
                else
                    loop str (index + 1) c
            end
    in loop "palindrome" 0 letter

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

let ft_is_palindrome str = 
    ft_string_all is_palindrom str

let () =
    print_endline (string_of_bool (ft_is_palindrome "radar")) ;
    print_endline (string_of_bool (ft_is_palindrome "madam")) ;
    print_endline (string_of_bool (ft_is_palindrome "car")) ;
    print_endline (string_of_bool (ft_is_palindrome ""))

