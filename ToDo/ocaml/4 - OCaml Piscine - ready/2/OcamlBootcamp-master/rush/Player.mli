(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Player.mli                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 16:00:38 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 16:30:07 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t

val create_new_player : string -> bool -> string -> int -> t

val make_move : t -> Board.t -> (int * int)

val get_name : t -> string

val get_player_status_type : t -> Block.status_type

val get_gui_x_y : int -> int -> (int * int)