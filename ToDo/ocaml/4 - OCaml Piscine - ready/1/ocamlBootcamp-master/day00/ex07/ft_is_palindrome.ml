let ft_is_palindrome str =
    let str_length = String.length str in
    if str_length > 0 then
        begin
            let sIndex = 0 in
            let eIndex = (str_length - 1) in
            let rec check_palindrome str sChar eChar index sIndex eIndex =
                if (eChar == sChar && index < str_length) then                
                    begin
                        print_string "index: " ;
                        print_int index ;
                        print_char '\n' ;
                        print_string "sIndex: " ;
                        print_int sIndex ;
                        print_char '\n' ;
                        print_string "eIndex: " ;
                        print_int eIndex ;
                        print_char '\n' ;
                        check_palindrome str (String.get str sIndex) (String.get
                        str eIndex) (index + 1)(sIndex + 1)(eIndex - 1)
                    end
                else if index == str_length then
                    true
                else
                    false
            in check_palindrome str (String.get str 0) (String.get str
            str_length) 0 sIndex eIndex
        end
    else
        true
let () = 
    print_string "test with [radar]: " ;
    print_endline (string_of_bool(ft_is_palindrome "hanienah"))
