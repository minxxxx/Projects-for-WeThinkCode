(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   leibniz_pi.ml                                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 11:14:47 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/17 19:54:08 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let leibniz_pi delta =
	let pi4 = 4. *. atan 1. in
	let rec loop i j pi =
		let d = pi *. 4. -. pi4 in
		if d > (-.delta) && d < delta then
			j
		else
			loop (i +. 1.) (j + 1) (((-1.) ** i) /. (2. *. i +. 1.) +. pi)
	in
	if delta <= 0. then
		-1
	else
		loop 0. 0 0.
(*
** Test
*)
let () =
	print_int (leibniz_pi 0.1); print_char '\n';
	print_int (leibniz_pi 0.01); print_char '\n';
	print_int (leibniz_pi 0.001); print_char '\n';
	print_int (leibniz_pi 0.0001); print_char '\n';
	print_int (leibniz_pi 0.00001); print_char '\n';
	print_int (leibniz_pi 0.000001); print_char '\n';
	print_int (leibniz_pi 0.0000002); print_char '\n';
	print_int (leibniz_pi 0.00000005); print_char '\n';
