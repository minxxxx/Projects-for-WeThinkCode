(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Cmd.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 19:45:47 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 21:38:37 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let get_player_info name number =
  print_endline ("Enter Player" ^ (string_of_int number) ^ "'s name:");
  let rec name_loop () = match (read_line ()) with
    | s -> 
        if ((String.length s) = 0) || (name = s) then
          begin 
            print_endline ("Enter Player" ^ (string_of_int number) ^ "'s name:");
            name_loop ()
          end
        else
          begin print_endline "Choose \n  1. AI\n  2. HUMAN"; s end in
  let rec ai_loop () = match (read_int_opt ()) with
    | Some a -> 
        if (a < 1) || (a > 2) then
            begin print_endline "Choose \n  1. AI\n  2. HUMAN"; ai_loop () end
        else if a = 1 then
            true
        else
            false
    | None -> print_endline "Choose \n  1. AI\n  2. HUMAN"; ai_loop () in
  let player_name = name_loop () in
  let ai_value = ai_loop () in
  (player_name, ai_value)

let player_move player board =
  let (x, y) = Player.make_move player board in
  let new_board =
    Board.change_block_status board x y (Player.get_player_status_type player) in
  let grid_index = ((x - 1) / 3) + (((y - 1) / 3) * 3) in
  let grid_owner = Board.get_grid_owner grid_index new_board in
  if grid_owner <> "None" then
    print_endline (grid_owner ^ " wins grid " ^ (string_of_int (grid_index + 1)) ^ "!");
  (false, new_board)

let start_game player1 player2 start_board =
  let rec game_loop board number =
     print_endline "";
     Board.print_board board;
     if (Board.get_winner board) = "None" then
       begin
        if number = 1 then
            begin
                let (is_end, new_board) = player_move player1 board in
                game_loop new_board 2
            end
        else
            begin
                let (is_end, new_board) = player_move player2 board in
                game_loop new_board 1
            end
       end
     else
       print_endline (Board.get_winner board ^ " wins the game!") in
  game_loop start_board 1

let fix_name name1 len1 name2 len2 =
    if len1 < len2 then
        name1 ^ (String.init (len2 - len1) (fun i -> ' '))
    else
        name1

let rec command_line_entry () =
  let (name1, ai_value1) = get_player_info "" 1 in
  let (name2, ai_value2) = get_player_info name1 2 in
  let final_name1 = fix_name name1 (String.length name1) name2 (String.length name2) in
  let final_name2 = fix_name name2 (String.length name2) name1 (String.length name1) in
  let player1 = Player.create_new_player final_name1 ai_value1 "cmdline" 1 in
  let player2 = Player.create_new_player final_name2 ai_value2 "cmdline" 2 in
  let rec loop () =
    print_endline "Choose :\n  1. New Game\n  2. Exit";
    match (read_int_opt ()) with
    | Some a -> if a = 1 then
                    command_line_entry ()
                else if a = 2 then
                    ()
                else
                    loop ()
    | None -> loop () in
  start_game player1 player2 (Board.create_new_board (String.length final_name1));
  loop ()

