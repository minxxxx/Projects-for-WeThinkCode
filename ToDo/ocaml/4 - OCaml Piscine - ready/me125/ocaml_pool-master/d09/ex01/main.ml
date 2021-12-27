(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 15:41:10 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 15:53:19 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let print_proj (p:App.project) =
	let name, comment, grade = p in
	print_endline (name ^ ": { comment: " ^ comment ^ ", grade: " ^ (string_of_int grade) ^ " }")

let () =
	let proj = App.create "Nibbler" 109 in
	print_proj proj;
	print_proj (App.fail proj);
	let proj = App.combine (App.zero) (App.create "get_next_line" 58) in
	print_proj proj;
	print_proj (App.success proj);
