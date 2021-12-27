class doctor name age (sidekick:People.people) =
object (self)

	val _name = name
	val _age = age
	val _sidekick = sidekick
	val _hp = 100

	method to_string = "[Doctor:Name=\"" ^ _name ^ "\", age=" ^ (string_of_int _age) ^ ", HP=" ^ (string_of_int _hp) ^ ", sidekick="^ sidekick#to_string ^"]"
	method talk = print_endline "Hi! I'm the Doctor!"
	initializer print_endline ("A new " ^ (string_of_int _age) ^ " years old Doctor has been created. He is peaceful and helps peoples.")

	method travel_in_time start arrival = print_endline "           ___\n           | |\n           | |\n   -------------------\n   -------------------\n    |  ___  |  ___  |\n    | | | | | | | | |\n    | |-+-| | |-+-| |\n    | |_|_| | |_|_| |\n    |  ___  |  ___  |\n    | |   | | |   | |\n    | |   | | |   | |\n    | |___| | |___| |\n    |  ___  |  ___  |\n    | |   | | |   | |\n    | |   | | |   | |\n    | |___| | |___| |\n    |       |       |\n   ===================" (* /!\ Age can be negative but it is an implementation's choice. Anyway i've got no idea of how to avoid that. *) ; {<_age=_age + (arrival - start)>}

	method use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"
	method private regenerate = {<_hp = 100>}

	method get_hurt_but_just_for_the_defense_session = {<_hp=_hp - 10>}
	method public_regenerate_but_just_for_the_defense_session = self#regenerate
end
