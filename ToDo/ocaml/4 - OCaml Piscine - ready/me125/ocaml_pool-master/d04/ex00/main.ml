(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 14:04:02 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 15:13:01 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec test = function
	| []			-> print_newline ()
	| head::tail	-> print_string (Color.toString head); test tail

let rec testVerbose = function
	| []				-> print_newline ()
	| head::sec::tail	-> print_string ((Color.toStringVerbose head) ^ ", "); testVerbose (sec::tail)
	| head::tail		-> print_string (Color.toStringVerbose head); testVerbose tail

let () =
	test (Color.all);
	testVerbose (Color.all)
