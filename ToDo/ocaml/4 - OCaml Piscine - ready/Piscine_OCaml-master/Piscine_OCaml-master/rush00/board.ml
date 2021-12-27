type state = Owned_x | Owned_o | No_owner

module Tic_tac =
struct
	type tic_tac = Solved_x | Solved_o | Fight of (state list)

	let createTicTac () =
		let create_list element =
			let rec loop n = match n with
				| 0 -> []
				| _ -> element :: loop (n - 1)
			in
			loop 9
		in
		Fight (create_list No_owner)

	let stringState = function
		| Owned_x -> "X"
		| Owned_o -> "O"
		| No_owner -> "-"

	let stringTicTac t = match t with
	| Solved_x -> "Solved x"
	| Solved_o -> "Solved o"
	| Fight b ->
		match b with
		| elem1::elem2::elem3::elem4::elem5::elem6::elem7::elem8::elem9::tail -> (stringState elem1) ^ (stringState elem2) ^ (stringState elem3) ^ "\n" ^ (stringState elem4) ^ (stringState elem5) ^ (stringState elem6) ^ "\n" ^ (stringState elem7) ^ (stringState elem8) ^ (stringState elem9) ^ "\n"
		| _ -> ""

	let placePoint t (x, y) new_owner =
		if x < 0 || x > 3 || y < 0 || y > 3 then
			(false, t)
		else
		begin
			match t with
			| Solved_o -> (false, t)
			| Solved_x -> (false, t)
			| Fight lst ->
			begin
				let index = x * 3 + y in
				let elem = List.nth lst index in
				if elem = Owned_x || elem = Owned_o
				then
					(false, t)
				else
				begin
					let new_tic_tac = Fight (List.mapi (fun i elem -> if i <> index then elem else new_owner) lst) in
					(true, new_tic_tac)
				end
			end
		end

	let getLineAsString t n = match t with
	| Solved_x ->
	begin
		match n with
		| 0 -> "\\   /"
		| 1 -> "  X  "
		| 2 -> "/   \\"
		| _ -> ""
	end
	| Solved_o ->
	begin
		match n with
		| 0 -> "/ - \\"
		| 1 -> "|   |"
		| 2 -> "\\ - /"
		| _ -> ""
	end
	| Fight lst ->
	begin
		match lst with
		|  elem1::elem2::elem3::elem4::elem5::elem6::elem7::elem8::elem9::tail ->
			if n = 0 then
				(stringState elem1) ^ " " ^ (stringState elem2) ^ " " ^ (stringState elem3)
			else if n = 1 then
				(stringState elem4) ^ " " ^ (stringState elem5) ^ " " ^ (stringState elem6)
			else if n = 2 then
				(stringState elem7) ^ " " ^ (stringState elem8) ^ " " ^ (stringState elem9)
			else
				""
		| _ -> ""
	end

	let ticTacFull tic_tac =
		let rec loop lst = match lst with
		| [] -> true
		| head::tail -> if (head = Owned_o || head = Owned_x) then
					loop tail
				else
					false
		in
		match tic_tac with
		| Solved_o -> true
		| Solved_x -> true
		| Fight lst -> loop lst

	let isJustSolved t player =
	if ticTacFull t then
		(true, if player = Owned_x then Solved_x else Solved_o)
	else
	begin
		match t with
		| Solved_o -> (false, t)
		| Solved_x -> (false, t)
		| Fight lst ->
		begin
			match lst with
			| Owned_o::Owned_o::Owned_o::elem4::elem5::elem6::elem7::elem8::elem9::tail -> (true, Solved_o)
			| Owned_x::Owned_x::Owned_x::elem4::elem5::elem6::elem7::elem8::elem9::tail -> (true, Solved_x)
			| elem1::elem2::elem3::Owned_o::Owned_o::Owned_o::elem7::elem8::elem9::tail -> (true, Solved_o)
			| elem1::elem2::elem3::Owned_x::Owned_x::Owned_x::elem7::elem8::elem9::tail -> (true, Solved_x)
			| elem1::elem2::elem3::elem4::elem5::elem6::Owned_o::Owned_o::Owned_o::tail -> (true, Solved_o)
			| elem1::elem2::elem3::elem4::elem5::elem6::Owned_x::Owned_x::Owned_x::tail -> (true, Solved_x)
			| Owned_o::elem2::elem3::Owned_o::elem5::elem6::Owned_o::elem8::elem9::tail -> (true, Solved_o)
			| Owned_x::elem2::elem3::Owned_x::elem5::elem6::Owned_x::elem8::elem9::tail -> (true, Solved_x)
			| elem1::Owned_o::elem3::elem4::Owned_o::elem6::elem7::Owned_o::elem9::tail -> (true, Solved_o)
			| elem1::Owned_x::elem3::elem4::Owned_x::elem6::elem7::Owned_x::elem9::tail -> (true, Solved_x)
			| elem1::elem2::Owned_o::elem4::elem5::Owned_o::elem7::elem8::Owned_o::tail -> (true, Solved_o)
			| elem1::elem2::Owned_x::elem4::elem5::Owned_x::elem7::elem8::Owned_x::tail -> (true, Solved_x)
			| Owned_o::elem2::elem3::elem4::Owned_o::elem6::elem7::elem8::Owned_o::tail -> (true, Solved_o)
			| Owned_x::elem2::elem3::elem4::Owned_x::elem6::elem7::elem8::Owned_x::tail -> (true, Solved_x)
			| elem1::elem2::Owned_o::elem4::Owned_o::elem6::Owned_o::elem8::elem9::tail -> (true, Solved_o)
			| elem1::elem2::Owned_x::elem4::Owned_x::elem6::Owned_x::elem8::elem9::tail -> (true, Solved_x)
			| _ -> (false, t)
		end
	end
