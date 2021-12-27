(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Board.mli                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 11:56:53 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 21:06:23 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t

val create_new_board : int -> t

val print_board : t -> unit

val get_row : t -> int -> string

val change_block_status : t -> int -> int -> Block.status_type -> t

val get_winner : t -> string

val is_valid_move : t -> int -> int -> bool

val get_grid_owner : int -> t -> string
