(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Reaction.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/13 09:19:52 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 18:11:25 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let group_molecules n_list =
    let rec loop new_molecule combined_molecule_list =
        match combined_molecule_list with
         | [] -> [(new_molecule, 1)]
         | (molecule, count)::next -> 
            match (molecule#equal new_molecule) with
                | true -> (molecule, (count + 1))::next
                | false -> (molecule, count)::(loop new_molecule next) in
    let rec loop_list molecules m_list = match molecules with
         | [] -> m_list
         | molecule::next -> loop_list next (loop molecule m_list) in
    loop_list n_list []

let rec multiply_coeff molecule_list = match molecule_list with
    | [] -> []
    | (molecule, coeff)::next ->
            let rec mul_atoms atom_list = match atom_list with
                | [] -> multiply_coeff next
                | (atom, count)::tail ->
                        (atom, (count * coeff))::(mul_atoms tail) in
            mul_atoms molecule#get_atoms

let combine_atoms atom_list =
    let rec add_atom atom n_list = match n_list with
        | [] -> [atom]
        | (elem, count)::next ->
                let (elem1, count1) = atom in
                match (elem#equal elem1) with
                | true -> (elem, (count + count1))::next
                | false -> (elem, count)::(add_atom atom next) in
    let rec loop_atoms a_list n_list = match a_list with
        | [] -> n_list
        | atom::next -> loop_atoms next (add_atom atom n_list) in
    loop_atoms atom_list []

class virtual reaction =
object (self : 'a)
    val virtual _start : Molecule.molecule list
    val virtual _end : Molecule.molecule list
    
    method get_start = group_molecules _start
    method get_end = group_molecules _end
    
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

    method virtual balance : 'a

    method is_balanced =
        self#balance_compare 
            (combine_atoms (multiply_coeff self#get_start))
            (combine_atoms (multiply_coeff self#get_end))
end
