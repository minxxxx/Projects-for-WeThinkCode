(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Atom.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:07:09 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 23:30:25 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual atom =
object (self : 'a)
    method virtual name : string
    method virtual symbol : string
    method virtual atomic_number : int

    method to_string =
      self#name ^ " (" ^ self#symbol ^ ") with atomic number " ^
      (string_of_int self#atomic_number)

    method equal (that : 'a) =
      (self#name = that#name)

    method hilton_notation_greater (that : 'a) =
      match (self#symbol, that#symbol) with
        | ("C", _) -> true
        | (_, "C") -> false
        | ("H", _) -> true
        | (_, "H") -> false
        | (symbol1, symbol2) -> not (symbol1 > symbol2)
end
