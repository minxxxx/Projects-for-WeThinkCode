(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex03.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/23 14:21:47 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 19:41:47 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type FIXED = sig
	type t

	val of_float : float -> t
	val of_int : int -> t
	val to_float : t -> float
	val to_int : t -> int
	val to_string : t -> string

	val zero : t
	val one : t

	val succ : t -> t
	val pred : t -> t

	val min : t -> t -> t
	val max : t -> t -> t

	val gth : t -> t -> bool
	val lth : t -> t -> bool
	val gte : t -> t -> bool
	val lte : t -> t -> bool
	val eqp : t -> t -> bool
	val eqs : t -> t -> bool

	val add : t -> t -> t
	val sub : t -> t -> t
	val mul : t -> t -> t
	val div : t -> t -> t

	val foreach : t -> t -> (t -> unit) -> unit
end

module type FRACTIONNAL_BITS = sig
	val bits : int
end

module type MAKE =
	functor (Lol:FRACTIONNAL_BITS) ->
	FIXED

let round_to_int a = int_of_float (if a < 0. then a -. 0.5 else a +. 0.5)

module Make : MAKE =
	functor (Lol:FRACTIONNAL_BITS) ->
	struct
		type t = int

		let of_int i = i * (1 lsl Lol.bits)
		let of_float f = round_to_int (f *. (float_of_int (1 lsl Lol.bits)))

		let to_int x = x / (1 lsl Lol.bits)
		let to_float x = (float_of_int x) /. (float_of_int (1 lsl Lol.bits))

		let to_string x = string_of_float (to_float x)

		let zero = 0
		let one = of_int 1

		let succ x = x + 1
		let pred x = x - 1

		let min a b = if a > b then b else a
		let max a b = if a > b then a else b

		let gth a b = a > b
		let lth a b = a < b
		let gte a b = a >= b
		let lte a b = a <= b
		let eqp a b = a = b
		let eqs a b = a == b

		let add a b = a + b
		let sub a b = a - b
		let mul a b = int_of_float ((float_of_int a) *. (to_float b))
		let div a b = of_float ((to_float a) /. (to_float b))

		let foreach a b f =
			let rec loop a =
				if a <= b then begin
					f a; loop (a + 1)
				end else
					()
			and loop_down a =
				if a >= b then begin
					f a; loop_down (a - 1)
				end else
					()
			in
			if a > b then
				loop_down a
			else
				loop a
	end

(*
** Test
*)

module Fixed4 : FIXED = Make (struct let bits = 4 end)
module Fixed8 : FIXED = Make (struct let bits = 8 end)

let test a b =
	Printf.printf "---> %s  %s\n" (Fixed4.to_string a) (Fixed4.to_string b);
	Printf.printf " to_int : %d\n" (Fixed4.to_int b);
	Printf.printf " to_float : %f\n" (Fixed4.to_float b);
	Printf.printf " succ : %f\n" (Fixed4.to_float (Fixed4.succ b));
	Printf.printf " pred : %f\n" (Fixed4.to_float (Fixed4.pred b));
	Printf.printf " min : %f\n" (Fixed4.to_float (Fixed4.min a b));
	Printf.printf " max : %f\n" (Fixed4.to_float (Fixed4.max a b));
	Printf.printf " gth : %B\n" (Fixed4.gth a b);
	Printf.printf " lth : %B\n" (Fixed4.lth a b);
	Printf.printf " gte : %B\n" (Fixed4.gte a b);
	Printf.printf " lte : %B\n" (Fixed4.lte a b);
	Printf.printf " eqp : %B\n" (Fixed4.eqp a b);
	Printf.printf " eqs : %B\n" (Fixed4.eqs a b);
	Printf.printf " add : %f\n" (Fixed4.to_float (Fixed4.add a b));
	Printf.printf " sub : %f\n" (Fixed4.to_float (Fixed4.sub a b));
	Printf.printf " mul : %f\n" (Fixed4.to_float (Fixed4.mul a b));
	Printf.printf " div : %f\n" (Fixed4.to_float (Fixed4.div a b))

let () =
	let x8 = Fixed8.of_float 21.10 in
	let y8 = Fixed8.of_float 21.32 in
	let r8 = Fixed8.add x8 y8 in
	print_endline (Fixed8.to_string r8);
	Fixed4.foreach (Fixed4.zero) (Fixed4.one) (fun f -> print_endline (Fixed4.to_string f));
	(* Fixed4.foreach (Fixed4.one) (Fixed4.zero) (fun f -> print_endline (Fixed4.to_string f)); *)
	Fixed4.foreach (Fixed4.of_int 5) (Fixed4.of_int 6) (test (Fixed4.of_float 5.5))
