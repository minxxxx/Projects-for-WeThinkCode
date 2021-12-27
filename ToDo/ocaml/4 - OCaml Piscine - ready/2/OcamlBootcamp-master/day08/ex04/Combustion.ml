(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Combustion.ml                                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/13 17:06:17 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 18:11:23 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec to_string_eqn m_list = match m_list with
    | [] -> ""
    | (molecule, count)::next -> (string_of_int count) ^ "-" ^ 
            molecule#formula ^ (to_string_eqn next)

let rec count_atoms start_list symbol = match start_list with
    | [] -> 0
    | (molecule, count)::next -> 
            let rec loop a_list = match a_list with
            | [] -> count_atoms next symbol
            | (atom, count1)::tail -> match (atom#symbol = symbol) with
                | true -> (count * count1) + (count_atoms next symbol)
                | false -> loop tail in
            loop molecule#get_atoms

let rec change_coef m_list coef curr index = match m_list with
    | [] -> []
    | (molecule, count)::next ->
            if (curr = index) then
                (molecule, coef)::next
            else
                (molecule, count)::(change_coef next coef (curr + 1) index)

let rec start_balance start_list end_list =
    let start_carbon = count_atoms start_list "C" in
    let end_carbon = count_atoms end_list "C" in
    let start_oxygen = count_atoms start_list "O" in
    let end_oxygen = count_atoms end_list "O" in
    let start_hydrogen = count_atoms start_list "H" in
    let end_hydrogen = count_atoms end_list "H" in
    Printf.printf "C %d : %d\n" start_carbon end_carbon;
    Printf.printf "O %d : %d\n" start_oxygen end_oxygen;
    Printf.printf "H %d : %d\n" start_hydrogen end_hydrogen;
    Printf.printf "--------------------\n";
    if (start_carbon > end_carbon) then
        start_balance start_list 
            (change_coef end_list (start_carbon / end_carbon) 0 0)
    else if (start_carbon < end_carbon) then
        start_balance 
            (change_coef start_list (end_carbon / start_carbon) 0 0)
            end_list
   else if (start_hydrogen > end_hydrogen) then
        start_balance start_list 
            (change_coef end_list (start_hydrogen / end_hydrogen) 0 1)
   else if (start_hydrogen < end_hydrogen) then
        start_balance 
            (change_coef start_list (end_hydrogen / start_hydrogen) 0 1)
            end_list
   else if (start_oxygen > end_oxygen) then
        start_balance start_list 
            (change_coef end_list (start_oxygen / end_oxygen) 0 2)
    else if (start_oxygen < end_oxygen) then
        start_balance 
            (change_coef start_list (end_oxygen / start_oxygen) 0 2)
            end_list
    else
        (start_list, end_list)


class ['b] alkane_combustion (alkanes : 'b list) =
object (self : 'a)
    val _start = List.append  alkanes [new Molecules.oxygen]
    val _end = [new Molecules.carbon_dioxide;new Molecules.water]
    
    method get_start = 
        try
            if (self#is_balanced = false) then
                failwith "Combustion not balance"
             else
                 Reaction.group_molecules _start
        with
        | _ ->  print_endline "Combustion not balance"; []
    
    method get_end = 
        try
            if (self#is_balanced = false) then
                failwith "Combustion not balance"
             else
                 Reaction.group_molecules _end
        with
        | _ ->  print_endline "Combustion not balance"; []
    
    method private balance_compare a_list b_list =
        let rec compare_atom (atom, total)  n_list = match n_list with
            | [] -> false
            | (elem, count)::next -> match (elem#equal atom) with
                | true -> if total = count then true else false
                | false -> compare_atom (atom, total) next in
        let rec loop_atoms n_list = match n_list with
        | [] -> true
        | (a, b)::next -> match (compare_atom (a, b) b_list) with
            | false -> false
            | true -> loop_atoms next in
        loop_atoms a_list

    method balance =
        let group_start = Reaction.group_molecules _start in
        let group_end = Reaction.group_molecules _end in
        start_balance group_start group_end

    method is_balanced =
        self#balance_compare 
            (Reaction.combine_atoms 
                (Reaction.multiply_coeff 
                    (Reaction.group_molecules _start)))
            (Reaction.combine_atoms 
                (Reaction.multiply_coeff 
                     (Reaction.group_molecules _end)))
end
