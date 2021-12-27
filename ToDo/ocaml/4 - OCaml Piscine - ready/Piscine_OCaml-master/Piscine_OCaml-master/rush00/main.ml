let parse_line () = (* Some of (x ,y) | None *)
	let is_int str =
		if String.length str = 1 && String.get str 0 > '0' && String.get str 0 <= '9' then
			true
		else
			false
	in
	let str = read_line () in
		let str = String.trim str in
		let lst = String.split_on_char ' ' str in
		match lst with
		| [] -> None
		| head::next::next2::tail -> None
		| head::next::tail -> if is_int head && is_int next then
							Some (int_of_string(next), int_of_string(head))
						else
							None
		| head::tail -> None

let rec loop board player =
	let play_again () =
		print_endline "Play again ? (y/N)" ;
		let str = read_line () in
		if str = "y" || str = "Y" then
		begin
			let board = Board.newBoard () in
			Board.printBoard board;
			loop board (Board.getOwned_o ())
		end
		else
			()
	in
	let checkAndPrint new_board player =
		if Board.isFull new_board then
		begin
			Board.printBoard new_board ;
			print_endline "Draw";
			play_again ()
		end
		else
		begin
			Board.printBoard new_board ;
			loop new_board (Board.changePlayer player)
		end
	in
	print_endline ((Board.getPlayer player) ^ "'s turn to play.");
	match parse_line () with
	| None -> begin print_endline "Incorrect format" ; loop board player end
	| Some(x,y) -> begin
		let (ok, new_board) = Board.tryToPlacePoint board (x, y) player in
		if (ok = false) then
		begin
			print_endline "Illegal move";
			loop board player
		end
		else
		begin
			(* Check over *)
			let (ok, str, new_board) = Board.ticTacEnded new_board (x, y) player in
			if ok = true then
			begin
				print_endline str;
				let (ok, str) = Board.gameEnded new_board in
				if ok = true then
				begin
					Board.printBoard new_board ;
					print_endline str;
					play_again()
				end
				else
					checkAndPrint new_board player
			end
			else
				checkAndPrint new_board player
		end
	end

let main () =
	let board = Board.newBoard () in
	Board.printBoard board;
	loop board (Board.getOwned_o ()); ()

let () = main ()
