class ['a] army (soldier:'a) =
object

	val _lst = [soldier]

	method add newsoldier = {<_lst=newsoldier::_lst>}
	method remove = match _lst with
	| head::tail -> {<_lst=tail>}
	| [] -> {<>}

	method foreach f = List.iter f _lst
end
