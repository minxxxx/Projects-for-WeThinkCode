(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/09 08:45:38 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/09 12:14:42 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let main () =
    let cardT2 = Value.Value.T2 in
    let cardT10 = Value.Value.T10 in
    let cardQueen = Value.Value.Queen in
    let cardAs = Value.Value.As in
    let allCards = Value.Value.all in
    let rec loop cardList = match cardList with
        | [] -> ()
        | head::next -> 
             print_endline (" " ^ (Value.Value.toStringVerbose head) ^ " -> " ^ 
                (string_of_int (Value.Value.toInt head)));
             loop next in
    print_endline ("toString T2 -> " ^ (Value.Value.toString cardT2));
    loop allCards;
    print_endline ("Next of T10 -> " ^ (Value.Value.toStringVerbose (Value.Value.next cardT10)));
    print_endline ("Previous of Queen -> " ^ (Value.Value.toStringVerbose (Value.Value.previous cardQueen)));
    print_endline "Next of As -> ";
    ignore (Value.Value.next cardAs);
    print_endline "Previous of T2 -> ";
    ignore (Value.Value.previous cardT2)

let _ = main ()
