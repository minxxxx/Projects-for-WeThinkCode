(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 10:44:04 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 17:17:44 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let loop_file in_stream jokes =
    try
        while true do
            let line = input_line in_stream in
            jokes := List.append !jokes [line]
        done;
        jokes
    with
    | _ -> jokes


let load_jokes argv argc =
    let joke_list = ref [] in
    try
        for i = 1 to (argc - 1) do
            let in_stream = open_in argv.(i) in
            ignore (loop_file in_stream joke_list)
        done;
        let array_jokes = Array.of_list !joke_list in
        let rand = Random.self_init (); Random.int (List.length !joke_list) in
        print_endline array_jokes.(rand)
    with
    | _ -> () 

let () =
    let argv = Sys.argv in
    match (Array.length argv) with
    | y when y < 2 -> print_endline "Pass in joke files"
    | _ -> load_jokes argv (Array.length argv)
