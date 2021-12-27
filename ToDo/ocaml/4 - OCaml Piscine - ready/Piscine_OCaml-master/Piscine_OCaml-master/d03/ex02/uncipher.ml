let unrot42 str =
	String.map (fun c -> char_of_int (
			if (((int_of_char c) - 42) mod 255) < 0 then
				(((int_of_char c) - 42) mod 255) + 255
			else
			 	(((int_of_char c) - 42) mod 255))) str


let uncaesar n str =
	String.map (fun c -> char_of_int (
			if (((int_of_char c) - n) mod 255) < 0 then
				(((int_of_char c) - n) mod 255) + 255
			else
			 	(((int_of_char c) - n) mod 255))) str

let rec ft_uncrypt (str:string) (lst:(string->string) list) =
	match lst with
	| f::tail -> ft_uncrypt (f str) tail
	| [] -> str


let xor key str =
	String.map (fun c -> char_of_int (((int_of_char c) lxor (key mod 255)) mod 255)) str
