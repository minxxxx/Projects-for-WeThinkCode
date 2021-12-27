let rec converges f x n =
	if n < 0 then false
	else if (f x) == x then
		true
	else
		converges f (f x) (n - 1)

let main () =
	print_endline (string_of_bool (converges (( * ) 2) 2 5));
	print_endline (string_of_bool (converges (fun x -> x / 2) 2 3));
	print_endline (string_of_bool (converges (fun x -> x / 2) 2 2));	(* 2/2 = 1, 1 / 2 = 0, 0 est un point fixe *)
	print_endline (string_of_bool (converges (fun x -> x * 2) 0 0))	(* On n'a besoin d'aucun itération pour atteindre un point fixe d'on renvoie true *)

let () = main ()
