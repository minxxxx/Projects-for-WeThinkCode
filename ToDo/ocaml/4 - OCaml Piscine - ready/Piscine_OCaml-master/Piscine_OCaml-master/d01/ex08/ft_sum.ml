let ft_sum f low_bound up_bound =
	let rec loop n acc =
		if n > up_bound then
			acc
		else
			loop (n + 1) (acc +. (f n))
	in
		if up_bound < low_bound then
			nan
		else
			loop low_bound 0.

let main () =
	print_float (ft_sum (fun i -> float_of_int (i * i)) 1 10);
	print_char '\n';
	print_float (ft_sum (fun i -> float_of_int (i + i)) 1 5); (* 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 = 2 + 4 + 6 + 8 + 10 = 30 *)
	print_char '\n';
	print_float (ft_sum float_of_int 1 5); (* 1 + 2 + 3 + 4 + 5 = 15 *)
	print_char '\n'


let () = main ()
