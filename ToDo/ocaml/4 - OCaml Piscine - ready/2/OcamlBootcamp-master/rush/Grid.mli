(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Grid.mli                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 00:04:51 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 15:47:31 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t

val create_blocks : int -> int -> Block.t list

val create_new_grid : int -> t

val change_block_status : t -> int -> Block.status_type -> t

val to_string : t -> string

val is_grid_open : t -> bool

val is_block_open : t -> int -> bool

val get_row : t -> int -> string

val get_grid_owner : t -> string

val is_valid_move : t -> int -> bool
