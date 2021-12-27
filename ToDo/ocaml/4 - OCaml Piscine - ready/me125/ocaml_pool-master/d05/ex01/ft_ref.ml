(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_ref.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 12:43:54 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 17:36:54 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a ft_ref = {mutable contents : 'a}

let return a :'a ft_ref = {contents = a}

let get a = a.contents

let set a v = a.contents <- v

let bind a f :'b ft_ref = f (get a)

(*
** Test
*)
let test_set r v = set r v

let test_print r = print_endline (get r)

let () =
	let r = return "initial string" in
	test_print r;
	print_endline " --> Set mdr";
	set r "mdr";
	test_print r;
	print_endline " --> Set lol";
	test_set r "lol";
	test_print r;
	print_endline " --> Bind ^";
	let r' = bind r (fun str -> return (str ^ str)) in
	test_print r';
	print_string "old: "; test_print r
