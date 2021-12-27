(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Color.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 14:03:53 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 14:58:50 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = Spade | Heart | Diamond | Club

let all = [Spade; Heart; Diamond; Club]

let toString = function
	| Spade			-> "S"
	| Heart			-> "H"
	| Diamond		-> "D"
	| Club			-> "C"

let toStringVerbose = function
	| Spade			-> "Spade"
	| Heart			-> "Heart"
	| Diamond		-> "Diamond"
	| Club			-> "Club"
