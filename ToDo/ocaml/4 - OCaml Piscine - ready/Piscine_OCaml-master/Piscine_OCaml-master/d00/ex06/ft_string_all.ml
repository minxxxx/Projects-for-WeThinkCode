let is_digit c = c >= '0' && c <= '9'
	
let ft_string_all predicate string = 
	let rec loop predicate string n =
		if n = (String.length string) then
			true
		else if (predicate (String.get string n)) then
			loop predicate string (n + 1)
		else
			false
	in
		loop predicate string 0

let main () = 
	print_endline (string_of_bool (ft_string_all is_digit "12a3"));
	print_endline (string_of_bool (ft_string_all is_digit "123")) ;
	print_endline (string_of_bool (ft_string_all is_digit "a123")) ;
	print_endline (string_of_bool (ft_string_all is_digit "a123")) ;
	print_endline (string_of_bool (ft_string_all is_digit "abc")) ;
	print_endline (string_of_bool (ft_string_all is_digit "")) ;
	print_endline (string_of_bool (ft_string_all is_digit "0123456789")) ;
	print_endline (string_of_bool (ft_string_all is_digit "O12EAS67B9")) 




let () = main ()
