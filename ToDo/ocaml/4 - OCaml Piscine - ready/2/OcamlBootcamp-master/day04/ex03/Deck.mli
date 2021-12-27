(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Deck.mli                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/09 17:03:40 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/09 18:37:05 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type COLOR =
sig
    type t = Spade | Heart | Diamond | Club

    val all : t list

    val toString : t -> string
    val toStringVerbose : t -> string
end

module type VALUE =
sig
    type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

    val all : t list

    val toInt : t -> int
    val toString : t -> string
    val toStringVerbose : t -> string

    val next : t -> t
    val previous : t -> t
end

module Color : COLOR
module Value : VALUE

module type CARD =
sig
    type t

    val newCard : Value.t -> Color.t -> t

    val allSpades : t list
    val allHearts : t list
    val allDiamonds : t list
    val allClubs : t list

    val all : t list

    val getValue : t -> Value.t
    val getColor : t -> Color.t
    
    val toString : t -> string
    val toStringVerbose : t -> string

    val compare : t -> t -> int
    val max : t -> t -> t
    val min : t -> t -> t

    val best : t list -> t
    val isOf : t -> Color.t -> bool
    val isSpade : t -> bool
    val isHeart : t -> bool
    val isDiamond : t -> bool
    val isClub : t -> bool
end

module Card : CARD

module type DECK =
sig
    type t

    val newDeck : unit -> t

    (*val toStringList : t -> string list
    val toStringListVerbose : t -> string list

    val drawCard : t -> (Card.t * t list)*)
end
