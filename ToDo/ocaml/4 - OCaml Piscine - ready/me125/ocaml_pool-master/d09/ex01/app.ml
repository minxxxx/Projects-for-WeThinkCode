(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   app.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 15:35:40 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 15:49:20 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type project = string * string * int

let zero = ("", "", 0)

let create name grade :project = (name, (if grade > 80 then "success" else "failed"), grade)

let combine (a1, _, n1) (a2, _, n2) :project = create (a1 ^ a2) ((n1 + n2) / 2)

let fail (a, _, _) :project = (a, "failed", 0)

let success (a, _, _) :project = (a, "success", 80)
