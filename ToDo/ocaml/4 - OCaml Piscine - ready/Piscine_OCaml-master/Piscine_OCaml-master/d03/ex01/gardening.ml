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
			draw_string_at a (xfrom + box_x / 10, yfrom - box_y/2 - 5)

let rec size (tree:'a tree) =
	match tree with
	| Nil -> 0
	| Node (v, left, right) -> 1 + size left + size right

let rec height (tree:'a tree) =
	match tree with
	| Nil -> 0
	| Node (v, left, right) -> 1 + (max (height left) (height right))

let draw_tree (tree:string tree) =
	let rec draw_tree_at tree coords =
		let (xfrom, yfrom) = coords in
		match tree with
		| Nil -> ()
		| Node (v, left, right) -> draw_tree_node (Node (v, left, right)) coords;
			draw_tree_at left (xfrom + box_x * 2, yfrom + box_y);
			draw_tree_at right (xfrom + box_x * 2, yfrom - box_y);
	in
	draw_tree_at tree (100, 400)


let main () =
	Graphics.open_graph " 800x600";
	print_endline "hello, world!";
	let node1 = Node ("pouet", Nil, Nil) in
	let node2 = Node ("pouet2", Nil, Nil) in
	let node3 = Node ("pouet3", node1, node2) in
	let node4 = Node ("pouet4", node3, Nil) in
	let node5 = Node ("pouet5", Nil, Nil) in
	let root = Node ("root", node4, node5) in
	print_string "size of the tree : " ; print_int (size root) ; print_char '\n';
	print_string "height of the tree : " ; print_int (height root) ; print_char '\n';
	draw_tree root;
	draw_tree Nil;
	print_char (Graphics.read_key ())

let () = main ()
