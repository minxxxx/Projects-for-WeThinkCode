(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   molecule.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 13:05:31 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 13:34:25 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec cat_occur f acc =
	match f with
	| []							-> acc
	| head::tail					-> begin
		match acc with
		| (n, prev)::occ when prev = head	-> cat_occur tail ((n + 1, prev)::occ)
		| _									-> cat_occur tail ((1, head)::acc)
	end

let string_of_formula f =
	let rec atom_list_to_symbols f acc =
		match f with
		| []							-> acc
		| head::tail					-> atom_list_to_symbols tail ((head#symbol)::acc)
	in
	let rec loop f acc =
		match f with
		| []							-> acc
		| (n,atom)::tail when n > 1		-> loop tail (acc ^ (atom) ^ (string_of_int n))
		| (_,atom)::tail				-> loop tail (acc ^ (atom))
	in
	loop (List.sort (
		fun (_,a1) (_,a2) ->
		match a1, a2 with
		| _, "C"					-> 1
		| "C", _					-> -1
		| _, "H"					-> 1
		| "H", _					-> -1
		| a1, a2					-> String.compare a1 a2
	) (cat_occur (atom_list_to_symbols f []) [])) ""

class virtual molecule __name __formula = object
	val _name = __name
	val _formula = string_of_formula __formula
	method name = _name
	method formula = _formula
	method to_string = "molecule( name = " ^ _name ^ " ; formula = " ^ _formula ^ " )"
	method equals (m:molecule) = m#name = _name && m#formula = _formula
end

class trinitrotoluene = object inherit molecule "Trinitrotoluene" [new Atom.nitrogen;new Atom.nitrogen;new Atom.nitrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.oxygen;new Atom.oxygen;new Atom.oxygen;new Atom.oxygen;new Atom.oxygen;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon] end
class water = object inherit molecule "Water" [new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen] end
class carbon_dioxyde = object inherit molecule "Carbon dioxyde" [new Atom.carbon;new Atom.oxygen;new Atom.oxygen] end
class dioxygen = object inherit molecule "Dioxygen" [new Atom.oxygen;new Atom.oxygen] end
class acetic_acid = object inherit molecule "acetic_acid" [new Atom.hydrogen;new Atom.carbon;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.oxygen] end
class acetone = object inherit molecule "acetone" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.oxygen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class acetonitrile = object inherit molecule "acetonitrile" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.nitrogen] end
class acetylene = object inherit molecule "acetylene" [new Atom.carbon;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;] end
class ammonia = object inherit molecule "ammonia" [new Atom.nitrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class aspirin = object inherit molecule "aspirin" [new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.oxygen;new Atom.oxygen;new Atom.oxygen;] end
class benzene = object inherit molecule "benzene" [new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class ethane = object inherit molecule "ethane" [new Atom.carbon;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class ethanal = object inherit molecule "ethanal" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.oxygen;new Atom.hydrogen] end
class ethanamide = object inherit molecule "ethanamide" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.oxygen;new Atom.nitrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class ethanol = object inherit molecule "ethanol" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.hydrogen] end
class ethylamine = object inherit molecule "ethylamine" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.nitrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class ethylene = object inherit molecule "ethylene" [new Atom.carbon;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class ethylene_glycol = object inherit molecule "ethylene_glycol" [new Atom.hydrogen;new Atom.oxygen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.hydrogen] end
class formaldehyde = object inherit molecule "formaldehyde" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;] end
class hydrochloric_acid = object inherit molecule "hydrochloric_acid" [new Atom.hydrogen;new Atom.carbon;] end
class hydrogen_cyanide = object inherit molecule "hydrogen_cyanide" [new Atom.hydrogen;new Atom.carbon;new Atom.nitrogen] end
class hydrogen_peroxide = object inherit molecule "hydrogen_peroxide" [new Atom.hydrogen;new Atom.hydrogen;new Atom.oxygen;new Atom.oxygen] end
class isobutane = object inherit molecule "isobutane" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end
class isopentane = object inherit molecule "isopentane" [new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.carbon;new Atom.hydrogen;new Atom.hydrogen;new Atom.hydrogen;] end

(*
** Test
*)

let test m =
	print_endline (m#to_string);
	print_endline (string_of_bool (m#equals (new trinitrotoluene)))

let () =
	test (new trinitrotoluene);
	test (new water);
	test (new carbon_dioxyde);
	test (new dioxygen);
	test (new acetic_acid);
	test (new acetone);
	test (new acetonitrile);
	test (new acetylene);
	test (new ammonia);
	test (new aspirin);
	test (new benzene);
	test (new ethane);
	test (new ethanal);
	test (new ethanamide);
	test (new ethanol);
	test (new ethylamine);
	test (new ethylene);
	test (new ethylene_glycol);
	test (new formaldehyde);
	test (new hydrochloric_acid);
	test (new hydrogen_cyanide);
	test (new hydrogen_peroxide);
	test (new isobutane);
	test (new isopentane);
