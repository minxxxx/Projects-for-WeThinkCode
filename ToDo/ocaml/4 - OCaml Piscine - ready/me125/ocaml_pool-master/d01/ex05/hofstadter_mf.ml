(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   hofstadter_mf.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 10:26:51 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/16 10:33:27 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec hfs_f n =
	if n = 0 then
		1
	else if n > 0 then
		n - (hfs_m (hfs_f (n - 1)))
	else
		-1
and hfs_m n =
	if n = 0 then
		0
	else if n > 0 then
		n - (hfs_f (hfs_m (n - 1)))
	else
		-1

(*
** Test
*)
let () =
	print_endline "m";
	print_int (hfs_m 0); print_char '\n';
	print_int (hfs_m 1); print_char '\n';
	print_int (hfs_m 2); print_char '\n';
	print_int (hfs_m 3); print_char '\n';
	print_int (hfs_m 4); print_char '\n';
	print_endline "f";
	print_int (hfs_f 0); print_char '\n';
	print_int (hfs_f 1); print_char '\n';
	print_int (hfs_f 2); print_char '\n';
	print_int (hfs_f 3); print_char '\n';
	print_int (hfs_f 4); print_char '\n';
