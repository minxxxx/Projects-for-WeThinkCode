type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let box_x = 50
let box_y = 25

let draw_square x y size =
	let draw_rectangle c1 c2 =
		let (x1,y1) = c1 in
		let (x2, y2) = c2 in
			Graphics.moveto x1 y1;
			Graphics.lineto x1 y2;
			Graphics.lineto x2 y2;
			Graphics.lineto x2 y1;
			Graphics.lineto x1 y1
	in
	draw_rectangle (x - size / 2, y - size / 2) (x + size / 2, y + size / 2)

let draw_tree_node node from =
	let draw_line c1 c2 =
		let (x1,y1) = c1 in
		let (x2, y2) = c2 in
			Graphics.moveto x1 y1;
			Graphics.lineto x2 y2
	in
	let draw_rectangle c1 c2 =
		let (x1,y1) = c1 in
		let (x2, y2) = c2 in
			Graphics.moveto x1 y1;
			Graphics.lineto x1 y2;
			Graphics.lineto x2 y2;
			Graphics.lineto x2 y1;
			Graphics.lineto x1 y1
	in
	let draw_string_at str coords =
		let (x, y) = coords in
			Graphics.moveto x y;
			Graphics.draw_string str
	in
	match node with
	| Nil -> ()
	| Node (a, b, c) ->
		let (xfrom, yfrom) = from in
			draw_rectangle (xfrom, yfrom) (xfrom + box_x, yfrom - box_y) ;
			if (b != Nil) then
				draw_line (xfrom + box_x, yfrom - box_y / 2) (xfrom + 2 * box_x, yfrom + box_y / 2);
			if (c != Nil) then
				draw_line (xfrom + box_x, yfrom - box_y / 2) (xfrom + 2 * box_x, yfrom - 3 * box_y / 2);
			draw_string_at (string_of_int a) (xfrom + box_x / 10, yfrom - box_y/2 - 5)

