let ft_print_rev str = 
	let rec loop str pos =
		print_char (String.get str pos) ;
		if pos <> 0 then
			loop str (pos - 1)
	in
		if ((String.length str) - 1) >= 0 then
			loop str ((String.length str) - 1) ;
		print_char '\n'

let main () = 
	ft_print_rev "abcd" ;
	ft_print_rev "a" ;
	ft_print_rev "Hello world !" ;
	ft_print_rev ""

let () = main ()
