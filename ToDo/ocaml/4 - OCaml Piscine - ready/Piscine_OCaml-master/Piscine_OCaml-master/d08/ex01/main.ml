let argon = new Argon.argon
let carbon = new Carbon.carbon
let hydrogen = new Hydrogen.hydrogen
let krypton = new Krypton.krypton
let neon = new Neon.neon
let oxygen = new Oxygen.oxygen
let plutonium = new Plutonium.plutonium
let uranium = new Uranium.uranium

let water = new Water.water
let carbon_dioxyde = new Carbon_dioxyde.carbon_dioxyde

let ethanol = new Ethanol.ethanol
let hydrogen_peroxide = new Hydrogen_peroxide.hydrogen_peroxide
let benzene = new Benzene.benzene


let () =
	Printf.printf "argon : %s\n" (argon#to_string) ;
	Printf.printf "carbon : %s\n" (carbon#to_string) ;
	Printf.printf "hydrogen : %s\n" (hydrogen#to_string) ;
	Printf.printf "krypton : %s\n" (krypton#to_string) ;
	Printf.printf "neon : %s\n" (neon#to_string) ;
	Printf.printf "oxygen : %s\n" (oxygen#to_string) ;
	Printf.printf "plutonium : %s\n" (plutonium#to_string) ;
	Printf.printf "uranium : %s\n" (uranium#to_string) ;

	Printf.printf "\nMolecules\n\n" ;

	Printf.printf "%s : %s\n" water#name water#to_string ;
	Printf.printf "%s : %s\n" carbon_dioxyde#name carbon_dioxyde#to_string ;
	Printf.printf "%s : %s\n" ethanol#name ethanol#to_string ;
	Printf.printf "%s : %s\n" hydrogen_peroxide#name hydrogen_peroxide#to_string ;
	Printf.printf "%s : %s\n" benzene#name benzene#to_string ;
	if (water#equals carbon_dioxyde) then
		print_endline "Water equals carbon_dioxyde"
	else
		print_endline "Water not equals carbon_dioxyde";

	if (water#equals water) then
		print_endline "Water equals water"
	else
		print_endline "Water not equals water";
