let ft_rot_n n str = 
	let number = n in
		let ft_rot_n_func c =
			let number_of_letters_in_alphabet = int_of_char 'z' - int_of_char 'a' in
			if (int_of_char c) >= (int_of_char 'a') && (int_of_char c) <= (int_of_char 'z') then
				char_of_int (((int_of_char c) - (int_of_char 'a') + number) mod (number_of_letters_in_alphabet + 1) + (int_of_char 'a'))
			else if (int_of_char c) >= (int_of_char 'A') && (int_of_char c) <= (int_of_char 'Z') then
				char_of_int (((int_of_char c) - (int_of_char 'A') + number) mod (number_of_letters_in_alphabet + 1) + (int_of_char 'A'))
			else
				c
		in
			String.map ft_rot_n_func str

let main () = 
	print_endline (ft_rot_n 42 "123456789") ;
	print_endline (ft_rot_n 0 "abcdefghijklmnopqrstuvwxyz");
	print_endline (ft_rot_n 1 "abcdefghijklmnopqrstuvwxyz");
	print_endline (ft_rot_n 2 "abcdefghijklmnopqrstuvwxyz") ;
	print_endline (ft_rot_n 2 "OI2EAS67B9") ;
	print_endline (ft_rot_n 0 "Damned !") ;
	print_endline (ft_rot_n 1 "NBzlk qnbjr !") ;
	print_endline (ft_rot_n 27 "NBzlk qnbjr !") ;
	print_endline (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz")

let () = main ()
