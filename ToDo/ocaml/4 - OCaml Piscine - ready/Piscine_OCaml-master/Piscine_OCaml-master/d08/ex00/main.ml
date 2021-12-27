let argon = new Argon.argon
let carbon = new Carbon.carbon
let hydrogen = new Hydrogen.hydrogen
let krypton = new Krypton.krypton
let neon = new Neon.neon
let oxygen = new Oxygen.oxygen
let plutonium = new Plutonium.plutonium
let uranium = new Uranium.uranium

let () =
	Printf.printf "argon : %s\n" (argon#to_string) ;
	Printf.printf "carbon : %s\n" (carbon#to_string) ;
	Printf.printf "hydrogen : %s\n" (hydrogen#to_string) ;
	Printf.printf "krypton : %s\n" (krypton#to_string) ;
	Printf.printf "neon : %s\n" (neon#to_string) ;
	Printf.printf "oxygen : %s\n" (oxygen#to_string) ;
	Printf.printf "plutonium : %s\n" (plutonium#to_string) ;
	Printf.printf "uranium : %s\n" (uranium#to_string) ;
	if (uranium#equals plutonium) then
		print_endline "Uranium equals plutonium"
	else
		print_endline "Uranium not equals plutonium";

	if (uranium#equals uranium) then
		print_endline "Uranium equals uranium"
	else
		print_endline "Uranium not equals uranium"
