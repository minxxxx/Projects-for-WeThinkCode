let my_sleep () = Unix.sleep 1


let () =
	try
		let nbr = int_of_string Sys.argv.(1) in
		for i = nbr downto 1 do
			my_sleep ()
		done
	with
	| _ -> ()


(* ocamlc -custom unix.cma micronap.ml -cclib -lunix *)
(* ocamlopt -cclib -lunix  unix.cmxa micronap.ml *)
