(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   set.ml                                             :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 18:10:45 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 19:00:09 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a t = 'a list

let return a :'a t = [a]

let of_list a :'a t = a
let to_list (a:'a t) :'a list = a

let null :'a t = []

let exists (a:'a t) f =
	let rec loop a' =
		match a' with
		| []			-> false
		| head::tail	-> (f head) || (loop tail)
	in
	loop a

let union (a:'a t) (b:'a t) =
	let rec loop a' acc =
		match a' with
		| []			-> acc
		| head::tail	-> loop tail (if exists acc (fun a -> a = head) then acc else head::acc)
	in
	loop a b

let bind (a:'a t) f =
	let rec loop a' acc =
		match a' with
		| []			-> acc
		| head::tail	-> loop tail (union (f head) acc)
	in
	loop a []

let inter (a:'a t) (b:'a t) :'a t =
	let rec loop a' b' acc =
		match a' with
		| []			-> acc
		| head::tail	-> loop tail b' (if exists b' (fun a -> a = head) then head::acc else acc)
	in
	(loop a b []) @ (loop b a [])

let diff (a:'a t) (b:'a t) :'a t =
	let rec loop a' b' acc =
		match a' with
		| []			-> acc
		| head::tail	-> loop tail b' (if exists b' (fun a -> a = head) then acc else head::acc)
	in
	(loop a b []) @ (loop b a [])

let rec foreach (a:'a t) f =
	match a with
	| []				-> ()
	| head::tail		-> f head; foreach tail f

let for_all (a:'a t) f =
	let rec loop a' =
		match a' with
		| []			-> true
		| head::tail	-> (f head) && (loop tail)
	in
	loop a
