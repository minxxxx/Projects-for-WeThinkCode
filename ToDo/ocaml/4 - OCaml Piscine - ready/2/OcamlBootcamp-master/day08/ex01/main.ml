(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:07:33 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 23:34:02 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let tnt = new Molecules.trinitrotoluene in
  let water = new Molecules.water in
  let carbon_dioxide = new Molecules.carbon_dioxide in
  let sulfuric_acid = new Molecules.sulfuric_acid in
  let ammonium_nitrate = new Molecules.ammonium_nitrate in
  let soduim_chloride = new Molecules.soduim_chloride in
  let tartrazine_dye = new Molecules.tartrazine_dye in
  print_endline tnt#to_string;
  print_endline water#to_string;
  print_endline carbon_dioxide#to_string;
  print_endline sulfuric_acid#to_string;
  print_endline ammonium_nitrate#to_string;
  print_endline soduim_chloride#to_string;
  print_endline tartrazine_dye#to_string;
  Printf.printf "Tnt equal to Water : %B\n"
    (tnt#equal water);
  Printf.printf "Water equal to Water : %B\n"
    (water#equal water)
  
