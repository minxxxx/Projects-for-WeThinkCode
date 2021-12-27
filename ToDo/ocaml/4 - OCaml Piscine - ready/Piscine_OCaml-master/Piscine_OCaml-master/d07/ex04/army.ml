class ['a] army (soldier:'a) =
object

	val _lst = [soldier]

	method add newsoldier = {<_lst=newsoldier::_lst>}
	method remove = match _lst with
	| head::tail -> {<_lst=tail>}
	| [] -> {<>}

	method foreach f = List.iter f _lst
	method set_lst lst = {<_lst=lst>}
	method get_lst = _lst

	method replace_elem new_elem pos = {<_lst = List.mapi (fun i elem -> if i = pos then new_elem else elem ) _lst >}
end
