(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 12:59:30 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 13:30:39 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let john = new People.people "John" in
  let doctor = new Doctor.doctor "Who" 42 john in
  print_endline ("Who are you? -> " ^ doctor#to_string);
  print_endline ("Travel from 1994 to 2017 -> " ^ 
                 (doctor#travel_in_time 1994 2017)#to_string);
  doctor#talk;
  doctor#use_sonic_screwdriver;
  let doctor1 = doctor#take_damage 30 in
  print_endline ("Ouch he shot me -> " ^ doctor1#to_string);
  print_endline ("This is a reborn -> " ^ 
                 (doctor1#reborn)#to_string)
