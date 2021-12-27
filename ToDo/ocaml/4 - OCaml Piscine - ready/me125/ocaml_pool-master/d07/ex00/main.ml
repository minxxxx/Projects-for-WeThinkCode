(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 11:39:13 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 15:34:06 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let p = new People.people in
	p#talk;
	print_endline ("Whiiii... " ^ (p#to_string));
	print_endline "Now die";
	p#die
