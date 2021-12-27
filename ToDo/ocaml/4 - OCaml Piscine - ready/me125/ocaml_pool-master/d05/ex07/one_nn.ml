(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   one_nn.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 18:05:40 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 18:32:23 by jaguillo         ###   ########.fr       *)
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
** Test
*)

let () =
	let radars = [
		([|-0.67321; 0.80893; -0.40446; 0.06264; 0.97763; 0.04474; 0.95973|], "test1");
		([|0.66667; -0.01366; 0.97404; 0.06831; 0.49590; 0.50137; 0.75683|], "test2");
		([|0.83609; 0.13215; 0.72171; 0.06059; 0.65829; 0.08315; 0.23888|], "test3");
		([|0.12961; 0.43837; 0.20330; 0.49418; 0.12686; 0.44747; 0.13507|], "test4");
	] in
	print_string "Nearest of a is: ";
	print_endline (one_nn radars
			([|0.02337; -0.00592; -0.09924; -0.11949; -0.00763; -0.11824; 0.14706|], "a"));
	print_string "Nearest of b is: ";
	print_endline (one_nn radars
			([|0.74852; -0.02811; 0.65680; -0.05178; 0.80621; 0.02811; 0.|], "b"));
	print_string "Nearest of test2 is: ";
	print_endline (one_nn radars
			([|0.66667; -0.01366; 0.97404; 0.06831; 0.49590; 0.50137; 0.75683|], "test2"))
