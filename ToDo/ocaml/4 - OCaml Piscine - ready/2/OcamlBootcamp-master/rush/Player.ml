(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Player.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 16:00:32 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/08 14:40:08 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type interface = CMDLINE | NCURSES | SDL

type t = {
  name : string;
  ai : bool;
  input : interface;
  number : int;
}

let is_in_grid startx starty endx endy x y =
  if (x < startx) || (x > endx) then 
    false
  else if (y > starty) || (y < endy) then
    false
  else
    true

let calc_x_y startx starty x y gridx gridy =
  let xx = ((x - startx) / 60) in
  let yy = ((starty - y ) / 60) in
  ((xx + gridx), (yy + gridy))

let get_gui_x_y x y =
  if (is_in_grid 100 660 280 480 x y) = true then
      calc_x_y 100 660 x y 1 1
  else if (is_in_grid 290 660 470 480 x y) = true then
      calc_x_y 290 660 x y 4 1
  else if (is_in_grid 480 660 660 480 x y) = true then
      calc_x_y 480 660 x y 7 1
  else if (is_in_grid 100 470 280 290 x y) = true then
      calc_x_y 100 470 x y 1 4
  else if (is_in_grid 290 470 470 290 x y) = true then
      calc_x_y 290 470 x y 4 4
  else if (is_in_grid 480 470 660 290 x y) = true then
      calc_x_y 480 470 x y 7 4
  else if (is_in_grid 100 280 280 100 x y) = true then
      calc_x_y 100 280 x y 1 7
  else if (is_in_grid 290 280 470 100 x y) = true then
      calc_x_y 290 280 x y 4 7
  else if (is_in_grid 480 290 660 100 x y) = true then
      calc_x_y 480 290 x y 7 7
  else
      (-1, -1)


let create_new_player name ai input number = match input with
  | "Ncurses" -> {name = name; ai = ai; input = NCURSES; number = number;}
  | "SDL" -> {name = name; ai = ai; input = SDL; number = number;}
  | _ -> {name = name; ai = ai; input = CMDLINE; number = number;}

let ai_move board =
  Random.self_init ();
  let rec loop () =
    let x = (Random.int 9) + 1 in
    let y = (Random.int 9) + 1 in
    if (Board.is_valid_move board x y) = true then
        begin
        print_endline ((string_of_int x) ^ " " ^ (string_of_int y));  
        (x, y)
        end
    else
        loop ()
  in loop ()


let get_ints_from_line l_str =
  ((int_of_string_opt (List.nth l_str 0)), (int_of_string_opt (List.nth l_str 1)))

let get_value_from_option x =
  match x with
    | None -> 0
    | Some v -> v

let get_name player =
  player.name

let get_player_status_type player =
  Block.Some player.name

let cmdline_move player board =
  let name = (String.trim player.name) in
  let rec loop () =
        match (read_line ()) with
        | "" -> loop ()
        | s -> let l_str = String.split_on_char ' ' s in
            match (List.length l_str) with
              | y when y > 1 -> 
                let (a, b) = get_ints_from_line l_str in
                if (a = None) || (b = None) then
                   begin print_endline "Incorrect format."; loop () end
                else 
                  begin
                  let (x, y) = ((get_value_from_option a), (get_value_from_option b)) in
                    if (x < 1) || (x > 9) || (y < 1) || (y > 9) then
                         begin print_endline "Illegal move."; loop () end
                    else if (Board.is_valid_move board x y) = true then
                        (x, y)
                    else
                        begin print_endline "Illegal move."; loop () end
                  end
              | _ -> print_endline "Incorrect format."; loop ()
  in print_endline (name ^ "'s turn to play.");
  loop ()

let ncurses_move player board =
  (1, 1)

let sdl_move player board =
    let rec loop () =
      ignore (Graphics.wait_next_event [Graphics.Button_up]);
      let (posx, posy) = Graphics.mouse_pos () in
      (*let (x, y) = get_gui_x_y status.mouse_x status.mouse_y in*)
      let (x, y) = get_gui_x_y posx posy in
      if (x = (-1)) || (y = (-1)) then
          loop ()
      else if (Board.is_valid_move board x y) = true then
          (x, y)
      else
          loop () in
    loop ()

let human_move player board = match player.input with
  | CMDLINE -> cmdline_move player board
  | NCURSES -> ncurses_move player board
  | SDL -> sdl_move player board

let make_move player board = match player.ai with
  | true -> ai_move board
  | false -> human_move player board

let test () =
  let player = create_new_player "paul   " false "cmdline" 1 in
  let rec loop board =
        ignore (make_move player board);
        loop board in
  loop (Board.create_new_board 7)

(*let _ = test ()*)