end

type board = (Tic_tac.tic_tac) list

let newBoard () = [Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac (); Tic_tac.createTicTac ()]

let tryToPlacePoint board (false_y, false_x) new_owner =
	if false_x < 1 || false_x > 9 || false_y < 1 || false_y > 9 then
	begin
		print_endline "here" ;
		(false, board)
	end
	else
	begin
		let (x, y) = (false_x - 1), (false_y - 1) in
		let (relative_x, relative_y) = (x mod 3, y mod 3) in
		let (tic_x, tic_y) = (x / 3, y / 3) in
		let tic_index = tic_x * 3 + tic_y in
		let (ok, newTic) = Tic_tac.placePoint (List.nth board tic_index) (relative_x, relative_y) new_owner in
			if ok = false then
				(false, board)
			else
			begin
				let new_board = (List.mapi (fun i elem -> if i <> tic_index then elem else newTic) board) in
				(true, new_board)
			end
	end


let isFull board =
	let rec loop n =
		if n = 9 then
			true
		else if Tic_tac.ticTacFull (List.nth board n) = false then
			false
		else
			loop (n + 1)
	in
	loop 0

let getPlayer = function
		| Owned_x -> "Player X"
		| Owned_o -> "Player O"
		| _ -> ""

let ticTacEnded board (false_y, false_x) player =
	let (x, y) = (false_x - 1), (false_y - 1) in
	let (tic_x, tic_y) = (x / 3, y / 3) in
	let tic_index = tic_x * 3 + tic_y in
	let (ok, newTic) = Tic_tac.isJustSolved (List.nth board tic_index) player in
	if ok = false then
		(false, "", board)
	else
	begin
		let new_board = (List.mapi (fun i elem -> if i <> tic_index then elem else newTic) board) in
		(true, ("Tic-Tac " ^ string_of_int(tic_index + 1) ^ " was just solved by " ^ (getPlayer player)), new_board)
	end

