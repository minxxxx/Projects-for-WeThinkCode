let ft_print_rev str = 
    let rec loop rev index = 
        if index >= 0 then
            begin
                print_char (String.get rev index) ;
                loop rev (index - 1)
            end
        else
            print_char '\n'
    in loop str ((String.length str) - 1)

let () =
    ft_print_rev "Hello world !" ;
    ft_print_rev ""
