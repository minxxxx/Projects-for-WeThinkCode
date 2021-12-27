let rec leibniz_pi delta =
	let pi_reference = 4. *. atan 1. in
		if delta < 0. then -1
		else
			let rec loop i acc =
				let temporary_sum = acc +.
					(-1. ** (float_of_int i))
						/.
					(2. *. (float_of_int i) +. 1.)
				in
					if (4. *. temporary_sum -. pi_reference > 0. && 4. *. temporary_sum -. pi_reference < delta)
					 	|| (pi_reference -. 4. *. temporary_sum > 0. && pi_reference -. 4. *. temporary_sum < delta)
					then
						i
					else
						loop (i + 1) temporary_sum
			in
				loop 0 0.

let main () =
	print_int (leibniz_pi 0.01);
	print_char '\n';
	print_int (leibniz_pi (-1.));
	print_char '\n';
	print_int (leibniz_pi (0.001));
	print_char '\n';
	print_int (leibniz_pi (0.005));
	print_char '\n'

let () = main ()
