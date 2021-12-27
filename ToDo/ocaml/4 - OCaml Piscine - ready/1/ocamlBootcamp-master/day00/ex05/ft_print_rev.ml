let ft_print_rev word = 
    let word_length = (String.length word) - 1 in
    let rec print_string word_length =
        if word_length >= 0 then
            begin
                let char_to_print = (String.get word word_length) in
                print_char char_to_print;
                print_string (word_length - 1)
            end
    in print_string word_length;
    print_char '\n'

let main() = ft_print_rev "Hello World!"
let () = main()
