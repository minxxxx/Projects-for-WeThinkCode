let rot42 (str : string) =
    Uncipher.ft_rot_n 42 str

let caesar (str : string) (shift : int) =
    Uncipher.ft_rot_n shift str

let caesar1 (str : string) =
    caesar str 3

let caesar2 (str : string) =
    caesar str 9

let caesar3 (str : string) =
    caesar str 42

let xor (str : string) (key : int) =
    let xor_c c =
        char_of_int ((int_of_char c) lxor key)
    in String.map xor_c str

let xor1 (str : string) =
    xor str 5

let xor2 (str : string) =
    xor str 15

let xor3 (str : string) =
    xor str 42

let rec ft_crypt (str : string) (ciphers : (string -> string) list) =
    match ciphers with
    | [] -> str
    | func::next -> ft_crypt (func str) next

let test_rot () =
    let str1 = "Hello world !" in
    let rotStr1 = rot42 str1 in
    print_endline ("rot42 -> " ^ rotStr1);
    print_endline ("unrot42 -> " ^ (Uncipher.unrot42 rotStr1))

let test_caesar () =
    let str1 = "The Quick Brown Fox !" in
    let caesarStr1 = caesar str1 3 in
    print_endline ("caesar -> " ^ caesarStr1);
    print_endline ("uncaesar -> " ^ (Uncipher.uncaesar caesarStr1 3))

let test_xor () =
    let str1 = "42 of life !" in
    let xorStr1 = xor str1 5 in
    print_endline ("xor -> " ^ xorStr1);
    print_endline ("unxor -> " ^ (xor xorStr1 5))

let test_crypt_uncrypt (str : string) encryptFuncs decryptFuncs =
    let encryptedStr = ft_crypt str encryptFuncs in
    print_endline ("Actual String -> " ^ str);
    print_endline ("Encrypted -> " ^ encryptedStr);
    print_endline ("Decrypted -> " ^ (Uncipher.ft_uncrypt encryptedStr decryptFuncs))

let main () =
    test_crypt_uncrypt "42 of Life !" [caesar1] [Uncipher.uncaesar1];
    test_crypt_uncrypt "The Big Brown Fox." [caesar1;caesar2] [Uncipher.uncaesar1;Uncipher.uncaesar2];
    test_crypt_uncrypt "Hahaha + hehehe" [caesar2;xor1;caesar3] 
                        [Uncipher.uncaesar2;xor1;Uncipher.uncaesar3];
    test_crypt_uncrypt "RiDdLe mE tHiS" [xor3;caesar3;xor2]
                        [xor3;Uncipher.uncaesar3;xor2]

let _ = main ()
