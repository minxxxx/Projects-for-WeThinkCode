(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Color.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/09 08:27:07 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/09 12:16:16 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type COLOR =
sig
    type t = Spade | Heart | Diamond | Club

    val all : t list

    val toString : t -> string
    val toStringVerbose : t -> string
end

module Color : COLOR =
    struct
        type t = Spade | Heart | Diamond | Club

        let (all : t list) = [Spade;Heart;Diamond;Club]

        let toString : (t -> string) = fun (elem : t) -> match elem with
            | Spade -> "S"
            | Heart -> "H"
            | Diamond -> "D"
            | Club -> "C"

        let toStringVerbose : (t -> string) = fun (elem : t) -> match elem with
            | Spade -> "Spade"
            | Heart -> "Heart"
            | Diamond -> "Diamond"
            | Club -> "Club"
    end
