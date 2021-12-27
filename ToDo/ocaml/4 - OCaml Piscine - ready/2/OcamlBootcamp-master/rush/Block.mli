(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Block.mli                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/06 23:10:15 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 10:19:02 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type status_type = Some of string | None
type t

val create_new_block : int -> t

val get_block_status : t -> string

val is_open_block : t -> bool

val change_block_status : t -> status_type -> t

val to_string : t -> string
