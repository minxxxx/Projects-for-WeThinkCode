(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   people.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 12:43:26 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 12:52:07 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class people name =
    object (self)
        initializer print_endline "This is who I am, right here, right now!"

        val _name = name
        val _hp = 100

        method to_string = _name ^ " : " ^ (string_of_int _hp)
        method talk = print_endline ("I’m " ^ _name ^ "! Do you know the Doctor?")
        method die = print_endline "Aaaarghh!"
    end
