class people name =
object
	val _name = name
	val _hp = 100

	method to_string = "[People:Name=\"" ^ _name ^ "\", HP=" ^ (string_of_int _hp) ^ "]"
	method talk = print_endline ("I'm " ^ _name ^ "! Do you know the Doctor?")
	method die = print_endline "Aaaarghh!"
	initializer print_endline ("A new people named `" ^ _name ^ "' is born. Let's hope he or she won't die too soon.")
end
