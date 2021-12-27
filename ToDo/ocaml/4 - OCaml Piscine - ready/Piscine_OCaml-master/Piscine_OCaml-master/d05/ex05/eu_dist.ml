let eu_dist a b =
	let rez = ref 0. in
	for i = 0 to Array.length a - 1 do
		rez := !rez +. ((a.(i) -. b.(i)) ** 2.)
	done ;
	sqrt(!rez)


let main () =
	let a = [|0. ; 0.|] in
	let b = [|1. ; 1.|] in
	print_float (eu_dist a b) ; print_char '\n';
	let a = [|0. ; 0.|] in
	let b = [|2. ; 2.|] in
	print_float (eu_dist a b) ; print_char '\n';
	let a = [|0. ; 0.|] in
	let b = [|3. ; 4.|] in
	print_float (eu_dist a b) ; print_char '\n';
	let a = [|1. ; 0.1 ; 12. ; 2.|] in
	let b = [|3.123 ; 4.123 ; 1.23 ; 1.|] in
	print_float (eu_dist a b) ; print_char '\n'

let () = main ()
