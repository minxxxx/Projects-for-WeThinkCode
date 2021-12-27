(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:07:33 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 17:02:11 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
    let photosynthesis = new Reactions.photosynthesis in
    let aerobic_respiration = new Reactions.aerobic_respiration in
    Printf.printf "Is photosynthesis balanced : %B\n" 
        photosynthesis#is_balanced;
    Printf.printf "Is Aerobic Respiration balanced : %B\n" 
        aerobic_respiration#is_balanced
