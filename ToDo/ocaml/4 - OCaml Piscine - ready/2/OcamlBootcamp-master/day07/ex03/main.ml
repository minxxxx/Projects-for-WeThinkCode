(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 12:59:30 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 15:48:14 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec destroy army =
    army#talk;
    match (List.length army#get_group) with
    | 0 -> ()
    | _ -> destroy army#delete

let rec create army count member =
    army#talk;
    match count with
    | y when y < 1 -> destroy army
    | _ -> create (army#add member) (count - 1) member

let () =
  create (new Army.army) 2 (new People.people "John");
  create (new Army.army) 4 (new Doctor.doctor "Who" 45 (new People.people "John"));
  create (new Army.army) 6 (new Dalek.dalek)
