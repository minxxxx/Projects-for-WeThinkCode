module Card =
struct
	module Color =
	struct
		type t = Spade | Heart | Diamond | Club
		let all = [Spade; Heart; Diamond; Club]
		let toString = function | Spade -> "S" | Heart -> "H" | Diamond -> "D" | Club -> "C"
		let toStringVerbose = function | Spade -> "Spade" | Heart -> "Heart" | Diamond -> "Diamond" | Club -> "Club"
	end

	module Value =
	struct
		type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As
		let all = [T2 ; T3 ; T4 ; T5 ; T6 ; T7 ; T8 ; T9 ; T10 ; Jack ; Queen ; King ; As]
		let toInt = function | T2 -> 1 | T3 -> 2 | T4 -> 3 | T5 -> 4 | T6 -> 5 | T7 -> 6 | T8 -> 7 | T9 -> 8 | T10 -> 9 | Jack -> 10 | Queen -> 11 | King -> 12 | As -> 13
		let toString = function | T2 -> "2" | T3 -> "3" | T4 -> "4" | T5 -> "5" | T6 -> "6" | T7 -> "7" | T8 -> "8" | T9 -> "9" | T10 -> "10" | Jack -> "J" | Queen -> "Q" | King -> "K" | As -> "A"
		let toStringVerbose = function | T2 -> "2" | T3 -> "3" | T4 -> "4" | T5 -> "5" | T6 -> "6" | T7 -> "7" | T8 -> "8" | T9 -> "9" | T10 -> "10" | Jack -> "Jack" | Queen -> "Queen" | King -> "King" | As -> "As"
		let next = function | T2 -> T3 | T3 -> T4 | T4 -> T5 | T5 -> T6 | T6 -> T7 | T7 -> T8 | T8 -> T9 | T9 -> T10 | T10 -> Jack | Jack -> Queen | Queen -> King | King -> As | As -> invalid_arg "Value.next : As has no next"
		let previous = function | T2 -> invalid_arg "Value.previous : T2 has no previous" | T3 -> T2 | T4 -> T3 | T5 -> T4 | T6 -> T5 | T7 -> T6 | T8 -> T7 | T9 -> T8 | T10 -> T9 | Jack -> T10 | Queen -> Jack | King -> Queen | As -> King
	end

	type t = {
		value : Value.t;
		color : Color.t
	}

	let newCard value color =  {
		value = value;
		color = color
	}

	let allSpades = List.map (function elem -> (newCard elem Spade)) Value.all
	let allHearts = List.map (function elem -> (newCard elem Heart)) Value.all
	let allDiamonds = List.map (function elem -> (newCard elem Diamond)) Value.all
	let allClubs = List.map (function elem -> (newCard elem Club)) Value.all
	let all = allSpades @ allHearts @ allDiamonds @ allClubs

	let getValue {value; color = _} = value
	let getColor {value = _; color} = color

	let toString {value; color} = (Value.toString value) ^ (Color.toString color)
	let toStringVerbose {value; color} = Printf.sprintf "Card(%s, %s)" (Value.toStringVerbose value) (Color.toStringVerbose color)

	let compare {value = v1; color = _} {value = v2; color = _} = Value.toInt v1 - Value.toInt v2

	let max {value = v1; color = c1} {value = v2; color = c2} =
		if Value.toInt v1 >= Value.toInt v2 then
			{value = v1; color = c1}
		else
			{value = v2; color = c2}

	let min {value = v1; color = c1} {value = v2; color = c2} =
		if Value.toInt v1 <= Value.toInt v2 then
			{value = v1; color = c1}
		else
			{value = v2; color = c2}

	let best = function
		| [] -> invalid_arg "Card.best called with an empty list"
		| head::next::tail -> List.fold_left max head (next::tail)
		| head::tail -> head

	let isOf {value; color} comp = (color = comp)

	let isSpade card = isOf card Spade
	let isHeart card = isOf card Heart
	let isDiamond card = isOf card Diamond
	let isClub card = isOf card Club
end

type t = Card.t list

let newDeck () =
	Random.self_init () ; (* Ca devrait etre dans le main mais ce'st un choix d'implementation *)
	let shuffle d =
		let tagged = List.map (function elem -> ((Random.int 90000), elem)) d in
		let sorted = List.sort compare tagged in
		List.map snd sorted
	in
	shuffle Card.all

let toStringList deck =
	List.map Card.toString deck

let toStringListVerbose deck =
	List.map Card.toStringVerbose deck

let drawCard = function
	| [] -> raise (Failure "Deck.drawCard : Error called with an empty deck")
	| head::tail -> (head, tail)
