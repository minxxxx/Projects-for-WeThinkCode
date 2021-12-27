let ft_print_comb2 () =
	let print_formated_number n = 
		if n < 10 then
			begin
				print_char '0' ;
				print_int n
			end
		else
			print_int n
	in
		let rec loop n1 n2 =
			if (n1 <> 0 || n2 <> 1) then
			begin
				print_char ',' ;
				print_char ' ' ;
			end;

			print_formated_number n1 ;
			print_char ' ' ;
			print_formated_number n2 ;
			if (n2 < 99) then
				loop n1 (n2 + 1)
			else if (n1 + 1 <= 99 && n1 + 2 <= 99) then
				loop (n1 + 1) (n1 + 2)
		in
			loop 0 1 ;
            print_char '\n'

let main () = 
	ft_print_comb2 ()

let () = main ()
