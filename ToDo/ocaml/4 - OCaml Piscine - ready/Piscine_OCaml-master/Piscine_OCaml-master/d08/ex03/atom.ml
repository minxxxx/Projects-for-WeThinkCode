class virtual atom name_p symbol_p atomic_number_p =
object

	val _name : string = name_p
	val _symbol : string = symbol_p
	val _atomic_number :int = atomic_number_p

	method name : string = _name
	method symbol : string = _symbol
	method atomic_number :int = _atomic_number

	method to_string = ("[Atom:name=\"" ^ _name ^ "\", symbol=\"" ^ _symbol ^ "\", atomic_number=" ^ (string_of_int _atomic_number) ^ "]")
	method equals (other:atom) = (_name = other#name) && (_symbol = other#symbol)&& (_atomic_number = other#atomic_number)
end
