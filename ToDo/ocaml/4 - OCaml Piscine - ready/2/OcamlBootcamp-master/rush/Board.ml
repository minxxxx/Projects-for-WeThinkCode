(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Board.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 11:56:45 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 21:05:59 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = {
  grids : Grid.t list;
  game_end : bool;
  namelen : int;
  winner : Block.status_type;
}

let rec create_grids count length = match count with
  | y when y < 1 -> []
  | _ -> (Grid.create_new_grid length)::(create_grids (count - 1) length)

let create_new_board length =
  {
    grids = create_grids 9 length;
    game_end = false;
    namelen = length;
    winner = Block.None;
  }

let get_winner board = match board.winner with
    | Block.None -> "None"
    | Block.Some str -> str

let check_win_lines grids index1 index2 index3 =
    if (Grid.get_grid_owner (List.nth grids index1)) = "None" then
        false
    else if (Grid.get_grid_owner (List.nth grids index1)) <>
            (Grid.get_grid_owner (List.nth grids index2)) then
        false
    else if (Grid.get_grid_owner (List.nth grids index1)) <>
            (Grid.get_grid_owner (List.nth grids index3)) then
        false
    else
        true

let has_won_game grids =
    if (check_win_lines grids 0 1 2) = true then
        true
    else if (check_win_lines grids 3 4 5) = true then
        true
    else if (check_win_lines grids 6 7 8) = true then
        true
    else if (check_win_lines grids 0 3 6) = true then
        true
    else if (check_win_lines grids 1 4 7) = true then
        true
    else if (check_win_lines grids 2 5 8) = true then
        true
    else if (check_win_lines grids 0 4 8) = true then
        true
    else if (check_win_lines grids 2 4 6) = true then
        true
    else
        false

let get_grid_owner index board =
  Grid.get_grid_owner (List.nth board.grids index)

let change_block_status board row col status = match board.game_end with
  | true -> board
  | false -> let grid_index = ((row - 1) / 3) + (((col - 1) / 3) * 3) in
             let block_index = (((row - 1) mod 3) + (((col - 1) mod 3) * 3)) + 1 in
             let rec loop l_grids index = match l_grids with
             | [] -> []
             | grid::next -> 
                if index = grid_index then
                  (Grid.change_block_status grid block_index status)::next
                else
                    grid::(loop next (index + 1)) 
            in let new_grids = loop board.grids 0 in
            (
              if (has_won_game new_grids) = true then
                {
                  grids = new_grids; game_end = true;
                  namelen = board.namelen; winner = status;
                }
              else
                {
                  grids = new_grids; game_end = board.game_end; 
                  namelen = board.namelen; winner = board.winner;
                }
            )

let is_valid_move board row col =
  let grid_index = ((row - 1) / 3) + (((col - 1) / 3) * 3) in
  let block_index = (((row-1) mod 3) + (((col-1) mod 3) * 3)) + 1 in
  if (Grid.get_grid_owner (List.nth board.grids grid_index)) <> "None" then
    false
  else if (Grid.is_valid_move (List.nth board.grids grid_index) 
             (block_index - 1)) <> true then
    false
  else
    true

let get_grids_in_row c1 c2 c3 =
  (Grid.get_row c1 1) ^ " * " ^ (Grid.get_row c2 1) ^ " * " ^ (Grid.get_row c3 1) 
  ^ "\n" ^
  (Grid.get_row c1 2) ^ " * " ^ (Grid.get_row c2 2) ^ " * " ^ (Grid.get_row c3 2) 
  ^ "\n" ^
  (Grid.get_row c1 3) ^ " * " ^ (Grid.get_row c2 3) ^ " * " ^ (Grid.get_row c3 3)

let get_row board row =
  let rec loop grids index = match grids with
    | col1::col2::col3::next -> 
      if index < 1 then
        ""
      else if index == 1 then
        get_grids_in_row col1 col2 col3
      else
        loop next (index - 1)
    | _ -> "" in
  loop board.grids row

let print_board board =
  print_endline (get_row board 1);
  print_endline (String.init ((board.namelen * 9) + 12) (fun i -> '*'));
  print_endline (get_row board 2);
  print_endline (String.init ((board.namelen * 9) + 12) (fun i -> '*'));
  print_endline ((get_row board 3) ^ "\n")

let test () =
  let board = ref (create_new_board 4) in
  print_board !board;
  (ignore (board := change_block_status !board 1 1 (Block.Some "john")));
  print_board !board;
  (ignore (board := change_block_status !board 2 2 (Block.Some "john")));
  print_board !board;
  (ignore (board := change_block_status !board 3 3 (Block.Some "john")));
  print_board !board;
  print_endline ("3 3 is valid move -> " ^ (string_of_bool (is_valid_move !board 3 3)));
  (ignore (board := change_block_status !board 5 4 (Block.Some "john")));
  print_board !board;
  (ignore (board := change_block_status !board 5 5 (Block.Some "john")));
  print_board !board;
  print_endline ("5 5 is valid move -> " ^ (string_of_bool (is_valid_move !board 5 5)));
  (ignore (board := change_block_status !board 5 6 (Block.Some "john")));
  print_board !board;
  (ignore (board := change_block_status !board 7 7 (Block.Some "john")));
  print_board !board;
  print_endline ("7 8 is valid move -> " ^ (string_of_bool (is_valid_move !board 7 8)));
  (ignore (board := change_block_status !board 8 7 (Block.Some "john")));
  print_board !board;
  (ignore (board := change_block_status !board 9 7 (Block.Some "john")));
  print_board !board;
  print_endline ("Winner : " ^ (get_winner !board))

(*let _ = test ()*)
