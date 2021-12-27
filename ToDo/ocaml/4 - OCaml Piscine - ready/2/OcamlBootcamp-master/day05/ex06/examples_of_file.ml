(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   examples_of_file.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 14:40:15 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 16:48:12 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let process_line mlist =
    let rec float_array_loop index max l_array = match index with
        | y when y < 0 -> l_array
        | y when y > max -> l_array
        | _ -> Array.set l_array index (float_of_string (List.nth mlist index));
               float_array_loop (index + 1) max l_array in
    let list_size = List.length mlist in
    let float_array = float_array_loop 0 (list_size - 2) (Array.make (list_size - 1) 0.0) in
    (float_array, (List.nth mlist (list_size - 1)))


let rec read_line in_stream res_list =
    try
        let line = input_line in_stream  in
        read_line in_stream (process_line (String.split_on_char ',' line)::res_list)
    with
    | Sys_error err -> Printf.printf "Error with file : %s\n" err; res_list
    | End_of_file -> res_list

let examples_of_file fileName =
    try 
        let in_stream = open_in fileName in
        read_line in_stream []
    with
    | Sys_error err -> Printf.printf "Error with file : %s : %s\n" fileName err; [] 
    | _ -> Printf.printf "Error with file : %s\n" fileName; []

let rec print_list mlist = match mlist with
    | [] -> ()
    | (float_array, name)::next -> 
            Printf.printf "%s -> %d\n" name (Array.length float_array);
            print_list next

let () =
    let argv = Sys.argv in
    match (Array.length argv) with
    | y when y < 2 -> print_endline "No file passed"
    | _ ->  let res_list = examples_of_file argv.(1) in
            Printf.printf "size of list : %d\n" (List.length res_list);
            print_list res_list