let printBoard board =
	match board with
	| elem1::elem2::elem3::elem4::elem5::elem6::elem7::elem8::elem9::tail ->
	begin
		let rec loop elem1 elem2 elem3 n =
			if n <> 3 then
			begin
				print_string ((Tic_tac.getLineAsString elem1 n) ^ " | " ^
					(Tic_tac.getLineAsString elem2 n)  ^ " | " ^
					(Tic_tac.getLineAsString elem3 n) ^ "\n") ;
				loop elem1 elem2 elem3 (n + 1)
			end
			else
				()
		in
		loop elem1 elem2 elem3 0;
		print_endline "---------------------" ;
		loop elem4 elem5 elem6 0;
		print_endline "---------------------" ;
		loop elem7 elem8 elem9 0;
	end
	| _ -> ()

let gameEnded board = match board with
	| Tic_tac.Solved_o::Tic_tac.Solved_o::Tic_tac.Solved_o::elem4::elem5::elem6::elem7::elem8::elem9::tail -> (true, "The game has been won by player O")
	| Tic_tac.Solved_x::Tic_tac.Solved_x::Tic_tac.Solved_x::elem4::elem5::elem6::elem7::elem8::elem9::tail -> (true, "The game has been won by player X")
	| elem1::elem2::elem3::Tic_tac.Solved_o::Tic_tac.Solved_o::Tic_tac.Solved_o::elem7::elem8::elem9::tail -> (true, "The game has been won by player O")
	| elem1::elem2::elem3::Tic_tac.Solved_x::Tic_tac.Solved_x::Tic_tac.Solved_x::elem7::elem8::elem9::tail -> (true, "The game has been won by player X")
	| elem1::elem2::elem3::elem4::elem5::elem6::Tic_tac.Solved_o::Tic_tac.Solved_o::Tic_tac.Solved_o::tail -> (true, "The game has been won by player O")
	| elem1::elem2::elem3::elem4::elem5::elem6::Tic_tac.Solved_x::Tic_tac.Solved_x::Tic_tac.Solved_x::tail -> (true, "The game has been won by player X")
	| Tic_tac.Solved_o::elem2::elem3::Tic_tac.Solved_o::elem5::elem6::Tic_tac.Solved_o::elem8::elem9::tail -> (true, "The game has been won by player O")
	| Tic_tac.Solved_x::elem2::elem3::Tic_tac.Solved_x::elem5::elem6::Tic_tac.Solved_x::elem8::elem9::tail -> (true, "The game has been won by player X")
	| elem1::Tic_tac.Solved_o::elem3::elem4::Tic_tac.Solved_o::elem6::elem7::Tic_tac.Solved_o::elem9::tail -> (true, "The game has been won by player O")
	| elem1::Tic_tac.Solved_x::elem3::elem4::Tic_tac.Solved_x::elem6::elem7::Tic_tac.Solved_x::elem9::tail -> (true, "The game has been won by player X")
	| elem1::elem2::Tic_tac.Solved_o::elem4::elem5::Tic_tac.Solved_o::elem7::elem8::Tic_tac.Solved_o::tail -> (true, "The game has been won by player O")
	| elem1::elem2::Tic_tac.Solved_x::elem4::elem5::Tic_tac.Solved_x::elem7::elem8::Tic_tac.Solved_x::tail -> (true, "The game has been won by player X")
	| Tic_tac.Solved_o::elem2::elem3::elem4::Tic_tac.Solved_o::elem6::elem7::elem8::Tic_tac.Solved_o::tail -> (true, "The game has been won by player O")
	| Tic_tac.Solved_x::elem2::elem3::elem4::Tic_tac.Solved_x::elem6::elem7::elem8::Tic_tac.Solved_x::tail -> (true, "The game has been won by player X")
	| elem1::elem2::Tic_tac.Solved_o::elem4::Tic_tac.Solved_o::elem6::Tic_tac.Solved_o::elem8::elem9::tail -> (true, "The game has been won by player O")
	| elem1::elem2::Tic_tac.Solved_x::elem4::Tic_tac.Solved_x::elem6::Tic_tac.Solved_x::elem8::elem9::tail -> (true, "The game has been won by player X")
	| _ ->  (false, "")



let getOwned_x () = Owned_x

let getOwned_o () = Owned_o

let changePlayer = function
	| Owned_x -> Owned_o
	| Owned_o -> Owned_x
	| _ -> Owned_o
