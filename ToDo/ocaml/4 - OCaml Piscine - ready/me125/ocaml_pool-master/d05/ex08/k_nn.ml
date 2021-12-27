(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   k_nn.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 18:42:40 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 18:46:50 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type radar = float array * string

(*
** eu_dist
*)

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
** one_nn
*)

let radar_name ((_, name):radar) = name
let radar_data ((data, _):radar) = data

let one_nn radars r =
	let rec loop lst best best_dist =
		match lst with
		| head::tail			->
			let dist = eu_dist (radar_data head) (radar_data r) in
			if dist < best_dist then
				loop tail head dist
			else
				loop tail best best_dist
		| []					-> radar_name best
	in
	match radars with
	| head::tail			-> loop tail head (eu_dist (radar_data head) (radar_data r))
	| []					-> failwith "No radar"

(*
** k_nn
*)

let rec best_save bests r dist i =
	if i >= (Array.length bests) then
		()
	else
		let (_, d') = bests.(i) in
		if d' > dist then
			bests.(i) <- (r, dist)
		else
			best_save bests r dist (i + 1)

let best_class bests =
	let rec occur_count bests s i occur =
		if (Array.length bests) <= i then
			occur
		else
			let ((_, s'), _) = bests.(i) in
			if s' = s then
				occur_count bests s (i + 1) (occur + 1)
			else
				occur_count bests s (i + 1) occur
	in
	let rec best_seq bests i best_i =
		if (Array.length bests) <= i then
			let (r, _) = bests.(best_i) in
			(* print_int best_i; *)
			r
		else
			let ((_, s), _) = bests.(i) in
			let ((_, s'), _) = bests.(best_i) in
			if (occur_count bests s 0 0) > (occur_count bests s' 0 0) then
				best_seq bests (i + 1) i
			else
				best_seq bests (i + 1) best_i
	in
(* 	print_endline "\n  ---> k bests";
	for i = 0 to ((Array.length bests) - 1) do
		let (r, d) = bests.(i) in
		print_string (radar_name r);
		print_string "; dist: ";
		print_float d;
		print_newline ()
	done;
	print_endline "  ---> end"; *)
	radar_name (best_seq bests 1 0)

let k_nn radars k r =
	let rec loop lst bests =
		match lst with
		| head::tail			->
			let dist = eu_dist (radar_data head) (radar_data r) in
			best_save bests head dist 0;
			loop tail bests
		| []					-> bests
	in
	let rec init_loop lst bests i =
		if i < k then
			match lst with
			| head::tail			->
				bests.(i) <- (head, (eu_dist (radar_data head) (radar_data r)));
				init_loop tail bests (i + 1)
			| []					-> failwith "Not enougth data"
		else
			lst
	in
	if k <= 0 then
		failwith "k too low"
	else
		let bests = Array.make k (([||], ""), 0.) in
		best_class (loop (init_loop radars bests 0) bests)

(*
** Test
*)

let () =
	let radars = [
		([|-0.67321; 0.80893; -0.40446; 0.06264; 0.97763; 0.04474; 0.95973|], "a");
		([|0.66667; -0.01366; 0.97404; 0.06831; 0.49590; 0.50137; 0.75683|], "b");
		([|0.83609; 0.13215; 0.72171; 0.06059; 0.65829; 0.08315; 0.23888|], "c");
		([|0.12961; 0.43837; 0.20330; 0.49418; 0.12686; 0.44747; 0.13507|], "c");
		([|0.88085; 0.35232; 0.68389; 0.65128; 0.34816; 0.79784; 0.05832|], "b");
		([|0.90842; -0.29784; 0.86490; -0.62635; 0.69590; 0.79378; 0.29492|], "c");
		([|0.87111; 0.04326; 0.79946; 0.18297; 0.99009; 0.29292; 0.49590|], "a");
		([|0.86889; -0.07111; 1.0000; -0.02494; 1.0000; -0.06889; 0.1|], "y");
	] in
	print_string "Nearest class of test0 is (k = 4): ";
	print_endline (k_nn radars 4
			([|0.02337; -0.00592; -0.09924; -0.11949; -0.00763; -0.11824; 0.14706|], "test0"));
	print_string "Nearest radar of test0 is: ";
	print_endline (one_nn radars
			([|0.02337; -0.00592; -0.09924; -0.11949; -0.00763; -0.11824; 0.14706|], "test0"));
	print_string "Nearest class of test1 is (k = 4): ";
	print_endline (k_nn radars 4
			([|0.74852; -0.02811; 0.65680; -0.05178; 0.80621; 0.02811; 0.|], "test1"));
	print_string "Nearest radar of test1 is: ";
	print_endline (one_nn radars
			([|0.74852; -0.02811; 0.65680; -0.05178; 0.80621; 0.02811; 0.|], "test1"));
	print_string "Nearest class of test2 is (k = 4): ";
	print_endline (k_nn radars 4
			([|0.66667; -0.01366; 0.97404; 0.06831; 0.49590; 0.50137; 0.75683|], "test2"));
	print_string "Nearest radar of test2 is: ";
	print_endline (one_nn radars
			([|0.66667; -0.01366; 0.97404; 0.06831; 0.49590; 0.50137; 0.75683|], "test2"))
