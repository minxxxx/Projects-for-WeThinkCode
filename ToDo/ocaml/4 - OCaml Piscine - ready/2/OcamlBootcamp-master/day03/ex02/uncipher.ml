let ft_rot_n (n : int) (str : string) =
    let rot_n = n mod 26 in
    let int_of_a = int_of_char 'a' in
    let int_of_A = int_of_char 'A' in
    let rot_char c =
        if (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') then
            begin
                if c >= 'A' && c <= 'Z' then
                    char_of_int (((((int_of_char c) - int_of_A) + rot_n) mod 26) + int_of_A)
                else
                    char_of_int (((((int_of_char c) - int_of_a) + rot_n) mod 26) + int_of_a)
            end
        else
            c
    in String.map rot_char str

let unrot42 (str : string) =
    ft_rot_n 10 str

let uncaesar (str : string) (shit : int) =
    ft_rot_n (26 - (shit mod 26)) str

let rec ft_uncrypt (str : string) (ciphers : (string -> string) list) =
    match ciphers with
    | [] -> str
    | func::next -> func (ft_uncrypt str next)

let uncaesar1 (str : string) =
    uncaesar str 3

let uncaesar2 (str : string) =
    uncaesar str 9

let uncaesar3 (str : string) =
    uncaesar str 42

