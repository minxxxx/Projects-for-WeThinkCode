(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_ref.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 10:17:34 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 17:38:54 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a ft_ref = {mutable contents : 'a;}

let return elem = {contents = elem}

let get elem_ref = elem_ref.contents

let set elem_ref elem = elem_ref.contents <- elem

let bind elem_ref f = f (get elem_ref)

let float_to_string x = {contents = (string_of_float x)}

let () =
    let a = return 1.5 in
    print_endline ("after return : a -> " ^ (string_of_float (get a)));
    set a 2.5;
    print_endline ("after return : a -> " ^ (string_of_float (get a)));
    let b = bind a float_to_string in
    print_endline ("after bind : b -> " ^ (get b))

