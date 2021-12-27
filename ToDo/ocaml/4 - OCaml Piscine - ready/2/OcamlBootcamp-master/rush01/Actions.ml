(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Actions.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/14 13:22:28 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/14 17:04:20 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Action =
struct
    type t = EAT | THUNDER | BATH | KILL

    let eat_action action_obj = match (action_obj#get_name) with
        | "Health" -> action_obj#increase 25
        | "Energy" -> action_obj#decrease 10
        | "Hygiene" -> action_obj#decrease 20
        | "Happiness" -> action_obj#increase 5
        | _ -> action_obj

    let thunder_action action_obj = match (action_obj#get_name) with
        | "Health" -> action_obj#decrease 20
        | "Energy" -> action_obj#increase 25
        | "Happiness" -> action_obj#decrease 20
        | _ -> action_obj

    let bath_action action_obj = match (action_obj#get_name) with
        | "Health" -> action_obj#decrease 20
        | "Energy" -> action_obj#decrease 10
        | "Hygiene" -> action_obj#increase 25
        | "Happiness" -> action_obj#increase 5
        | _ -> action_obj

    let kill_action action_obj = match (action_obj#get_name) with
        | "Health" -> action_obj#decrease 20
        | "Energy" -> action_obj#decrease 10
        | "Happiness" -> action_obj#increase 20
        | _ -> action_obj

    let apply_action act lst = match act with
        | EAT -> List.map eat_action lst
        | THUNDER -> List.map thunder_action lst
        | BATH -> List.map bath_action lst
        | KILL -> List.map kill_action lst
end

class action (name : string) =
object (self : 'a)
    val _bar = 100
    val _name = name
    val _pos = (0, 0)
    val _size = (5, 100)

    method decrease amt = match (_bar - amt) with
        | y when y <= 0 -> {< _bar = 0; _name = _name; _pos = _pos; _size = _size >}
        | _ -> {< _bar = (_bar - amt); _name = _name; _pos = _pos; _size = _size>}

    method increase amt = match (_bar + amt) with
        | y when y >= 100 -> {< _bar = 100; _name = _name; _pos = _pos; _size = _size>}
        | _ -> {< _bar = (_bar + amt); _name = _name; _pos = _pos; _size = _size >}

    method is_empty = match _bar with
        | y when y <= 0 -> true
        | _ -> false

    method set_position pos = {< _bar=_bar;_name=_name;_pos=pos;_size=_size >}
    method set_size size = {< _bar=_bar;_name=_name;_pos=_pos;_size=size >}

    method get_value = _bar
    method get_name = _name
    method get_position = _pos
    method get_size = _size

    method to_string = _name ^ " -> " ^ (string_of_int _bar)
end

class actions =
object (self : 'a)
    val _action_list = []

    method apply_action act =
        {< _action_list = (Action.apply_action act _action_list) >}

    method add_action_object (action_obj : action) =
        {< _action_list = (List.append _action_list [action_obj]) >}

    method get_action_list = _action_list
end

(*let () =
  let tmp = ref new actions in
  let print_obj x = print_endline x#to_string in
  List.iter print_obj !tmp#get_action_list;
  print_endline "---------------------";
  tmp := !tmp#add_action_object (new action "Health");
  tmp := !tmp#add_action_object (new action "Energy");
  tmp := !tmp#add_action_object (new action "Happiness");
  tmp := !tmp#add_action_object (new action "Hygiene");
  tmp := !tmp#apply_action Action.EAT;
  List.iter print_obj !tmp#get_action_list;
  print_endline "---------------------";
  tmp := !tmp#apply_action Action.BATH;
  List.iter print_obj !tmp#get_action_list;
  print_endline "---------------------";
  tmp := !tmp#apply_action Action.THUNDER;
  List.iter print_obj !tmp#get_action_list;
  print_endline "---------------------";
  tmp := !tmp#apply_action Action.KILL;
  List.iter print_obj !tmp#get_action_list;
  print_endline "---------------------"*)

(*let () =
  let sleep = new action "sleep" in
  print_endline sleep#to_string;
  print_endline (sleep#decrease 50)#to_string;
  print_endline (sleep#decrease 120)#to_string;
  print_endline ((sleep#decrease 50)#increase 10)#to_string;
  print_endline ((sleep#decrease 50)#increase 90)#to_string;
  Printf.printf "Sleep value : %d\n" (sleep#decrease 20)#get_value;
  Printf.printf "Is sleep empty : %B\n" (sleep#decrease 100)#is_empty;
  Printf.printf "Is sleep empty : %B\n" (sleep#decrease 50)#is_empty*)
