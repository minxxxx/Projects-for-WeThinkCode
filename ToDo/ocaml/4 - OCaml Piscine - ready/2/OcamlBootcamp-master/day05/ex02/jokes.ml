(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 10:44:04 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 11:17:46 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let create_jokes () =
    let jokes = Array.make 8 "" in
    Array.set jokes 0 "What’s the difference between a G-spot and a golf ball?
    A guy will actually search for a golf ball.";
    Array.set jokes 1 "Why was the guitar teacher arrested?
    For fingering a minor.";
    Array.set jokes 2 "What do the Mafia and pussies have in common?
    One slip of the tongue, and you’re in deep shit.";
    Array.set jokes 3 "What do a penis and a Rubik’s Cubes have in common?
    The more you play with it, the harder it gets.";
    Array.set jokes 4 "What do a woman and a bar have in common?
    Liquor in the front, poker in the back.";
    Array.set jokes 5 "What do you call two jalapeños getting it on?
    Fucking hot!";
    Array.set jokes 6 "What did the O say to the Q?
    Dude, your dick’s hanging out.";
    Array.set jokes 7 "How is a push-up bra like a bag of chips?
    As soon as you open it, you realize it’s half empty.";
    jokes

let () =
    let jokes = create_jokes () in
    let rand = Random.self_init (); Random.int 8 in
    print_endline jokes.(rand)
