(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   calc.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 16:00:20 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 16:56:33 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type MONOID = sig
	type element
	val zero1 : element
	val zero2 : element
	val mul : element -> element -> element
	val add : element -> element -> element
	val div : element -> element -> element
	val sub : element -> element -> element
end

module INT :(MONOID with type element = int) = struct
	type element = int
	let zero1 = 0
	let zero2 = 1
	let mul = ( * )
	let add = ( + )
	let div a b = if b = 0 then zero1 else a / b
	let sub = ( - )
end

module FLOAT :(MONOID with type element = float) = struct
	type element = float
	let zero1 = 0.
	let zero2 = 1.
	let mul = ( *. )
	let add = ( +. )
	let div = ( /. )
	let sub = ( -. )
end

module Calc =
	functor (Lol:MONOID) ->
	struct
		let add = Lol.add
		let sub = Lol.sub
		let mul = Lol.mul
		let div = Lol.div
		let power a b =
			if b <= 0 then
				Lol.zero2
			else
				let rec loop b acc =
					if b > 0 then
						loop (b - 1) (Lol.mul acc a)
					else
						acc
				in
				loop b Lol.zero2
		let fact a =
			if a < Lol.zero1 then
				Lol.zero2
			else
				let rec loop a' acc =
					if a' < a then
						let a' = (Lol.add a' Lol.zero2) in
						loop a' (Lol.mul acc a')
					else
						acc
				in
				loop Lol.zero2 Lol.zero2
	end

module Calc_int = Calc(INT)
module Calc_float = Calc(FLOAT)

let () =
	print_endline (string_of_int (Calc_int.power 3 3));
	print_endline (string_of_float (Calc_float.power 3.0 3));
	print_endline (string_of_int (Calc_int.mul (Calc_int.add 20 1) 2));
	print_endline (string_of_float (Calc_float.mul (Calc_float.add 20.0 1.0) 2.0));
	print_endline (string_of_int (Calc_int.div (Calc_int.add 20 1) 2));
	print_endline (string_of_float (Calc_float.div (Calc_float.add 20.0 1.0) 2.0));
	print_endline (string_of_int (Calc_int.div (Calc_int.add 20 1) 0));
	print_endline (string_of_float (Calc_float.div (Calc_float.add 20.0 1.0) 0.0));
	print_endline (string_of_float (Calc_float.power 5.124 5));
	print_endline (string_of_float (Calc_float.power 5.124 3));
	print_endline (string_of_int (Calc_int.fact 4));
	print_endline (string_of_int (Calc_int.fact 10));
	print_endline (string_of_int (Calc_int.fact 0));
	print_endline (string_of_int (Calc_int.fact (-1)));
	print_endline (string_of_int (Calc_int.power 5 0));
	print_endline (string_of_int (Calc_int.power 8 1));
	print_endline (string_of_int (Calc_int.power 7 (-1)));
	print_endline (string_of_float (Calc_float.fact 5.124));
	print_endline (string_of_float (Calc_float.power 5.124 0));
