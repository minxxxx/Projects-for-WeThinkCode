(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Card.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 15:31:40 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 16:42:55 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Color = struct

	type t = Spade | Heart | Diamond | Club

	let all = [Spade; Heart; Diamond; Club]

	let toString = function
		| Spade			-> "S"
		| Heart			-> "H"
		| Diamond		-> "D"
		| Club			-> "C"

	let toStringVerbose = function
		| Spade			-> "Spade"
		| Heart			-> "Heart"
		| Diamond		-> "Diamond"
		| Club			-> "Club"

end

module Value = struct

	type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

	let all = [T2; T3; T4; T5; T6; T7; T8; T9; T10; Jack; Queen; King; As]

	let toInt = function
		| T2				-> 1
		| T3				-> 2
		| T4				-> 3
		| T5				-> 4
		| T6				-> 5
		| T7				-> 6
		| T8				-> 7
		| T9				-> 8
		| T10				-> 9
		| Jack				-> 10
		| Queen				-> 11
		| King				-> 12
		| As				-> 13

	let toString = function
		| T2				-> "2"
		| T3				-> "3"
		| T4				-> "4"
		| T5				-> "5"
		| T6				-> "6"
		| T7				-> "7"
		| T8				-> "8"
		| T9				-> "9"
		| T10				-> "10"
		| Jack				-> "J"
		| Queen				-> "Q"
		| King				-> "K"
		| As				-> "A"

	let toStringVerbose = function
		| T2				-> "2"
		| T3				-> "3"
		| T4				-> "4"
		| T5				-> "5"
		| T6				-> "6"
		| T7				-> "7"
		| T8				-> "8"
		| T9				-> "9"
		| T10				-> "10"
		| Jack				-> "Jack"
		| Queen				-> "Queen"
		| King				-> "King"
		| As				-> "As"

	let next = function
		| T2				-> T3
		| T3				-> T4
		| T4				-> T5
		| T5				-> T6
		| T6				-> T7
		| T7				-> T8
		| T8				-> T9
		| T9				-> T10
		| T10				-> Jack
		| Jack				-> Queen
		| Queen				-> King
		| King				-> As
		| As				-> invalid_arg "As"

	let previous = function
		| T2				-> invalid_arg "T2"
		| T3				-> T2
		| T4				-> T3
		| T5				-> T4
		| T6				-> T5
		| T7				-> T6
		| T8				-> T7
		| T9				-> T8
		| T10				-> T9
		| Jack				-> T10
		| Queen				-> Jack
		| King				-> Queen
		| As				-> King

end

type t = Value.t * Color.t

let newCard value color = (value, color)

let allOf c =
	let rec loop = function
		| []			-> []
		| head::tail	-> (head, c)::(loop tail)
	in
	loop Value.all

let allSpades = allOf Color.Spade
let allHearts = allOf Color.Heart
let allDiamonds = allOf Color.Diamond
let allClubs = allOf Color.Club

let all = List.concat [allSpades; allHearts; allDiamonds; allClubs]

let getValue (v, _) = v
let getColor (_, c) = c
let toString (v, c) = (Value.toString v) ^ (Color.toString c)
let toStringVerbose (v, c) =
	"Card(" ^ (Value.toStringVerbose v) ^ ", " ^ (Color.toStringVerbose c) ^ ")"

let compare (v1, _) (v2, _) = (Value.toInt v1) - (Value.toInt v2)
let max a b = if (compare a b) >= 0 then a else b
let min a b = if (compare a b) >= 0 then b else a

let best = function
	| []			-> invalid_arg "empty list"
	| head::tail	-> List.fold_left max head tail

let isOf (_, c') c = if c = c' then true else false

let isSpade t = isOf t Color.Spade
let isHeart t = isOf t Color.Heart
let isDiamond t = isOf t Color.Diamond
let isClub t = isOf t Color.Club
