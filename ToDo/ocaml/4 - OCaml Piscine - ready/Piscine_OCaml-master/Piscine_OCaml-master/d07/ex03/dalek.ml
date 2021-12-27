class dalek =
object
	val _name = Random.self_init () ; "Dalek" ^ (String.make 1 (char_of_int ((Random.int 26) + (int_of_char 'A')))) ^ (String.make 1 (char_of_int ((Random.int 26) + (int_of_char 'a')))) ^ (String.make 1 (char_of_int ((Random.int 26) + (int_of_char 'a'))))
	val _hp = 100
	val mutable _shield = true

	method to_string = "[Dalek:Name=\"" ^ _name ^ "\", HP=" ^ (string_of_int _hp) ^ ", Shield=" ^ (if _shield then "true" else "false") ^ "]"
	method talk =
		Random.self_init() ;
		print_endline
			(match Random.int 4 with
				| 0 -> "Explain! Explain!"
				| 1 -> "Exterminate! Exterminate!"
				| 2 -> "I obey!"
				| 3 -> "You are the Doctor! You are the enemy of the Daleks!"
				| _ -> "WTF")

	method exterminate (people:People.people) = _shield <- false; people#die
	method die = print_endline "Emergency Temporal Shift"
end
