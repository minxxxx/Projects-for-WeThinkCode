let fibonacci n =
	let rec fibo_loop i prev1 prev2 =
		if i = n then
			prev1 + prev2 (* condition d'arret *)
		else if i = 0 then
			(fibo_loop 1 0 0) (* on appelle 1 avec prev1 = 0 et prev2 = 0 *)
		else if (i = 1) then
			(fibo_loop 2 1 0) (* on appelle 2 avec prev1 = 1 et prev2 = 0 *)
		else
			(fibo_loop (i + 1) (prev2 + prev1) prev1) (* on appelle n + 1 avec prev1 = prev2 + prev1, et prev2 = prev1 *)
	in
		if n < 0 then
			(-1)
		else
			fibo_loop 0 0 0


let main () =
	print_endline "hello, world!";
	print_int (fibonacci 1);
	print_char '\n';
	print_int (fibonacci 6);
	print_char '\n';
	print_int (fibonacci (-1));
	print_char '\n';
	print_int (fibonacci 2);
	print_char '\n';
	print_int (fibonacci 65);
	print_char '\n'




let () = main ()
