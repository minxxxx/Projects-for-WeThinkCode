(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   alkane.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 15:21:59 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 19:42:32 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let alkane_name = function
| 1								-> "Methane"
| 2								-> "Ethane"
| 3								-> "Propane"
| 4								-> "Butane"
| 5								-> "Pentane"
| 6								-> "Hexane"
| 7								-> "Heptane"
| 8								-> "Octane"
| 9								-> "Nonane"
| 10							-> "Decane"
| 11							-> "Undecane"
| 12							-> "Dodecane"
| 16							-> "Hexadecane"
| 20							-> "Icosane"
| 30							-> "Triacontane"
| 40							-> "Tetracontane"
| 50							-> "Pentacontane"
| 60							-> "Hexacontane"
| _								-> "Unknow"

let list_create f len =
	let rec loop i acc =
		if i <= 0 then
			acc
		else
			loop (i - 1) ((f i)::acc)
	in
	loop len []

let alkane_formula n =
	(list_create (fun i -> new Atom.carbon) n) @ (list_create (fun i -> new Atom.hydrogen) (2 * n + 2))

class alkane n = object
	inherit Molecule.molecule (alkane_name n) (alkane_formula n)
end

class methane = object inherit alkane 1 end
class ethane = object inherit alkane 2 end
class propane = object inherit alkane 3 end
class butane = object inherit alkane 4 end
class pentane = object inherit alkane 5 end
class hexane = object inherit alkane 6 end
class heptane = object inherit alkane 7 end
class octane = object inherit alkane 8 end
class nonane = object inherit alkane 9 end
class decane = object inherit alkane 10 end
class undecane = object inherit alkane 11 end
class dodecane = object inherit alkane 12 end
class hexadecane = object inherit alkane 16 end
class icosane = object inherit alkane 20 end
class triacontane = object inherit alkane 30 end
class tetracontane = object inherit alkane 40 end
class pentacontane = object inherit alkane 50 end
class hexacontane = object inherit alkane 60 end

(*
** Test
*)

let test m =
	print_endline (m#to_string);
	print_endline (string_of_bool (m#equals (new ethane)))

let () =
	test (new methane);
	test (new ethane);
	test (new propane);
	test (new butane);
	test (new pentane);
	test (new hexane);
	test (new heptane);
	test (new octane);
	test (new nonane);
	test (new decane);
	test (new undecane);
	test (new dodecane);
	test (new hexadecane);
	test (new icosane);
	test (new triacontane);
	test (new tetracontane);
	test (new pentacontane);
	test (new hexacontane);
