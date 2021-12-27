(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   watchover.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 15:24:03 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 16:51:29 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type hour = int

let zero:hour = 12

let add (a:hour) (b:hour) :hour =
	let tmp = (a + b) mod zero in
	if tmp <= 0 then
		zero + tmp
	else
		tmp

let sub (a:hour) (b:hour) :hour = add a (-b)

let to_int (a:hour) :int = a
