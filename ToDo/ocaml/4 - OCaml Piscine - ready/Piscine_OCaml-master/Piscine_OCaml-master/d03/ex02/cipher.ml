let rot42 str =
	String.map (fun c -> char_of_int (((int_of_char c) + 42) mod 255)) str

let caesar n str =
	String.map (fun c -> char_of_int (((int_of_char c) + n) mod 255)) str

let xor key str =
	String.map (fun c -> char_of_int (((int_of_char c) lxor (key mod 255)) mod 255)) str

let rec ft_crypt (str:string) (lst:(string->string) list) =
	match lst with
	| f::tail -> ft_crypt (f str) tail
	| [] -> str

let main () =
	print_endline ("Rot42 : ");
	let rotted = rot42 "Coucou - abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()\xfa" in
	print_endline rotted;
	print_endline (Uncipher.unrot42 rotted);

	print_endline ("Rotn : ");
	let rotted2 = caesar 751 "Coucou - abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()\xfa" in
	print_endline rotted2;
	print_endline (Uncipher.uncaesar 751 rotted2);

	print_endline ("lxor : ");
	let xored = xor 754 "Coucou - abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()\xfa" in
	print_endline xored;
	print_endline (Uncipher.xor 754 xored);

	print_endline "\n";

	let before_cypher = "abc312h321ob3u129ey7disdsiocewwefe{}{}{}[][][][]" in
	let cyphered = ft_crypt before_cypher [caesar 75; rot42 ; xor 59348] in
	print_endline ("before cypher : " ^ before_cypher);
	print_endline ("After cypher : " ^ cyphered);
	print_endline ("Uncyphered : " ^ (Uncipher.ft_uncrypt cyphered [Uncipher.xor 59348 ; Uncipher.unrot42 ; Uncipher.uncaesar 75]))

let () = main ()
