module type PAIR = sig val pair : (int * int) end
module type VAL = sig val x : int end

module type MAKEPROJECTION = functor (PairVal : PAIR) -> VAL

module MakeFst : MAKEPROJECTION = functor (PairVal : PAIR) ->
	struct
		let x = let (value, _) = PairVal.pair in value
	end

module MakeSnd : MAKEPROJECTION = functor (PairVal : PAIR) ->
	struct
		let x = let (_, value) = PairVal.pair in value
	end


module Pair : PAIR = struct let pair = ( 21, 42 ) end
module Fst : VAL = MakeFst (Pair)
module Snd : VAL = MakeSnd (Pair)

let () = Printf.printf "Fst.x = %d, Snd.x = %d\n" Fst.x Snd.x
