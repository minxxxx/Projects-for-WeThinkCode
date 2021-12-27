(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Grid.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 00:04:40 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 15:47:03 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = {
  owner : Block.status_type;
  blocks : Block.t list;
  full : bool;
}

let rec create_blocks count length = match count with
    | y when y < 1 -> []
    | _ -> (Block.create_new_block length)::(create_blocks (count - 1) length)

let create_new_grid length =
  {
    owner = Block.None;
    blocks = create_blocks 9 length;
    full = false;
  }

let get_grid_owner grid = match grid.owner with
    | Block.None -> "None"
    | Block.Some str -> str

let check_win_lines blocks index1 index2 index3 =
  if (Block.to_string (List.nth blocks index1)) = "None" then
    false
  else if (Block.to_string (List.nth blocks index1)) 
          <> (Block.to_string (List.nth blocks index2)) then
    false
  else if (Block.to_string (List.nth blocks index1))
          <> (Block.to_string (List.nth blocks index3)) then
    false
  else
    true

let is_valid_move grid index =
    if (Block.to_string (List.nth grid.blocks index)) <> "None" then
        false
    else
        true

let has_won_grid blocks =
  if (check_win_lines blocks 0 1 2) = true then
    true
  else if (check_win_lines blocks 3 4 5) = true then
    true
  else if (check_win_lines blocks 6 7 8) = true then
    true
  else if (check_win_lines blocks 0 3 6) = true then
    true
  else if (check_win_lines blocks 1 4 7) = true then
    true
  else if (check_win_lines blocks 2 5 8) = true then
    true
  else if (check_win_lines blocks 0 4 8) = true then
    true
  else if (check_win_lines blocks 2 4 6) = true then
    true
  else
    false

let rec is_grid_full blocks =
  match blocks with
  | [] -> true
  | block::next -> match (Block.to_string block) with
                | "None" -> false
                | _ -> is_grid_full next

let change_block_status grid blockIndex status =
    match grid.full with
    | true -> grid
    | false -> let rec loop l_blocks index = match l_blocks with
        | [] -> []
        | block::next -> 
            if index = blockIndex then
                (Block.change_block_status block status)::next
            else
                block::(loop next (index + 1))
    in let new_blocks = loop grid.blocks 1 in
    (
      fun () -> 
        if (has_won_grid new_blocks) = true then
          {owner=status;blocks=new_blocks;full=true}
        else if (is_grid_full new_blocks) = true then
          {owner=status;blocks=new_blocks;full=true}
        else
          {owner=grid.owner;blocks=(loop grid.blocks 1);full=grid.full}
    )()

let to_string grid =
    let rec loop blocks = match blocks with
      | [] -> "[]"
        | block::next -> "[" ^ (Block.to_string block) ^ "]::" ^ (loop next)
    in (fun () -> match grid.owner with
            | Block.Some str -> str ^ " " ^ (loop grid.blocks)
            | Block.None -> "None " ^ (loop grid.blocks)
    )()

let get_row grid row = match grid.full with
  | true -> (get_grid_owner grid) ^ " " ^
            (get_grid_owner grid) ^ " " ^
            (get_grid_owner grid)
  | false -> let rec loop blocks index = match blocks with
            | col1::col2::col3::next -> 
                if index < 1 then 
                    ""
                else if index = 1 then
                    (Block.get_block_status col1) ^ " " ^ 
                    (Block.get_block_status col2) ^ " " ^
                    (Block.get_block_status col3)
                else
                    loop next (index - 1)
            | _ -> ""
            in loop grid.blocks row

let is_grid_open grid =
    (grid.full = false)

let is_block_open grid index = match grid.full with
  | true -> false
  | false -> match index with
    | y when y > 0 && y < 10 -> (Block.is_open_block (List.nth grid.blocks (index-1)))
    | _ -> false

let print_grid grid =
  print_endline (get_row grid 1);
  print_endline (get_row grid 2);
  print_endline (get_row grid 3)

let test () =
    let grid1 = ref (create_new_grid 4) in
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
    print_endline ("Is block open 0 : " ^ (string_of_bool (is_block_open !grid1 0)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 1 (Block.Some "John"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 4 : " ^ (string_of_bool (is_block_open !grid1 4)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 2 (Block.Some "Jill"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 10 : " ^ (string_of_bool (is_block_open !grid1 10)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 3 (Block.Some "John"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 3 : " ^ (string_of_bool (is_block_open !grid1 3)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 4 (Block.Some "Jill"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 8 : " ^ (string_of_bool (is_block_open !grid1 8)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 5 (Block.Some "Jill"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 3 : " ^ (string_of_bool (is_block_open !grid1 3)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 6 (Block.Some "Jill"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 4 : " ^ (string_of_bool (is_block_open !grid1 4)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 7 (Block.Some "Jill"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 9 : " ^ (string_of_bool (is_block_open !grid1 9)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 8 (Block.Some "John"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 8 : " ^ (string_of_bool (is_block_open !grid1 8)));
    print_endline "----------------------------";
    ignore (grid1 := change_block_status !grid1 9 (Block.Some "John"));
    print_grid !grid1;
    print_endline ("Grid Owner : " ^ (get_grid_owner !grid1));
    print_endline ("Is Grid Open : " ^ (string_of_bool (is_grid_open !grid1)));
     print_endline ("Is block open 9 : " ^ (string_of_bool (is_block_open !grid1 9)));
    print_endline "----------------------------";
    print_endline ("Is grid full : " ^ (string_of_bool !grid1.full));
    print_endline "----------------------------"

(*let _ = test ()*)
