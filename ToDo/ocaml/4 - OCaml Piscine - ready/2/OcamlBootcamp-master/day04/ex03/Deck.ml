(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Deck.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/09 17:03:27 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/09 18:37:04 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type COLOR =
sig
    type t = Spade | Heart | Diamond | Club

    val all : t list

    val toString : t -> string
    val toStringVerbose : t -> string
end

module Color : COLOR =
struct
    type t = Spade | Heart | Diamond | Club

    let (all : t list) = [Spade;Heart;Diamond;Club]

    let toString : (t -> string) = fun (elem : t) -> match elem with
        | Spade -> "S"
        | Heart -> "H"
        | Diamond -> "D"
        | Club -> "C"

    let toStringVerbose : (t -> string) = fun (elem : t) -> match elem with
        | Spade -> "Spade"
        | Heart -> "Heart"
        | Diamond -> "Diamond"
        | Club -> "Club"
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

module Value : VALUE =
struct
    type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

    let (all : t list) = [T2;T3;T4;T5;T6;T7;T8;T9;T10;Jack;Queen;King;As]

    let toInt : (t -> int) = fun (elem : t) -> match elem with
        | T2 -> 1
        | T3 -> 2
        | T4 -> 3
        | T5 -> 4
        | T6 -> 5
        | T7 -> 6
        | T8 -> 7
        | T9 -> 8
        | T10 -> 9
        | Jack -> 10
        | Queen -> 11
        | King -> 12
        | As -> 13

let toString : (t -> string) = fun (elem : t) -> match elem with
    | T2 -> "1"
    | T3 -> "2"
    | T4 -> "3"
    | T5 -> "4"
    | T6 -> "5"
    | T7 -> "6"
    | T8 -> "7"
    | T9 -> "8"
    | T10 -> "9"
    | Jack -> "J"
    | Queen -> "Q"
    | King -> "K"
    | As -> "As"

let toStringVerbose : (t -> string) = fun (elem : t) -> match elem with
    | T2 -> "1"
    | T3 -> "2"
    | T4 -> "3"
    | T5 -> "4"
    | T6 -> "5"
    | T7 -> "6"
    | T8 -> "7"
    | T9 -> "8"
    | T10 -> "9"
    | Jack -> "Jack"
    | Queen -> "Queen"
    | King -> "King"
    | As -> "As"

let next : (t -> t) = fun (elem : t) -> match elem with
    | T2 -> T3
    | T3 -> T4
    | T4 -> T5
    | T5 -> T6
    | T6 -> T7
    | T7 -> T8
    | T8 -> T9
    | T9 -> T10
    | T10 -> Jack
    | Jack -> Queen
    | Queen -> King
    | King -> As
    | As -> invalid_arg "As is the last element"

let previous : (t -> t) = fun (elem : t) -> match elem with
    | T2 -> invalid_arg "T2 is the first element"
    | T3 -> T2
    | T4 -> T3
    | T5 -> T4
    | T6 -> T5
    | T7 -> T6
    | T8 -> T7
    | T9 -> T8
    | T10 -> T9
    | Jack -> T10
    | Queen -> Jack
    | King -> Queen
    | As -> King
end

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

module Card : CARD =
struct
    type t = Nil | CCard of Value.t * Color.t

    let newCard value col =
        CCard (value, col)

    let allSpades 
        = [CCard (Value.T2, Color.Spade);CCard (Value.T3, Color.Spade);CCard (Value.T4,Color.Spade);
            CCard (Value.T5, Color.Spade);CCard (Value.T6, Color.Spade);CCard (Value.T7,Color.Spade);
            CCard (Value.T8, Color.Spade);CCard (Value.T9, Color.Spade);CCard (Value.T10,Color.Spade);
            CCard (Value.Jack, Color.Spade);CCard (Value.Queen, Color.Spade);CCard (Value.King,Color.Spade);
            CCard (Value.As, Color.Spade);]

    let allHearts 
        = [CCard (Value.T2, Color.Heart);CCard (Value.T3, Color.Heart);CCard (Value.T4,Color.Heart);
            CCard (Value.T5, Color.Heart);CCard (Value.T6, Color.Heart);CCard (Value.T7,Color.Heart);
            CCard (Value.T8, Color.Heart);CCard (Value.T9, Color.Heart);CCard (Value.T10,Color.Heart);
            CCard (Value.Jack, Color.Heart);CCard (Value.Queen, Color.Heart);CCard (Value.King,Color.Heart);
            CCard (Value.As, Color.Heart);]

    let allDiamonds 
        = [CCard (Value.T2, Color.Diamond);CCard (Value.T3, Color.Diamond);CCard (Value.T4,Color.Diamond);
            CCard (Value.T5, Color.Diamond);CCard (Value.T6, Color.Diamond);CCard (Value.T7,Color.Diamond);
            CCard (Value.T8, Color.Diamond);CCard (Value.T9, Color.Diamond);CCard (Value.T10,Color.Diamond);
            CCard (Value.Jack, Color.Diamond);CCard (Value.Queen, Color.Diamond);CCard (Value.King,Color.Diamond);
            CCard (Value.As, Color.Diamond);]

    let allClubs 
        = [CCard (Value.T2, Color.Club);CCard (Value.T3, Color.Club);CCard (Value.T4,Color.Club);
            CCard (Value.T5, Color.Club);CCard (Value.T6, Color.Club);CCard (Value.T7,Color.Club);
            CCard (Value.T8, Color.Club);CCard (Value.T9, Color.Club);CCard (Value.T10,Color.Club);
            CCard (Value.Jack, Color.Club);CCard (Value.Queen, Color.Club);CCard (Value.King,Color.Club);
            CCard (Value.As, Color.Club);]

    let all = List.append (List.append allSpades allHearts) (List.append allDiamonds allClubs)

    let getValue card = match card with
        | CCard (value, _) -> value
        | _ -> Value.T2

    let getColor card = match card with
        | CCard (_, color) -> color
        | _ -> Color.Spade

    let toString card = match card with
        | CCard (value, color) -> (Value.toString value) ^ (Color.toString color)
        | _ -> ""

    let toStringVerbose card = match card with
        | CCard (value, color) -> "Card(" ^ (Value.toStringVerbose value) ^ ", " ^
                (Color.toStringVerbose color) ^ ")"
        | _ -> ""

    let compare card1 card2 =
        match card1 with
        | Nil -> if card2 = Nil then 0 else -1
        | CCard (value1, color1) -> match card2 with
                | Nil -> 1
                | CCard (value2, color2) ->
                        if value1 = value2 then
                            0
                        else if value1 < value2 then
                            (-1)
                        else
                            0

    let max card1 card2 =
        let res = compare card1 card2 in
        match res with
        | (-1) -> card2
        | _ -> card1

    let min card1 card2 =
        let res = compare card1 card2 in
        match res with
        | 1 -> card2
        | _ -> card1

    let best cards =
        let rec loop cardList card =
            match cardList with
            | [] -> if card = Nil then invalid_arg "list is empty" else card
            | head::next -> match card with
                            | Nil -> loop next head
                            | _ -> loop next (max card head) in
        loop cards Nil

    let isOf card color = match card with
        | Nil -> false
        | CCard (value1, color1) -> color = color1

    let isSpade card = match card with
        | Nil -> false
        | CCard (value, color) -> isOf card Color.Spade

    let isDiamond card = match card with
        | Nil -> false
        | CCard (value, color) -> isOf card Color.Diamond

    let isHeart card = match card with
        | Nil -> false
        | CCard (value, color) -> isOf card Color.Heart

    let isClub card = match card with
        | Nil -> false
        | CCard (value, color) -> isOf card Color.Club

end

module type DECK =
sig
    type t

    val newDeck : unit -> t

    (*val toStringList : t -> string list
    val toStringListVerbose : t -> string list

    val drawCard : t -> (Card.t * t list)*)
end

module Deck : DECK =
struct
    type t = Card.t list

    let rec inList numList num = match numList with
        | [] -> false
        | head::next -> if head = num then true 
            else 
                inList numList num

   let rec generate_num numList num =
       if (inList numList num) = true then
           generate_num numList ((Random.int 11) + 1)
       else
           num

    let rec generateInts numList count = match count with
        | 0 -> []
        | _ ->  let num = generate_num numList ((Random.int 11) + 1) in
                num::(generateInts numList (count - 1))

    let newDeck () =
        let numList = generateInts [] 12 in
        let rec loop nlist cardList = match nlist with
            | [] -> []
            | head::next ->
                    (List.nth cardList head)::(loop next cardList) in
        let spades = loop Card.allSpades numList in
        let diamonds = spades::(loop Card.allDiamonds numList) in
        let clubs = diamonds::(loop Card.allClubs numList) in
        clubs::(loop Card.allClubs numList)

end
