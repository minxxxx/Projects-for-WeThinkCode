(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   examples_of_file.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 15:24:33 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/23 17:49:49 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec is_float str i =
	if (String.length str) <= i then
		true
	else
		match String.get str i with
		| '-' | '.' | '0'..'9'						-> is_float str (i + 1)
		| _											-> false

let rec csv_next_len line i (len, next) =
	if (String.length line) <= i then
		(len, next)
	else
		match String.get line i with
		| ',' | ' ' | '\t'							-> csv_next_len line (i + 1) (len, next + 1)
		| _ when next = 0							-> csv_next_len line (i + 1) (len + 1, 0)
		| _											-> (len, next)

let rec csv_line line i =
	let len, next = csv_next_len line i (0, 0) in
	if len = 0 then
		[]
	else
		let sub = String.sub line i len in
		if is_float sub 0 then
			sub::(csv_line line (i + len + next))
		else
			[sub]

let examples_of_line c_in =
	let csv = csv_line (input_line c_in) 0 in
	if (List.length csv) = 0 then
		([||], "")
	else
		let floats = Array.init ((List.length csv) - 1)
			(fun i -> float_of_string (List.nth csv i)) in
		(floats, (List.nth csv  ((List.length csv) - 1)))

let examples_of_file path =
	let res = ref [] in
	begin
		try
			let c_in = open_in path in
			while true do
				res := (!res) @ [(examples_of_line c_in)]
			done
		with
		| End_of_file			-> ()
	end;
	!res

(*
** Test
*)
let print_float_array a =
	print_string "[|";
	for i = 0 to ((Array.length a) - 1) do
		if i > 0 then
			print_string "; ";
		print_float a.(i)
	done;
	print_string "|]"

let rec print_example = function
	| (lst, c)::tail			->
		print_string (c ^ " ; ");
		print_float_array lst;
		print_newline ();
		print_example tail
	| []						-> ()

let main argc argv =
	if argc < 2 then
		failwith "Not enougth argument"
	else
		print_example (examples_of_file argv.(1))

let () =
	try main (Array.length Sys.argv) Sys.argv with
	| Sys_error (msg)
	| Failure (msg)				-> print_endline ("Error: " ^ msg)
	| Invalid_argument (msg)	-> print_endline ("Lol: " ^ msg)
	| _							-> print_endline "Error occur"
