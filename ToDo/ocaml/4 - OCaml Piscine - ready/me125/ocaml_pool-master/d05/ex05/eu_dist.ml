(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   eu_dist.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 14:51:50 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 18:31:34 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let eu_dist a b =
	if (Array.length a) <> (Array.length b) then
		invalid_arg "Array have not the same dimension";
	let res = ref 0. in
	for i = 0 to ((Array.length a) - 1) do
		let diff = a.(i) -. b.(i) in
		res := !res +. (diff *. diff)
	done;
	!res ** 0.5

(*
** Test
*)
let print_float_array a =
	print_string "[|";
	for i = 0 to ((Array.length a) - 1) do
		if i > 0 then
			print_string "; ";
		print_float a.(i)
	done;
	print_string "|]"

let test a b =
	print_string "eu_dist(";
	print_float_array a;
	print_string ", ";
	print_float_array b;
	print_string ") = ";
	print_float (eu_dist a b);
	print_newline ()

let () =
	test [||] [||];
	test [|0.|] [|0.|];
	test [|3.815504;
		2.107736;
		2.042192;
		3.909637;
		1.719227;
		4.593510;
		4.832642;
		0.857140;
		3.815607;
		2.607076;|]
		[|0.904534;
		2.806514;
		4.882707;
		0.581756;
		4.550899;
		4.349869;
		4.674030;
		4.136962;
		3.936505;
		4.655247;|];
	test [|3.815504;
		2.107736;
		(-.infinity);
		3.909637;
		1.719227;
		nan;
		4.832642;
		0.857140;
		3.815607;
		2.607076;|]
		[|0.904534;
		2.806514;
		4.882707;
		nan;
		4.550899;
		infinity;
		4.674030;
		4.136962;
		3.936505;
		4.655247;|];
	test [|1.967639;
		1.753730;
		4.124866;
		0.274739;
		2.950430;
		1.531334;
		0.613968;
		2.564456;
		1.188031;
		3.842660;
		3.347460;
		0.982011;
		3.165739;
		0.090381;
		0.865815;
		2.374670;
		4.260251;
		0.484717;
		4.334187;
		4.677821;|]
		[|4.895636;
		0.261145;
		4.526524;
		4.379405;
		3.721757;
		1.665443;
		1.276554;
		1.599478;
		0.369576;
		1.761817;
		1.036045;
		2.576119;
		2.215380;
		4.826579;
		1.847781;
		1.378680;
		1.619666;
		4.816610;
		0.055967;
		3.484126;|];
(* 
from random import uniform

for i in range(0, 10):
	print("%f;" % uniform(0, 5))
 *)
