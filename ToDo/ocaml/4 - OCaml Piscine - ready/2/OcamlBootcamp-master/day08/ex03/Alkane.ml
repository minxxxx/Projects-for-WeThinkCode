(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Alkane.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/13 08:06:35 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 09:10:06 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let get_alkane_name n = match n with
    | 0 -> ""
    | 1 -> "Methane"
    | 2 -> "Ethane"
    | 3 -> "Propane"
    | 4 -> "Butane"
    | 5 -> "Pentaane"
    | 6 -> "Hexane"
    | 7 -> "Heptane"
    | 8 -> "Octane"
    | 9 -> "Nonane"
    | 10 -> "Decane"
    | 11 -> "Undecane"
    | _ -> "Dodecane"


class alkane (n : int) =
object (self : 'a)
    inherit Molecule.molecule
    val _n = n
    
    method private _atoms =
        let carbon = new First_twenty.carbon in
        let hydrogen = new First_twenty.hydrogen in
        let rec loop count atom (atoms : 'b list) = match count with
            | y when y < 1 -> atoms
            | _ -> loop (count - 1) atom (List.append atoms [atom]) in
        loop ((2 * _n) + 2) hydrogen (loop _n carbon [])

   method name =
       get_alkane_name _n
end
