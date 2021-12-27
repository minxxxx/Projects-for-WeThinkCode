(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex02.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/23 13:47:30 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 14:21:07 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type PAIR = sig
	val pair : (int * int)
end

module type VAL = sig
	val x : int
end

module Pair : PAIR = struct let pair = ( 21, 42 ) end

module type MAKEPROJECTION =
	functor (Pair:PAIR) -> VAL

module MakeFst : MAKEPROJECTION =
	functor (Pair:PAIR) ->
	struct
		let x = fst Pair.pair
	end

module MakeSnd : MAKEPROJECTION =
	functor (Pair:PAIR) ->
	struct
		let x = snd Pair.pair
	end

(* FIX ME !!! *)
module Fst : VAL = MakeFst (Pair)

module Snd : VAL = MakeSnd (Pair)

let () = Printf.printf "Fst.x = %d, Snd.x = %d\n" Fst.x Snd.x
