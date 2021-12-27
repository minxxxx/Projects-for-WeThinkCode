(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gardening.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 16:46:13 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 18:54:29 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let case_width = 60
let case_height = 25
let case_margin = 10
let case_padding = case_width / 2
let case_offset = 150
let initial_x = 50
let initial_y = 500

let draw_rect x y w h =
	let x' = x - (w / 2) in
	let y' = y - (h / 2) in
	Graphics.moveto x' y';
	Graphics.lineto (x' + w) y';
	Graphics.lineto (x' + w) (y' + h);
	Graphics.lineto x' (y' + h);
	Graphics.lineto x' y'

let draw_line (x1, y1) (x2, y2) =
	Graphics.moveto x1 y1;
	Graphics.lineto x2 y2

let draw_string x y str =
	let (w, h) = Graphics.text_size str in
	Graphics.moveto (x - (w / 2)) (y - (h / 2));
	Graphics.draw_string str

let rec size = function
	| Nil					-> 0
	| Node (_, Nil, Nil)	-> 1
	| Node (_, a, Nil)		-> 1 + (size a)
	| Node (_, Nil, b)		-> 1 + (size b)
	| Node (_, a, b)		-> 1 + (size a) + (size b)

let max a b = if a < b then b else a

let rec height = function
	| Nil					-> 0
	| Node (_, Nil, Nil)	-> 1
	| Node (_, a, Nil)		-> 1 + (height a)
	| Node (_, Nil, b)		-> 1 + (height b)
	| Node (_, a, b)		-> 1 + (max (height a) (height b))

let draw_tree t =
	let rec draw_next t x y =
		let h = (int_of_float (2. ** float ((height t) - 1))) * (case_height / 2 + case_margin) in
		draw_rect x y case_width case_height;
		match t with
		| Nil				-> draw_string x y "Nil"
		| Node (str, a, b)	->
			draw_string x y str;
			draw_line (x + case_padding, y) (x + case_offset - case_padding, y + h);
			draw_next a (x + case_offset) (y + h);
			draw_line (x + case_padding, y) (x + case_offset - case_padding, y - h);
			draw_next b (x + case_offset) (y - h)
	in
	draw_next t initial_x initial_y

(*
** Test
*)
let rec pause () = pause ()

let test t =
	print_string "Size: "; print_int (size t); print_newline ();
	print_string "Height: "; print_int (height t); print_newline ();
	draw_tree t

let () =
	Graphics.open_graph " 1000x1000";
	test (Node ("1",
		(Node ("11",
			Nil,
			(Node ("112",
				(Node ("1121",
					Nil,
					Nil
				)),
				(Node ("1122",
					Nil,
					Nil
				))
			))
		)),
		(Node ("12",
			(Node ("121",
				Nil,
				Nil
			)),
			(Node ("122",
				(Node ("1221",
					Nil,
					Nil
				)),
				(Node ("1222",
					Nil,
					Nil
				))
			))
		))
	));
	pause ()
