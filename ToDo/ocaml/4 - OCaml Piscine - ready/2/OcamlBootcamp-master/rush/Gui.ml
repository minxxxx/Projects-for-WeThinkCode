(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Gui.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 22:01:33 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/08 13:59:30 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let abs x = match x with
  | y when y < 0 -> x * (-1)
  | _ -> x

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

let fix_name name1 len1 name2 len2 =
    if len1 < len2 then
        name1 ^ (String.init (len2 - len1) (fun i -> ' '))
    else
        name1

let start_window_and_draw_board board =
  Graphics.open_graph " 960x780";
  Graphics.set_color (Graphics.rgb 163 93 53);
  Graphics.fill_rect 0 0 960 780;
  Graphics.set_line_width 4;
  Graphics.set_color Graphics.black;
  Graphics.draw_rect 130 30 500 50;
  Graphics.set_color (Graphics.rgb 140 104 74);
  Graphics.fill_rect 130 30 500 50;
  let rec col_loop x y count = match count with
    | a when a < 1 -> ()
    | _ ->  Graphics.set_color (Graphics.rgb 82 31 25);
            Graphics.fill_rect x y 60 60;
            Graphics.set_color Graphics.black;
            Graphics.draw_rect x y 60 60;
            if count = 7 then
                col_loop (x + 70) y (count - 1)
            else if count = 4 then
                col_loop (x + 70) y (count - 1)
            else
                col_loop (x + 60) y (count - 1)
  in let rec row_loop y count = match count with
    | a when a < 1 -> ()
    | _ -> col_loop 100 y 9; 
            if count = 7 then
                row_loop (y - 70) (count - 1)
            else if count = 4 then
                row_loop (y - 70) (count - 1)
            else
                row_loop (y - 60) (count - 1) in
  row_loop 600 9

let get_x_y_for_circle x y =
  let xx = ((x * 60) + 100) - 30 in
  let yy = (660 - (y * 60)) + 30 in
  if (x < 4 && y < 4) then
     (xx, yy)
  else if (x < 7) && (y < 4) then
    (xx + 10, yy)
  else if (x > 6) && (y < 4) then
    (xx + 20, yy)
  else if (x < 4) && (y < 7) then
    (xx, yy - 10)
  else if (x < 7) && (y < 7) then
    (xx + 10, yy - 10)
  else if (x > 6) && (y < 7) then
    (xx + 20, yy - 10)
  else if (x < 4) && (y > 6) then
    (xx, yy - 20)
  else if (x < 7) && (y > 6) then
    (xx + 10, yy - 20)
  else
    (xx + 20, yy - 20)

let fill_owner_grid x y w h color =
  Graphics.set_color (Graphics.rgb 82 31 25);
  Graphics.fill_rect x y w h;
  Graphics.set_color Graphics.black;
  Graphics.draw_rect x y w h;
  Graphics.draw_circle (x + 90) (y + 90) ((w / 2) - 20);
  Graphics.set_color color;
  Graphics.fill_circle (x + 90) (y + 90) ((w / 2) - 20)

let player_move player board number =
    let (x, y) = Player.make_move player board in
    let new_board =
           Board.change_block_status board x y (Player.get_player_status_type player) in
    let (xx, yy) = get_x_y_for_circle x y in
    let color = if number = 1 then Graphics.red else Graphics.blue in
    let grid_index = ((x - 1) / 3) + (((y - 1) / 3) * 3) in
    let grid_owner = Board.get_grid_owner grid_index new_board in
    Graphics.set_color Graphics.black;
    Graphics.draw_circle xx yy 20;
    Graphics.set_color color;
    Graphics.fill_circle xx yy 20;
    if grid_owner <> "None" then
        begin
            if grid_index = 0 then
              fill_owner_grid 100 480 180 180 color
            else if grid_index = 1 then
              fill_owner_grid 290 480 180 180 color
            else if grid_index = 2 then
              fill_owner_grid 480 480 180 180 color
            else if grid_index = 3 then
              fill_owner_grid 100 290 180 180 color
            else if grid_index = 4 then
              fill_owner_grid 290 290 180 180 color
            else if grid_index = 5 then
              fill_owner_grid 480 290 180 180 color
            else if grid_index = 6 then
              fill_owner_grid 100 100 180 180 color
            else if grid_index = 7 then
              fill_owner_grid 290 100 180 180 color
            else
              fill_owner_grid 480 100 180 180 color
          end;
    Graphics.set_text_size 150;
    Graphics.set_color (Graphics.rgb 140 104 74);
    Graphics.fill_rect 130 30 500 50;
    Graphics.set_color Graphics.black;
    Graphics.moveto 140 50;
    Graphics.draw_string ((Player.get_name player) ^ " plays " ^ (string_of_int x) ^ 
                          " " ^ (string_of_int y) ^ ".   ");
    if grid_owner <> "None" then
      Graphics.draw_string ((Player.get_name player) ^ " wins grid " ^ (string_of_int (grid_index + 1)) ^ "!");
    (false, new_board)

let start_game player1 player2 start_board =
    Graphics.set_color Graphics.red;
    Graphics.fill_rect 750 500 50 50;
    Graphics.set_color Graphics.black;
    Graphics.draw_rect 750 500 50 50;
    Graphics.moveto 820 520;
    Graphics.draw_string (Player.get_name player1);
    Graphics.set_color Graphics.blue;
    Graphics.fill_rect 750 400 50 50;
    Graphics.set_color Graphics.black;
    Graphics.draw_rect 750 400 50 50;
    Graphics.moveto 820 420;
    Graphics.draw_string (Player.get_name player2);
    let rec game_loop board number =
      if (Board.get_winner board) = "None" then
            begin
                if number = 1 then
                    begin
                        let (is_end, new_board) = player_move player1 board 1 in
                        game_loop new_board 2
                    end
                else
                    begin
                        let (is_end, new_board) = player_move player2 board 2 in
                        game_loop new_board 1
                    end
            end
       else
            begin
                Graphics.set_color (Graphics.rgb 140 104 74);
                Graphics.fill_rect 130 30 500 50;
                Graphics.set_color Graphics.black;
                Graphics.moveto 140 50;
                Graphics.draw_string ((Board.get_winner board) ^ " wins the game!");
                ignore (Graphics.read_key ())
            end in
    game_loop start_board 1

let rec gui_entry () =
  let (name1, ai_value1) = get_player_info "" 1 in
  let (name2, ai_value2) = get_player_info name1 2 in
  let final_name1 = fix_name name1 (String.length name1) name2 (String.length name2) in
  let final_name2 = fix_name name2 (String.length name2) name1 (String.length name1) in
  let player1 = Player.create_new_player final_name1 ai_value1 "SDL" 1 in
  let player2 = Player.create_new_player final_name2 ai_value2 "SDL" 2 in
  let board = Board.create_new_board (String.length final_name1) in
  let rec loop () =
    print_endline "Choose :\n  1. New Game\n  2. Exit";
    match (read_int_opt ()) with
    | Some a -> if a = 1 then
                    gui_entry ()
                else if a = 2 then
                    ()
                else
                    loop ()
    | None -> loop () in
  start_window_and_draw_board board;
  start_game player1 player2 board;
  loop ()


