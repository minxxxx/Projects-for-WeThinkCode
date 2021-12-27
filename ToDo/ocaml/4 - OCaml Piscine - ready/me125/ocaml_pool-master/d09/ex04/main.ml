(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 18:43:14 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 19:01:30 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let s1 = Lol.of_list ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"; "i"] in
	let s2 = Lol.of_list ["f"; "g"; "h"; "i"; "j"; "k"; "l"; "m"; "n"] in
	print_string "Lol1: "; Lol.foreach (Lol.to_list s1) print_string; print_newline ();
	print_string "Lol2: "; Lol.foreach (Lol.to_list s2) print_string; print_newline ();
	print_string "union: "; Lol.foreach (Lol.to_list (Lol.union s1 s2)) print_string; print_newline ();
	print_string "inter: "; Lol.foreach (Lol.to_list (Lol.inter s1 s2)) print_string; print_newline ();
	print_string "diff: "; Lol.foreach (Lol.to_list (Lol.diff s1 s2)) print_string; print_newline ();
	print_string "bind a -> z: "; Lol.foreach (Lol.to_list (Lol.bind s1 (fun a -> if a = "a" then Lol.return "z" else Lol.return a))) print_string; print_newline ();
	print_string "bind a -> z: "; Lol.foreach (Lol.to_list (Lol.bind s2 (fun a -> if a = "a" then Lol.return "z" else Lol.return a))) print_string; print_newline ();
	print_string "for_all <>a: "; print_string (string_of_bool (Lol.for_all s1 (fun a -> a <> "a"))); print_newline ();
	print_string "for_all <>a: "; print_string (string_of_bool (Lol.for_all s2 (fun a -> a <> "a"))); print_newline ();
