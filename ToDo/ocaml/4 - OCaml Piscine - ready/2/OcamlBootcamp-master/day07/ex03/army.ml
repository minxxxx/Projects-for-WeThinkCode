(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   army.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 15:12:42 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 15:39:26 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a] army =
    object (self)
        val _group : 'a list = []

        method add member =
          let rec loop group = match group with
                | [] -> [member]
                | head::next -> head::(loop next) in
          let new_group = loop _group in
          {< _group = new_group >}

        method delete =
          let remove_head group = match group with
                | [] -> []
                | head::next -> next in
          {<_group = (remove_head _group)>}

        method talk =
          let rec loop group = match group with
                | [] -> ()
                | head::next -> head#talk; loop next in
          print_endline "*************************";
          loop _group;
          print_endline "_________________________"

        method get_group = _group
    end
