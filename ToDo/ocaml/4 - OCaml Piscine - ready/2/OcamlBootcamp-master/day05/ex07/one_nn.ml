(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   one_nn.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 16:32:30 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 16:56:34 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type radar = (float array * string)

type t = float array -> float array -> float

let inner_cal index a_array b_array =
    let res = a_array.(index) -. b_array.(index) in
    res *. res

let (eu_dist : t) = fun a_array b_array ->
    let len = if (Array.length a_array) < (Array.length b_array) then
                Array.length a_array
           else
               Array.length b_array in
    let rec loop index max res = match index with
        | y when y >= max -> res
        | _ -> loop (index + 1) max (res +. (inner_cal index a_array b_array)) in
    let result = loop 0 len 0.0 in
    sqrt result

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

let rec one_nn radar_list test_radar radar_val dist = match radar_list with
    | [] -> radar_val
    | (float_array, value)::next -> 
            let (float_test_array, test_value) = test_radar in
            let new_dist = eu_dist float_array float_test_array in
            if new_dist <= dist then
                one_nn next test_radar value new_dist
            else
                one_nn next test_radar radar_val dist

let rec run_test train_list test_list = match test_list with
    | [] -> ()
    | head::next -> print_endline (one_nn train_list head "" max_float);
                    run_test train_list next

let () =
    let argv = Sys.argv in
    match (Array.length argv) with
    | y when y < 3 -> print_endline "program requires a test_file and train_file"
    | _ ->  let train_list = examples_of_file argv.(1) in
            let test_list = examples_of_file argv.(2) in
            run_test train_list test_list
