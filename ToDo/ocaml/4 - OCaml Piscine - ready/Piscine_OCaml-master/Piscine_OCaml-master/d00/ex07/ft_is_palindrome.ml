let ft_is_palindrome str = 
	let rec ft_is_palindrome_rec str i j =
		if i >= j then
			true
		else if (String.get str i) <> (String.get str j) then
			false
		else
			ft_is_palindrome_rec str (i + 1) (j - 1)
	in
		ft_is_palindrome_rec str 0 (String.length str - 1)

let main () = 
	print_endline (string_of_bool(ft_is_palindrome "123")) ; 
	print_endline (string_of_bool(ft_is_palindrome "123q")) ;
	print_endline (string_of_bool(ft_is_palindrome "ergennegre"));
	print_endline (string_of_bool(ft_is_palindrome "emucedessinreveilpartnattercesecrettantraplievernissedecume")) ;
	print_endline (string_of_bool(ft_is_palindrome "kayak")) ;
	print_endline (string_of_bool(ft_is_palindrome "laval")) ;
	print_endline (string_of_bool(ft_is_palindrome "lava")) ;
	print_endline (string_of_bool(ft_is_palindrome "l"))

let () = main ()
