(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 15:23:41 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 15:30:44 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let test t =
	Printf.printf "[%d] %s (%s)\n" (Value.toInt t) (Value.toString t) (Value.toStringVerbose t)

let () =
	test Value.T2;
	test Value.T3;
	test Value.T4;
	test Value.T5;
	test Value.T6;
	test Value.T7;
	test Value.T8;
	test Value.T9;
	test Value.T10;
	test Value.Jack;
	test Value.Queen;
	test Value.King;
	test Value.As;
	test (Value.previous Value.As);
	test (Value.next Value.King);
