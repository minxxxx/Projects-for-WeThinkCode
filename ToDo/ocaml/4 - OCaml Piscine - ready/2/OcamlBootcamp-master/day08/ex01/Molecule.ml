(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Molecule.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 22:15:04 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 23:32:52 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual molecule =
object (self : 'a)
    method private virtual _atoms : 'b list
    method private hiltonAtoms = 
        let rec add_atom hiltonList atom = match hiltonList with
          | [] -> [(atom, 1)]
            | (elem, count)::next -> match (elem#equal atom) with
                | true -> (elem, (count + 1))::next
                | false -> match (elem#hilton_notation_greater atom) with
                    | true -> (elem, count)::(add_atom next atom)
                    | false -> (atom, 1)::(elem, count)::next in
        let rec loop atomList hiltonList = match atomList with
            | [] -> hiltonList
            | atom::next -> loop next (add_atom hiltonList atom) in
        loop self#_atoms []

    method virtual name : string
    method formula =
        let rec loop hiltonList = match hiltonList with
            | [] -> ""
            | (elem, count)::next ->
                elem#symbol ^ (string_of_int count) ^
                    (loop next) in
        loop self#hiltonAtoms

    method to_string = 
      self#name ^ " with formula " ^ self#formula

    method equal (that : 'a) =
      (self#name = that#name) && (self#formula = that#formula)

end
