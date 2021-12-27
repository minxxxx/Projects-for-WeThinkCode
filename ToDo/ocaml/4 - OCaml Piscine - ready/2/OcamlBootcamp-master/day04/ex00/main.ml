(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/09 08:27:13 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/09 11:13:27 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let main () =
    let spadeColor = Color.Color.Spade in
    let diamondColor = Color.Color.Diamond in
    let allColors = Color.Color.all in
    let rec loop colorList = match colorList with
        | [] -> ()
        | head::next -> print_endline (Color.Color.toString head);
                        print_endline (Color.Color.toStringVerbose head);
                        loop next in
    print_endline ("Spade toString -> " ^ (Color.Color.toString spadeColor));
    print_endline ("Diamond toStringVerbose -> " ^ (Color.Color.toStringVerbose diamondColor));
    print_endline "All colors";
    loop allColors

let _ = main ()
