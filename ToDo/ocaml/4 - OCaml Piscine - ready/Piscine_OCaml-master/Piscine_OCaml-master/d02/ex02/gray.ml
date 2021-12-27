let gray n =
	let rec create_str n =
		if (n <= 0) then ""
		else "0" ^ (create_str (n - 1))
	in
	let count_1s str =
		let rec count_1s_loop i =
			if (String.length str) <= i then
				0
			else if String.get str i = '1' then
				1 + count_1s_loop (i + 1)
			else
				count_1s_loop (i + 1)
		in
		count_1s_loop 0
	in
	let change_str_n_to str n to_change =
		let rec change_str_n_to_loop i =
			if String.length str <= i then
				""
			else if i = n then
				String.make 1 to_change ^ (change_str_n_to_loop (i + 1))
			else
				(String.make 1 (String.get str i)) ^ (change_str_n_to_loop (i + 1))
		in
		change_str_n_to_loop 0
	in
	let find_rightest_1 str =
		(* Printf.printf "[%s]\n" str; *)
		let rec find_rightest_1_loop i rightest_i =
			if String.length str <= i then
				rightest_i - 1
			else if String.get str i = '1' then
			 	find_rightest_1_loop (i + 1) i
			else
				find_rightest_1_loop (i + 1) rightest_i
		in
		find_rightest_1_loop 0 0
	in
	let rec loop current_str not_first_time =
		if not_first_time <> 0 then
			print_char ' ' ;
		print_string current_str ;
		if (count_1s current_str) mod 2 = 0 (* si le nombre de 1 est pair, il faut inverser le dernier chiffre. *)
		then
			if String.get current_str ((String.length current_str) - 1) = '1' then
				loop (change_str_n_to current_str ((String.length current_str) - 1) '0') 1
			else
				loop (change_str_n_to current_str ((String.length current_str) - 1) '1') 1
		else (* si le nombre de 1 est impair, il faut inverser le chiffre situé à gauche du 1 le plus à droite. *)
		if ((find_rightest_1 current_str) >= 0) then
			if String.get current_str (find_rightest_1 current_str) = '1' then
				loop (change_str_n_to current_str (find_rightest_1 current_str) '0') 1
			else
				loop (change_str_n_to current_str (find_rightest_1 current_str) '1') 1
		else
			print_char '\n'
	in
	if n <= 0 then
		print_char '\n'
	else
		loop (create_str n) 0

let main () =
	gray 3;
	gray 2;
	gray 4;
	gray 1;
	gray 0

let () = main ()
