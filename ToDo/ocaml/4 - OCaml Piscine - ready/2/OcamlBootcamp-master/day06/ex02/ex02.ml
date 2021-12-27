(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex02.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/11 14:11:10 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/11 17:25:44 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type PAIR = 
sig 
    val pair : (int * int)
end

module type VAL = 
sig 
    val x : int 
end

module type MAKEPROJECTION =
    functor (Pair : PAIR) -> 
        VAL

module MakeFst : MAKEPROJECTION =
    functor (Pair : PAIR) ->
        struct
            let (a, b) = Pair.pair
            let x = a
        end

module MakeSnd : MAKEPROJECTION =
    functor (Pair : PAIR) ->
        struct
            let (a, b) = Pair.pair
            let x = b
        end

module Pair : PAIR = 
struct 
    let pair = (21, 42)
end

module Fst : VAL = MakeFst (Pair)

module Snd : VAL = MakeSnd (Pair)

let () = 
    Printf.printf "Fst.x = %d, Snd.x = %d\n" Fst.x Snd.x
