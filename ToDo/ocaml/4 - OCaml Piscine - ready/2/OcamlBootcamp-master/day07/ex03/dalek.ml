(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   dalek.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 13:40:38 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 15:06:59 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class dalek =
    object (self)
        val _person = let name_ext = Random.self_init (); String.make 3 'p' in
                    let generate_char c = char_of_int ((Random.int 26) + 65) in
                    let name = "Dalek" ^ String.map generate_char name_ext in
                    new People.people name

        val mutable _shield = true

        method to_string = 
            _person#to_string ^ "\nShield : " ^ (string_of_bool _shield)

        method talk = 
            let phrase = [|"Explain! Explain!";"Exterminate! Exterminate!";
               "I obey!";"You are the Doctor! You are the enemy of the Daleks!"|] in
            let rand = Random.int 4 in
            print_endline phrase.(rand)

        method exterminate (person : People.people) =
            _shield <- (_shield = false);
            print_endline (_person#get_name ^ " attacks " ^ person#get_name)

        method take_damage damage = match _shield with
            | true -> self
            | false -> {< _person = (_person#change damage); _shield = _shield >}

        method die = print_endline "Emergency Temporal Shift!"
                
    end
