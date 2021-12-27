(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   btree.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 11:04:22 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/19 14:01:18 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let max a b = if a < b then b else a
let abs a = if a < 0 then (-a) else a

let rec height = function
	| Nil					-> 1
	| Node (_, Nil, Nil)	-> 2
	| Node (_, a, Nil)		-> 1 + (height a)
	| Node (_, Nil, b)		-> 1 + (height b)
	| Node (_, a, b)		-> 1 + (max (height a) (height b))

let rec is_bst = function
	| Nil											-> true
	| Node (_, Nil, Nil)							-> true
	| Node (v, (Node (v', _, _) as a), (Node (v'', _, _) as b))	->
		(v' < v) && (v < v'') && (is_bst a) && (is_bst b)
	| Node (v, (Node (v', _, _) as a), Nil)			-> (v > v') && (is_bst a)
	| Node (v, Nil, (Node (v', _, _) as b))			-> (v < v') && (is_bst b)

let is_balanced t =
	let rec t_balanced = function
		| Nil					-> true
		| Node (_, Nil, Nil)	-> true
		| Node (_, a, Nil)		-> ((height a) <= 1)
		| Node (_, Nil, b)		-> ((height b) <= 1)
		| Node (_, a, b)		-> (t_balanced a) || (t_balanced b)
	in
	(t_balanced t) && (is_bst t)

let rec is_perfect = function
	| Nil											-> true
	| Node (_, a, b) when (height a) = (height b)	-> (is_perfect a) && (is_perfect b)
	| _												-> false

let rec search_bst t v =
	match t with
	| Nil							-> false
	| Node (v', a, b) when v' = v	-> true
	| Node (v', a, b) when v' > v	-> search_bst a v
	| Node (v', a, b)				-> search_bst b v

let rec add_bst t v =
	match t with
	| Nil							-> Node (v, Nil, Nil)
	| Node (v', _, _) when v' = v	-> failwith "Already exists"
	| Node (v', a, b) when v' > v	-> Node (v', (add_bst a v), b)
	| Node (v', a, b)				-> Node (v', a, (add_bst b v))

let rec min_bst = function
	| (Node (_, Nil, _) as a)		-> a
	| Node (_, a, _)				-> min_bst a
	| _								-> Nil

let rec merge_dst a b v =
	match (a, b) with
	| (a', Nil)							-> a'
	| (Nil, b')							-> b'
	| _									->
		match (min_bst b) with
		| Nil					-> failwith "Not bst"
		| Node (v, _, _)		-> Node (v, a, delete_bst b v)

and delete_bst t v =
	match t with
	| Node (v', Nil, Nil) when v' <> v	-> Nil
	| Node (v', a, b) when v' = v		-> merge_dst a b v
	| Node (v', a, b) when v' > v		-> Node (v', delete_bst a v, b)
	| Node (v', a, b)					-> Node (v', a, delete_bst b v)
	| _									-> failwith "Does not exists"

(*
** Main from ex01
*)
let case_width = 60
let case_height = 25
let case_margin = 10
let case_padding = case_width / 2
let case_offset = 150
let initial_x = 50
let initial_y = 750

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
	| Nil					-> 1
	| Node (_, Nil, Nil)	-> 3
	| Node (_, a, Nil)		-> 1 + (size a)
	| Node (_, Nil, b)		-> 1 + (size b)
	| Node (_, a, b)		-> 1 + (size a) + (size b)

let max a b = if a < b then b else a

let rec height = function
	| Nil					-> 1
	| Node (_, Nil, Nil)	-> 2
	| Node (_, a, Nil)		-> 1 + (height a)
	| Node (_, Nil, b)		-> 1 + (height b)
	| Node (_, a, b)		-> 1 + (max (height a) (height b))

let draw_tree t =
	let rec draw_next t x y =
		let h = (int_of_float (2. ** float ((height t) - 2))) * (case_height / 2 + case_margin) in
		draw_rect x y case_width case_height;
		match t with
		| Nil				-> draw_string x y "Nil"
		| Node (v, a, b)	->
			draw_string x y (string_of_int v);
			draw_line (x + case_padding, y) (x + case_offset - case_padding, y + h);
			draw_next a (x + case_offset) (y + h);
			draw_line (x + case_padding, y) (x + case_offset - case_padding, y - h);
			draw_next b (x + case_offset) (y - h)
	in
	draw_next t initial_x initial_y

(*
** Test
*)
let print_bool a = print_string (if a then "true" else "false")

let test t =
	print_string "BST: "; print_bool (is_bst t); print_char '\n';
	print_string "balanced: "; print_bool (is_balanced t); print_char '\n';
	print_string "perfect: "; print_bool (is_perfect t); print_char '\n';
	print_string "search 25: "; print_bool (search_bst t 25); print_newline ()

let test_graph t =
	Graphics.open_graph " 1500x1500";
	draw_tree t

let rec pause () = pause ()

let () =
	let tree = add_bst Nil 1 in
	let tree = add_bst tree 2 in
	let tree = add_bst tree 0 in
	print_endline "---------";
	test tree;
	let tree = add_bst tree 5 in
	let tree = add_bst tree 18 in
	let tree = add_bst tree 8 in
	let tree = add_bst tree 9 in
	let tree = add_bst tree 20 in
	let tree = add_bst tree (-42) in
	let tree = add_bst tree 17 in
	print_endline "---------";
	test tree;
	print_endline "---------";
	let tree = delete_bst tree 8 in
	let tree = delete_bst tree 17 in
	let tree = delete_bst tree 1 in
	let tree = add_bst tree 25 in
	let tree = add_bst tree (-100) in
	let tree = add_bst tree (-1) in
	test tree;
	print_endline "---------";
	test_graph tree;
	pause ();