let rec size (tree:'a tree) =
	match tree with
	| Nil -> 0
	| Node (v, left, right) -> 1 + size left + size right

let rec height (tree:'a tree) =
	match tree with
	| Nil -> 0
	| Node (v, left, right) -> 1 + (max (height left) (height right))

let draw_tree (tree:int tree) =
	let rec draw_tree_at tree coords =
		let (xfrom, yfrom) = coords in
		match tree with
		| Nil -> ()
		| Node (v, left, right) -> draw_tree_node (Node (v, left, right)) coords;
			draw_tree_at left (xfrom + box_x * 2, yfrom + box_y);
			draw_tree_at right (xfrom + box_x * 2, yfrom - box_y);
	in
	draw_tree_at tree (100, 400)

let rec is_bst (tree:'a tree) =
	let check_right left right v =
	match right with
		| Nil -> true
		| Node (vr, lr, rr) ->
		if (vr <= v) then
			false
		else
			is_bst left && is_bst right
	in
	match tree with
	| Nil -> true
	| Node (v, left, right) ->
		match left with
		| Nil -> check_right left right v
		| Node (vl, ll, rl) ->
			if (vl >= v) then
				false
			else
				check_right left right v

let is_perfect tree =
	let h = height tree in
	let rec traverse tree n =
		match tree with
		| Nil -> n = h
		| Node (v, left, right) -> if (left = Nil && right <> Nil) || (left <> Nil && right = Nil)
							then false
							else begin traverse left (n + 1) && traverse right (n + 1) end
	in
	traverse tree 0

let is_balanced tree =
	let h = height tree in
	let rec traverse tree n =
		match tree with
		| Nil -> n - h >= (-1) && n - h <= 1
		| Node (v, left, right) -> traverse left (n + 1) && traverse right (n + 1)
	in
	is_bst tree && traverse tree 0

let rec search_bst tree value =
	if is_bst tree = false then
		failwith "search_bst takes a bst as parameter"
	else
	begin
		match tree with
		| Nil -> false
		| Node (v, left, right) ->
			if v = value then
				true
			else
				search_bst left value || search_bst right value
	end

let rec add_bst tree value =
	if is_bst tree = false then
		failwith "add_bst takes a bst as parameter"
	else
	begin
		match tree with
			| Nil -> Nil
			| Node (v, Node (vl, ll, rl), Node (vr, lr, rr)) ->
				if (value = v || value = vl || value = vr) then
					failwith "The value is already in the bst. Can't add it or it won't be a bst anymore"
				else if value < v then
					Node (v, add_bst (Node (vl, ll, rl)) value, Node (vr, lr, rr))
				else
					Node (v, Node (vl, ll, rl), add_bst (Node (vr, lr, rr)) value)
			| Node (v, Nil, Node (vr, lr, rr)) ->
				if (value = v || value = vr) then
					failwith "The value is already in the bst. Can't add it or it won't be a bst anymore"
				else if value < v then
					Node (v, Node (value, Nil, Nil), Node (vr, lr, rr))
				else
					Node (v, Nil, add_bst (Node (vr, lr, rr)) value)
			| Node (v, Node (vl, ll, rl), Nil) ->
				if value = v || value = vl then
					failwith "The value is already in the bst. Can't add it or it won't be a bst anymore"
				else if value < v then
					Node (v, add_bst (Node (vl, ll, rl)) value, Nil)
				else
					Node (v, Node (vl, ll, rl), Node (value, Nil, Nil))
			| Node (v, Nil, Nil) ->
				if value = v then
					failwith "The value is already in the bst. Can't add it or it won't be a bst anymore"
				else if value < v then
					Node(v, Node (value, Nil, Nil), Nil)
				else
					Node (v, Nil, Node (value, Nil, Nil))
	end

(*
let rec del_bst tree value =
	if is_bst tree = false then
		failwith "del_bst takes a bst as parameter"
	else if search_bst tree value = false then
		failwith "The value was not found in the tree"
	else
	begin
		match tree with
		| Nil -> Nil
		| Node (v, Node(vl, ll, rl), Node(vr, lr, rr)) ->
			if v = value then (* The root of the tree is the requested value *)
				Nil
			else if vl = value then
				delete
			else if vr = value then
				Nil
			else
				Nil
		| Node (v, Nil, Node(vr, lr, rr)) -> Nil
		| Node (v, Node(vl, ll, rl), Nil) -> Nil
		| Node (v, Nil, Nil) -> Nil
	end
*)

let main () =
	Graphics.open_graph " 800x600";
	let node1 = Node (1, Nil, Nil) in
	let node2 = Node (3, Nil, Nil) in
	let node3 = Node (2, node1, node2) in
	let node4 = add_bst node3 7 in
	print_endline ("is bst ? " ^ string_of_bool (is_bst node4));
	print_endline ("is perfect ? " ^ string_of_bool (is_perfect node4));
	print_endline ("is balanced ? " ^ string_of_bool (is_balanced node4));
	print_endline ("1 in tree ? " ^ string_of_bool (search_bst node4 1));
	draw_tree node4;
	print_char (Graphics.read_key ());
	Graphics.clear_graph();

	print_endline "";
	let node1 = Node (1, Nil, Nil) in
	let node2 = Node (3, Nil, Nil) in
	let node3 = Node (2, node1, node2) in
	let node4 = Node (4, node3, Nil) in
	let node5 = Node (6, Nil, Nil) in
	let node6 = Node (5, node4, node5) in
	let root =  add_bst node6 7 in
	print_endline ("is bst ? " ^ string_of_bool (is_bst root));
	print_endline ("is perfect ? " ^ string_of_bool (is_perfect root));
	print_endline ("is balanced ? " ^ string_of_bool (is_balanced root));
	print_endline ("1 in tree ? " ^ string_of_bool (search_bst root 1));
	draw_tree root;
	print_char (Graphics.read_key ());
	Graphics.clear_graph();

	print_endline "";
	let node3 = Node (2, Nil, Nil) in
	let node4 = Node (4, node3, Nil) in
	let node6 = Node (6, node4, Nil) in
	let root =  add_bst node6 5 in
	print_endline ("is bst ? " ^ string_of_bool (is_bst root));
	print_endline ("is perfect ? " ^ string_of_bool (is_perfect root));
	print_endline ("is balanced ? " ^ string_of_bool (is_balanced root));
	print_endline ("1 in tree ? " ^ string_of_bool (search_bst root 1));
	draw_tree root;
	print_char (Graphics.read_key ());

	print_endline "";
	let node1 = Node (10, Nil, Nil) in
	let node2 = Node (30, Nil, Nil) in
	let node3 = Node (20, node1, node2) in
	let node4 = Node (40, node3, Nil) in
	let node5 = Node (60, Nil, Nil) in
	let node6 = Node (50, node4, node5) in
	let node7 =  add_bst node6 8 in
	let node8 =  add_bst node7 33 in
	let root =  add_bst node8 29 in
	print_endline ("is bst ? " ^ string_of_bool (is_bst root));
	print_endline ("is perfect ? " ^ string_of_bool (is_perfect root));
	print_endline ("is balanced ? " ^ string_of_bool (is_balanced root));
	print_endline ("1 in tree ? " ^ string_of_bool (search_bst root 1));
	draw_tree root;
	print_char (Graphics.read_key ());
	Graphics.clear_graph()



let () = main ()
