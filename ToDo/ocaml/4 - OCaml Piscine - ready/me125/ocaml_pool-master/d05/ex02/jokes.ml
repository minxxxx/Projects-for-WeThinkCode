(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 13:13:20 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/22 14:00:26 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let jokes = [|
		"yo mama so fat she dont fit in da array";
		"Knock, knock. Who's there? Daisy. Daisy who? Daisy me rollin', they hatin'!";
		"Why do birds fly south for the winter? Because its too far to walk";
		"What's the difference between a snow man and a snow woman? Snow balls";
		"Did you hear about the guy who invented the knock knock joke? He won the 'no-bell' prize";
		"What is a duck's favourite drug? Quack";
		|] in
	Random.self_init ();
	print_endline (jokes.(Random.int (Array.length jokes)))
