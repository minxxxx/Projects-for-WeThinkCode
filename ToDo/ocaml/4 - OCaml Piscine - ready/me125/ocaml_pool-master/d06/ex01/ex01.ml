(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex01.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/23 13:35:02 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/24 19:23:34 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let djb2 str =
	let str_len = String.length str in
	let rec loop i acc =
		if i >= str_len then
			acc
		else
			loop (i + 1) ((acc lsl 5) + acc + int_of_char ((String.get str i)))
	in
	loop 0 5381

module StringHashtbl =
	Hashtbl.Make (
		struct
			type t = string
			let hash = djb2
			let equal = (=)
		end)

let () =
	let ht = StringHashtbl.create 5 in
	let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
	let pairs = List.map (fun s -> (s, String.length s)) values in
	List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
	StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
