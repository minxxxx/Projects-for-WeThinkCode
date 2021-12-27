(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Block.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/06 23:10:10 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 10:55:27 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type status_type = Some of string | None
type t = {
  status : status_type;
  length : int;
}

let create_new_block len =
  {
    status = None;
    length = len
  }

let get_block_status block = match block.status with
    | None -> (String.init block.length (fun i -> '-'))
    | Some str -> str

let is_open_block block = match block.status with
    | None -> true
    | _ -> false

let change_block_status block s = match (is_open_block block) with
  | true -> { status=s; length=block.length; }
    | false -> block

let to_string block = match block.status with
    | None -> "None"
    | Some str -> str

let test () =
    let block1 = create_new_block 5 in
    let block2 = change_block_status block1 (Some "John") in
    let block3 = change_block_status block2 (Some "Tasha") in
    print_endline ("Create a new block1 -> " ^ (to_string block1));
    print_endline ("Is block1 open -> " ^ (string_of_bool (is_open_block block1)));
    print_endline ("change status block1 to X (block2) -> " ^ (to_string block2));
    print_endline ("Is block2 open -> " ^ (string_of_bool (is_open_block block2)));
    print_endline ("change status block2 to O (block3) -> " ^ (to_string block3));
    print_endline ("Is block3 open -> " ^ (string_of_bool (is_open_block block3)))

(*let _ = test ()*)
