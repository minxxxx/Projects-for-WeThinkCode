let ft_print_comb () =
	let rec print_params d1 d2 d3 =
		if not (d1 = 0 && d2 = 1 && d3 = 2) then
			print_string ", ";
		print_int d1 ;
		print_int d2 ;
		print_int d3 ;
		if (d3 <> 9) then
			print_params d1 d2 (d3 + 1)
		else if (d2 + 2 < 10) then
			print_params d1 (d2 + 1) (d2 + 2)
		else if (d1 + 3 < 10) then
			print_params (d1 + 1) (d1 + 2) (d1 + 3)
	in
		print_params 0 1 2 ;
        print_string "\n"

let main () = 
	ft_print_comb ()

let () = main ()
