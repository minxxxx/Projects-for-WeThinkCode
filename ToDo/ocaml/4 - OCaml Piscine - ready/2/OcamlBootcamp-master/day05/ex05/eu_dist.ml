(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   eu_dist.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 13:06:43 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 14:31:51 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = float array -> float array -> float

let inner_cal index a_array b_array =
    let res = a_array.(index) -. b_array.(index) in
    res *. res

let (eu_dist : t) = fun a_array b_array ->
    let len = if (Array.length a_array) < (Array.length b_array) then
                Array.length a_array
           else
               Array.length b_array in
    let rec loop index max res = match index with
        | y when y >= max -> res
        | _ -> loop (index + 1) max (res +. (inner_cal index a_array b_array)) in
    let result = loop 0 len 0.0 in
    sqrt result

let () =
    let a_array = [|1.0;2.0;3.0;4.0;5.0|] in
    let b_array = [|5.0;2.5;3.0;0.5|] in
    let c_array = [|0.0;2.5;3.4;4.9;10.2|] in
    print_endline ("a & b -> " ^ (string_of_float (eu_dist a_array b_array)));
    print_endline ("a & c -> " ^ (string_of_float (eu_dist a_array c_array)));
    print_endline ("b & c -> " ^ (string_of_float (eu_dist b_array c_array)));
    print_endline ("b & b -> " ^ (string_of_float (eu_dist b_array b_array)))

