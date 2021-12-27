type 'a ft_ref = {mutable ft_content: 'a}

let return v = {ft_content = v}

let get v = v.ft_content

let set reference value = reference.ft_content <- value

(* let bind reference f = return (get (f (get reference))) *)
let bind reference f = f (get reference)

let main () =
	let t = return 1 in
	print_int (get t) ; print_char '\n' ;
	set t 2;
	print_int (get t) ; print_char '\n' ;
	let t2 = bind t (function x -> return (x * 4)) in
	print_int (get t2) ; print_char '\n'

let () = main ()
