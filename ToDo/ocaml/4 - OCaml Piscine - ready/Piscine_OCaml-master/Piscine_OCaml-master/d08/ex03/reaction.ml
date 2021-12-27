class virtual reaction (start:(Molecule.molecule * int) list) (result:(Molecule.molecule * int) list) =
object
	val _start = start
	val _result = result

	method get_start = _start
	method get_result = _result

	method virtual balance : reaction

	method is_balanced =
		let rec count_atoms lst =
			List.fold_left
			(fun acc (m,c) ->
				let rec loop n =
					if n = 0 then
						[]
					else
						m#get_formula_lst @ (loop (n - 1))
				in
				loop c
			) [] lst
		in
		let sort_lst lst =
			List.sort (fun (elem1, nbr1) (elem2, nbr2) ->
				if elem1#equals elem2
					then 0
				else if elem1#equals new Carbon.carbon
					then 1
				else if elem2#equals new Carbon.carbon
					then -1
				else if elem1#equals new Hydrogen.hydrogen
					then 1
				else if elem2#equals new Hydrogen.hydrogen
					then -1
				else
					(compare elem2#symbol elem1#symbol)) lst
		in
		let merge_lst lst =
			let rec increase_atom (parameter:Atom.atom) liste =
				match liste with
					| (param, nbr)::tail when param#equals parameter -> (parameter, nbr + 1)::tail
					| head::tail -> head::(increase_atom parameter tail)
					| [] -> (parameter, 1)::[]
			in
			let rec loop rez lst =
				match lst with
				| head::tail -> loop (increase_atom head rez) tail
				| [] -> rez
			in
			loop [] lst
		in
		let lst1 = sort_lst (merge_lst (count_atoms _start)) in
		let lst2 = sort_lst (merge_lst (count_atoms _result)) in
		lst1 = lst2

end
