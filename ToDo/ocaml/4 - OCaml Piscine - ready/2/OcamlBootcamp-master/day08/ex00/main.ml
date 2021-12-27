(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:07:33 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 22:05:40 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let carbon = new First_twenty.carbon in
  let sulfur = new First_twenty.sulfur in
  let hydrogen = new First_twenty.hydrogen in
  let oxygen = new First_twenty.oxygen in
  let calcium = new First_twenty.calcium in
  let phosphorus = new First_twenty.phosphorus in
  print_endline carbon#to_string;
  print_endline sulfur#to_string;
  print_endline hydrogen#to_string;
  print_endline oxygen#to_string;
  print_endline calcium#to_string;
  print_endline phosphorus#to_string;
  Printf.printf "Is Sulfur equal to Calcium %B\n" 
    (sulfur#equal calcium);
  Printf.printf "Is Carbon equal to Carbon %B\n" 
    (carbon#equal carbon);
  Printf.printf "Carbon hilton_greater Sulfur %B\n"
    (carbon#hilton_notation_greater sulfur);
  Printf.printf "Hydrogen hilton_greater Carbon %B\n"
    (hydrogen#hilton_notation_greater carbon);
  Printf.printf "Hydrogen hilton_greater Sulfur %B\n"
    (hydrogen#hilton_notation_greater sulfur);
  Printf.printf "Calcium hilton_greater Hydrogen %B\n"
    (calcium#hilton_notation_greater hydrogen);
  Printf.printf "Calcium hilton_greater Oxygen %B\n"
    (calcium#hilton_notation_greater oxygen);
  Printf.printf "Phosphorus hilton_greater Oxygen %B\n"
    (phosphorus#hilton_notation_greater oxygen)
