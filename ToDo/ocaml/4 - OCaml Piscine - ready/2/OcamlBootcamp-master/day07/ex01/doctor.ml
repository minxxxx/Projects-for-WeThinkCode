(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   doctor.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 12:59:38 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 16:14:27 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a, 'b, 'c] doctor (name: 'a) (age: 'b) (sidekick: 'c) =
    object (self)
        initializer print_endline "The birth of a Great Doctor. All Hail!!!"

        val _name = name
        val _age = age
        val _sidekick = sidekick
        val _hp = 100

        method private draw_tardis =
            print_endline "\t\t\t\t         =========";
            print_endline "\t\t\t\t         |       |";
            print_endline "\t\t\t\t  ======================";
            print_endline "\t\t\t\t  |                    |";
            print_endline "\t\t\t\t ========================";
            print_endline "\t\t\t\t |                      |";
            print_endline "\t\t\t\t==========================";
            print_endline "\t\t\t\t| POLICE PUBLIC CALL BOX |";
            print_endline "\t\t\t\t|           |            |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t| |   |   | | |    |   | |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t| |   |   | | |    |   | |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t|           |            |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t| |   |   | | |    |   | |";
            print_endline "\t\t\t\t| ---------[|]---------- |";
            print_endline "\t\t\t\t| |   |   | | |    |   | |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t|           |            |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t| |   |   | | |    |   | |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t| |   |   | | |    |   | |";
            print_endline "\t\t\t\t| --------- | ---------- |";
            print_endline "\t\t\t\t|           |            |";
            print_endline "\t\t\t\t=========================="

        method private regenerate = {< _name = _name; _age = _age; 
                                       _sidekick = _sidekick; _hp = 100>}

        method to_string = ("name : " ^ _name ^
                            "\nage : " ^ (string_of_int _age) ^
                            "\nhp : " ^ (string_of_int _hp) ^
                            "\nsidekick : " ^ _sidekick#to_string)
        method talk = print_endline "Hi! I’m the Doctor!"
        method travel_in_time start arrival = 
            self#draw_tardis;
            {< _name = _name; _age = _age + (arrival - start); 
               _sidekick = _sidekick; _hp = _hp>}
        method  use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

        method take_damage damage = {< _name = _name; _age = _age;
                                       _sidekick = _sidekick; _hp = _hp - damage>}
        method reborn = self#regenerate
    end
