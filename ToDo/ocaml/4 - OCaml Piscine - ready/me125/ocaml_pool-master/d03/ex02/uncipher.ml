(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   uncipher.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 19:23:33 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 19:00:59 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rotc n c = char_of_int (((int_of_char c) + n + 128) mod 128)

let unrot42 str = String.map (rotc (-42)) str

let uncaesar n str = String.map (rotc (-n)) str

let rec ft_uncrypt (str:string) fn =
	match fn with
	| []				-> str
	| head::tail		-> head (ft_uncrypt str tail)
