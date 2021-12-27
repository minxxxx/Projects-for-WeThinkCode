(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   reaction.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 16:44:58 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 13:05:20 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual reaction (a:(Molecule.molecule * int) list) (b:(Molecule.molecule * int) list) = object
	method virtual get_start : (Molecule.molecule * int) list
	method virtual get_result : (Molecule.molecule * int) list
	method virtual balance : reaction
	method virtual is_balanced : bool
end
