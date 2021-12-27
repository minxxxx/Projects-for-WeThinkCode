(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:07:33 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 18:11:25 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
    let methane_combustion = new Combustion.alkane_combustion 
        [Alkanes.methane] in
    Printf.printf "Methane input : %s\n" 
        (Combustion.to_string_eqn methane_combustion#get_start);
    Printf.printf "Methane output : %s\n" 
        (Combustion.to_string_eqn methane_combustion#get_end);
    ignore (methane_combustion#balance)
