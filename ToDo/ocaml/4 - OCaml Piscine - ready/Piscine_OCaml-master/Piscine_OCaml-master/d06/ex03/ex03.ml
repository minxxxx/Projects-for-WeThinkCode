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
	val eqp : t -> t -> bool (** physical equality *)
	val eqs : t -> t -> bool (** structural equality *)
	val add : t -> t -> t
	val sub : t -> t -> t
	val mul : t -> t -> t
	val div : t -> t -> t
	val foreach : t -> t -> (t -> unit) -> unit
end

module type FRACTIONNAL_BITS =
sig
	val bits : int
end

module type MAKEFIXED =
	functor (FixedSrc : FRACTIONNAL_BITS) -> FIXED

module Make : MAKEFIXED =
	functor (FixedSrc : FRACTIONNAL_BITS) ->
	struct
		let round f = int_of_float (floor (f +. 0.5))

		type t = int

		let of_float src = round (src *. (2. ** float_of_int FixedSrc.bits))
		let of_int src = src lsl FixedSrc.bits

		let to_float src = (float_of_int src) /. (2. ** float_of_int FixedSrc.bits)
		let to_int src = src lsr FixedSrc.bits

		let to_string src = string_of_float (to_float src)

		let zero = 0
		let one = of_int 1

		let succ t = t + 1
		let pred t = t - 1

		let min t1 t2 = if t1 <= t2 then t1 else t2
		let max t1 t2 = if t1 >= t2 then t1 else t2

		let gth t1 t2 = t1 > t2
		let lth t1 t2 = t1 < t2

		let gte t1 t2 = t1 >= t2
		let lte t1 t2 = t1 <= t2

		let eqp t1 t2 = t1 == t2
		let eqs t1 t2 = t1 = t2

		let add t1 t2 = of_float (to_float t1 +. to_float t2)
		let sub t1 t2 = of_float (to_float t1 -. to_float t2)
		let mul t1 t2 = of_float (to_float t1 *. to_float t2)
		let div t1 t2 = of_float (to_float t1 /. to_float t2)

		let rec foreach mini maxi f =
			if mini = maxi then
				f mini
			else
			begin
				f mini ; foreach (if mini < maxi then succ mini else pred mini) maxi f
			end
	end

module Fixed1 : FIXED = Make (struct let bits = 1 end)
module Fixed4 : FIXED = Make (struct let bits = 4 end)
module Fixed8 : FIXED = Make (struct let bits = 8 end)
module Fixed16 : FIXED = Make (struct let bits = 16 end)

let () =
let x8 = Fixed8.of_float 21.10 in
let y8 = Fixed8.of_float 21.32 in
let r8 = Fixed8.add x8 y8 in
print_endline (Fixed8.to_string r8);

Fixed4.foreach (Fixed4.zero) (Fixed4.one) (fun f -> print_endline (Fixed4.to_string f));
Fixed4.foreach (Fixed4.one) (Fixed4.zero) (fun f -> print_endline (Fixed4.to_string f));

let x1 = Fixed1.of_float 21.12 in
let y1 = Fixed1.of_float 21.30 in
let r1 = Fixed1.add x1 y1 in
Printf.printf "%s + %s = %s\n" (Fixed1.to_string x1) (Fixed1.to_string y1) (Fixed1.to_string r1);

let x16 = Fixed16.of_float 21.12 in
let y16 = Fixed16.of_float 21.30 in

Printf.printf "%s + %s = %s\n" (Fixed16.to_string x16) (Fixed16.to_string y16) (Fixed16.to_string (Fixed16.add x16 y16));
Printf.printf "%s - %s = %s\n" (Fixed16.to_string x16) (Fixed16.to_string y16) (Fixed16.to_string (Fixed16.sub x16 y16));
Printf.printf "%s * %s = %s\n" (Fixed16.to_string x16) (Fixed16.to_string y16) (Fixed16.to_string (Fixed16.mul x16 y16));
Printf.printf "%s / %s = %s\n" (Fixed16.to_string x16) (Fixed16.to_string y16) (Fixed16.to_string (Fixed16.div x16 y16));

Fixed16.foreach Fixed16.zero (Fixed16.of_float 0.0001) (function f -> print_endline (Fixed16.to_string f));

let x8 = Fixed8.of_float 10.5 in
let y8 = Fixed8.of_int 8 in
Printf.printf "x8 = %s and y8 = %s\n" (Fixed8.to_string x8) (Fixed8.to_string y8);

if Fixed8.lth x8 y8 then
	print_endline "x8 < y8"
else
	print_endline "!(x8 < y8)";

if Fixed8.gth x8 y8 then
	print_endline "x8 > y8"
else
	print_endline "!(x8 > y8)";

if Fixed8.lte x8 y8 then
	print_endline "x8 <= y8"
else
	print_endline "!(x8 <= y8)";

if Fixed8.gte x8 y8 then
	print_endline "x8 >= y8"
else
	print_endline "!(x8 >= y8)";

print_endline "max of x8 and y8 : ";
print_endline (Fixed8.to_string (Fixed8.max x8 y8));

print_endline "min of x8 and y8 : ";
print_endline (Fixed8.to_string (Fixed8.min x8 y8));

Printf.printf "x8 to int : %d\n" (Fixed8.to_int x8);
Printf.printf "x8 to float : %f\n" (Fixed8.to_float x8);
Printf.printf "x8 to string : %s\n" (Fixed8.to_string x8);


if Fixed8.eqp x8 y8 then
	print_endline "x8 physically equal to y8"
else
	print_endline "!(x8 physically equal to y8)";

if Fixed8.eqs x8 y8 then
	print_endline "x8 structurally equal to y8"
else
	print_endline "!(x8 structurally equal to y8)";

if Fixed8.eqp Fixed8.zero Fixed8.zero then
	print_endline "Fixed8.zero physically equal to Fixed8.zero"
else
	print_endline "!(Fixed8.zero physically equal to Fixed8.zero)";

if Fixed8.eqs Fixed8.zero Fixed8.zero then
	print_endline "Fixed8.zero structurally equal to Fixed8.zero"
else
	print_endline "!(Fixed8.zero structurally equal to Fixed8.zero)"
