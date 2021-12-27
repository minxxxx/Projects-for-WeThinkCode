(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 15:27:44 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 15:33:15 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let test_add a b =
	let a = Watchover.add a b in
	Printf.printf "Add %d --> %d\n" b (Watchover.to_int a);
	a

let test_sub a b =
	let a = Watchover.sub a b in
	Printf.printf "Sub %d --> %d\n" b (Watchover.to_int a);
	a

let () =
	let clock = Watchover.zero in
	let clock = test_add clock 0 in
	let clock = test_add clock 2 in
	let clock = test_add clock 3 in
	let clock = test_add clock 4 in
	let clock = test_add clock 10 in
	let clock = test_add clock 5 in
	let clock = test_add clock 12 in
	let clock = test_add clock (-50) in
	let clock = test_add clock 30 in
	let clock = test_sub clock 5 in
	let clock = test_sub clock 1 in
	let clock = test_sub clock (-5) in
	let clock = test_sub clock 20 in
	let clock = test_sub clock 10 in
	let clock = test_sub clock 12 in
	let clock = test_sub clock 500 in
	Printf.printf "%d\n" (Watchover.to_int clock)
