(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:07:33 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 09:10:04 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
    let methane = Alkanes.methane in
    let ethane = Alkanes.ethane in
    let butane = Alkanes.butane in
    let octane = Alkanes.octane in
    let dodecane = Alkanes.dodecane in
    print_endline methane#to_string;
    print_endline butane#to_string;
    print_endline ethane#to_string;
    print_endline octane#to_string;
    print_endline dodecane#to_string;
    Printf.printf "methane equal to ocatane : %B\n"
        (methane#equal octane);
    Printf.printf "methane equal to methane : %B\n"
        (methane#equal methane)
