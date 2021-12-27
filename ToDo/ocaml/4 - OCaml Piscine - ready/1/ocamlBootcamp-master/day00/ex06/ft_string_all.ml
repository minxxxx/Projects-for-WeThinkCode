let ft_string_all ft_func word =
    let word_length = String.length word in
    if word_length >= 0 then
        begin
            let rec ft_check_char ft_func word index = 
                if index >= 0 && true = ft_func (String.get word index) then
                    ft_check_char ft_func word (index - 1)
                else if index <= 0 then
                    true
                else
                    false
            in
            ft_check_char ft_func word (word_length - 1)
        end
     else
         false

let ft_isdigit c = c >= '0' && c <= '9'
let ft_isalpha c = c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'

let main() = 
    print_string "test ft_string_all with ft_isdigit [0123456789]: " ;
    print_endline (string_of_bool(ft_string_all ft_isdigit "0123456789")) ;
    print_string "test ft_string_all with ft_isdigit [0AA23456789]: " ;
    print_endline (string_of_bool(ft_string_all ft_isdigit "0AA23456789")) ;
    print_string "test ft_string_all with ft_isalpha [adjlDlsjf]: " ;
    print_endline (string_of_bool(ft_string_all ft_isalpha "adjlDlsjf")) ;
    print_string "test ft_string_all with ft_isalpha [adj1Dlsjf]: " ;
    print_endline (string_of_bool(ft_string_all ft_isalpha "adj1Dlsjf"))

let () = main()

