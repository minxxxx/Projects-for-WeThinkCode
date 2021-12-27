(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   doctor.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 12:59:38 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 14:38:47 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a, 'b, 'c] doctor (name: 'a) (age: 'b) (sidekick: 'c) =
    object (self)
        initializer print_endline "The birth of a Great Doctor. All Hail!!!"

        val _person = new People.people name 
        val _age = age
        val _sidekick = sidekick

        method private draw_tardis = print_endline "####draw tardis####"
        method private regenerate = {< _person = (new People.people _person#get_name); 
                                       _age = _age; _sidekick = _sidekick>}

        method to_string = _person#to_string ^
                            "\nAge : " ^ (string_of_int _age) ^
                            "\nSidekick : " ^ _sidekick#to_string
        method talk = print_endline "Hi! I’m the Doctor!"
        method travel_in_time start arrival = 
            self#draw_tardis;
            {< _person = _person; _age = _age + (arrival - start); _sidekick = _sidekick>}
        method  use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

        method take_damage damage = {< _age = _age; _sidekick = _sidekick; 
                                       _person = (_person#change damage)>}
        method reborn = self#regenerate
        method get_person = _person
    end
