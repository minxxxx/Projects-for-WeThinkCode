(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sum.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 12:32:05 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 17:27:46 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let sum x y =
    let tmp = ref x in
    tmp := !tmp +. y;
    !tmp

let () =
    let a = sum 2.0 3.0 in
    let b = sum a  1.5 in
    print_endline ("a -> sum 2.0 3.0 : " ^ string_of_float a);
    print_endline ("b -> sum a 1.5 : " ^ string_of_float b)
