(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Creature.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/14 15:22:30 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/14 17:06:39 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Creature =
struct
    let add_health actions =
      let tmp = actions#add_action_object 
          (((new Actions.action "Health")#set_position (0, 0))#set_size (100, 5)) in
      tmp
        
    let add_energy actions =
      let tmp = actions#add_action_object 
          (((new Actions.action "Energy")#set_position (0, 0))#set_size (100, 5)) in
      add_health tmp

    let add_happines actions =
      let tmp = actions#add_action_object 
          (((new Actions.action "Happiness")#set_position (0, 0))#set_size (100, 5)) in
      add_energy tmp

    let add_hygiene actions =
      let tmp = actions#add_action_object 
          (((new Actions.action "Hygiene")#set_position (0, 0))#set_size (100, 5)) in
      add_happines tmp

    let build_action_list () =
        let actions = new Actions.actions in
        add_hygiene actions   
end

class creature (image : string) =
object (self : 'a)
    val _image = image
    val _actions = Creature.build_action_list ()

    method get_actions = 
      _actions#get_action_list
    method apply_action action = match action with
      | "eat" -> {< _image = _image; _actions = (_actions#apply_action Actions.Action.EAT) >}
      | "thunder" -> {< _image = _image; _actions = (_actions#apply_action Actions.Action.THUNDER) >}
      | "bath" -> {< _image = _image; _actions = (_actions#apply_action Actions.Action.BATH) >}
      | "kill" -> {< _image = _image; _actions = (_actions#apply_action Actions.Action.KILL) >}
      | _ -> self
end

let () =
  let toy = new creature "test" in
  let print_action x = print_endline x#to_string in
  List.iter print_action toy#get_actions
