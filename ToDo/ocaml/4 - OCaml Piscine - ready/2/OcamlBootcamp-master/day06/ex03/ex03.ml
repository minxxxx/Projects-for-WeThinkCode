(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex03.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/11 14:49:57 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/11 17:25:43 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type FRACTIONNAL_BITS =
sig
    val bits : int
end

module type FIXED =
sig
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

module type MAKE =
    functor (FB : FRACTIONNAL_BITS) ->
        FIXED

module Make : MAKE =
    functor (FB : FRACTIONNAL_BITS) ->
        struct
            type t = int
            
            let rec power_of_two exp res = match exp with
            | y when y < 1 -> res
            | _ -> power_of_two (exp - 1) (res * 2)

            let int_bits = 1 * (power_of_two FB.bits 1)
            let float_bits = 1.0 *. (2.0 ** (float_of_int FB.bits))

            let of_float value = int_of_float (value *. float_bits)
            let of_int value = value * int_bits

            let to_float fixed_point = (float_of_int fixed_point) /. float_bits
            let to_int fixed_point = fixed_point / int_bits
            let to_string fixed_point = string_of_float (to_float fixed_point)

            let zero = 0
            let one = 1 * int_bits
            let succ fixed_point = fixed_point + 1
            let pred fixed_point = if fixed_point = zero then 0 else fixed_point - 1

            let gth fixed_point1 fixed_point2 = fixed_point1 > fixed_point2
            let lth fixed_point1 fixed_point2 = fixed_point1 < fixed_point2
            let gte fixed_point1 fixed_point2 = fixed_point1 >= fixed_point2
            let lte fixed_point1 fixed_point2 = fixed_point1 <= fixed_point2
            let eqp fixed_point1 fixed_point2 = fixed_point1 == fixed_point2
            let eqs fixed_point1 fixed_point2 = fixed_point1 = fixed_point2

            let min fixed_point1 fixed_point2 = 
                if (lte fixed_point1 fixed_point2) = true 
                then fixed_point1 
                else fixed_point2

            let max fixed_point1 fixed_point2 = 
                if (gte fixed_point1 fixed_point2) = true 
                then fixed_point1 
                else fixed_point2

            let add fixed_point1 fixed_point2 = fixed_point1 + fixed_point2
            let sub fixed_point1 fixed_point2 = fixed_point1 - fixed_point2
            let mul fixed_point1 fixed_point2 = fixed_point1 * fixed_point2
            let div fixed_point1 fixed_point2 =
                if fixed_point2 = zero then fixed_point1
                else fixed_point1 / fixed_point2

            let rec foreach current last f = match (lte current last) with
                | true -> f current; foreach (succ current) last f
                | false -> ()
        end

module Fixed4 : FIXED = Make (struct let bits = 4 end)
module Fixed8 : FIXED = Make (struct let bits = 8 end)

let () =
    let x8 = Fixed8.of_float 21.10 in
    let y8 = Fixed8.of_float 21.32 in
    let r8 = Fixed8.add x8 y8 in
    print_endline (Fixed8.to_string r8);
    print_endline ("x8 toString : " ^ (Fixed8.to_string x8));
    print_endline ("y8 toString : " ^ (Fixed8.to_string y8));
    print_endline ("x8 lth y8 : " ^ (string_of_bool (Fixed8.lth x8 y8)));
    print_endline ("x8 gth y8 : " ^ (string_of_bool (Fixed8.gth x8 y8)));
    print_endline ("min x8 y8 : " ^ (Fixed8.to_string (Fixed8.min x8 y8)));
    print_endline ("max x8 y8 : " ^ (Fixed8.to_string (Fixed8.max x8 y8)));
    Fixed4.foreach (Fixed4.zero) (Fixed4.one) (fun f -> print_endline (Fixed4.to_string f))
