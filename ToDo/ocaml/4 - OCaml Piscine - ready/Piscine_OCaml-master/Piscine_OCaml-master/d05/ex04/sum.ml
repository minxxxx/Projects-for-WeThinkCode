let sum n1 n2 = n1 +. n2

let main () =
	print_float (sum 10.1 10.2) ; print_char '\n';
	print_float (sum 1.1234 10.2) ; print_char '\n';
	print_float (sum 1.12345 1.2345) ; print_char '\n';
	print_float (sum 0. 1.2345) ; print_char '\n';
	print_float (sum 0. 0.) ; print_char '\n';
	print_float (sum 0.123456789 0.123456789) ; print_char '\n';
	print_float (sum 0.11111111111111111 0.22222222222222222) ; print_char '\n';
	print_float (sum 0.111113513512632173527613576213567213123111111111111 0.222222222223781232817637821638271632183621387216386721222222) ; print_char '\n'


let () = main ()
