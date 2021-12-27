(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 12:59:30 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 15:08:34 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let print_people person =
  print_endline "******* Person ******";
  print_endline person#to_string;
  person#talk

let print_doctor doctor =
  print_endline "******* Doctor ******";
  print_endline doctor#to_string;
  doctor#talk

let print_dalek dalek =
  print_endline "******* Dalek ******";
  print_endline dalek#to_string;
  dalek#talk

let print_all person doctor dalek =
  print_people person;
  print_doctor doctor;
  print_dalek dalek

let rec play_attacks attacks person doctor dalek = 
    print_all person doctor dalek;
     match attacks with
    | [] -> ()
    | attack::next -> match attack with
        | 1 ->  print_endline "     \n#### doctor attacks daleck ####";
                play_attacks next person doctor (dalek#take_damage 10)
        | 2 ->  print_endline "     \n#### daleck attacks doctor ####";
                dalek#exterminate doctor#get_person;
                play_attacks next person (doctor#take_damage 10) dalek
        | 3 ->  print_endline "     \n#### daleck attacks person ####";
                dalek#exterminate person;
                play_attacks next (person#change 10) doctor dalek
        | _ ->  print_endline "     \n#### doctor, reborn ####";
                play_attacks next person (doctor#reborn) dalek

let () =
  let person = new People.people "John" in
  let doctor = new Doctor.doctor "Who" 42 person in
  let dalek = new Dalek.dalek in
  let attacks = [1;2;1;3;1;2;3;2;1;3;4] in
  play_attacks attacks person doctor dalek;
  print_string "Person dies -> ";
  person#die;
  print_string "Doctor dies -> ";
  doctor#get_person#die;
  print_string "Dalek dies -> ";
  dalek#die
