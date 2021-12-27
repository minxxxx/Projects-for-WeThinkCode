(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/09 10:51:14 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/09 16:59:54 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let main () =
    let spadeCards = Card.Card.allSpades in
    let heartCards = Card.Card.allHearts in
    let diamondCards = Card.Card.allDiamonds in
    let clubCards = Card.Card.allClubs in
    let deck = Card.Card.all in
    let rec loop cardList = match cardList with
        | [] -> ()
        | head::next ->
               print_endline ((Card.Card.toString head) ^ " " ^ (Card.Card.toStringVerbose head));
               loop next in
    loop deck;
    print_endline ("Get max 7H & QS -> " ^ (Card.Card.toString 
        (Card.Card.max (List.nth heartCards 6) (List.nth spadeCards 10))));
    print_endline ("Get max KD & KC -> " ^ (Card.Card.toString 
        (Card.Card.max (List.nth diamondCards 11) (List.nth clubCards 11))));
    print_endline ("Get max 9H & 4D -> " ^ (Card.Card.toString 
        (Card.Card.max (List.nth heartCards 8) (List.nth diamondCards 3))));
    print_endline ("Get max 7H & 3H -> " ^ (Card.Card.toString 
        (Card.Card.max (List.nth heartCards 6) (List.nth spadeCards 2))));
    print_endline ("Get max AsS & AsS -> " ^ (Card.Card.toString 
        (Card.Card.max (List.nth spadeCards 12) (List.nth spadeCards 12))));
    print_endline ("best of spade -> " ^ (Card.Card.toStringVerbose
        (Card.Card.best spadeCards)));
    print_endline ("Is card Spade 9D -> " ^ (string_of_bool (Card.Card.isSpade (List.nth diamondCards 8))));
    print_endline ("Is card Spade KS -> " ^ (string_of_bool (Card.Card.isSpade (List.nth spadeCards 11))))

let _ = main ()
