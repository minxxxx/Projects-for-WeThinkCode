class virtual molecule name_p formula_p =
object (self)
	val _name : string = name_p
	val _formula: (Atom.atom list) = formula_p

	method private formula_as_string =
		let rec increase_atom (parameter:Atom.atom) liste =
			match liste with
			| (param, nbr)::tail when param#equals parameter -> (parameter, nbr + 1)::tail
			| head::tail -> head::(increase_atom parameter tail)
			| [] -> (parameter, 1)::[]
		in
		let rec loop ret current_lst  =
			match current_lst with
			| a::tail -> loop (increase_atom a ret) tail
			| [] -> ret
		in
		let lst = loop [] _formula in
		let lst = List.sort (fun (elem1, nbr1) (elem2, nbr2) ->
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
			List.fold_left (fun str (elem, nbr) -> elem#symbol ^ (if nbr > 1 then string_of_int nbr else "" ) ^ str) "" lst

	method name = _name
	method formula = self#formula_as_string

	method to_string = ("[Molecule:name=\"" ^ self#name ^ "\", formula=\"" ^ self#formula ^ "\"]")

	method equals (other:molecule) = (self#formula = other#formula)

	method get_formula_lst = _formula
end
