(* (0,600).........................(800,600)
.                                 .
.                                 .
.                                 .(800,400)
.                                 .
.                                 .
.                                 .
.                                 .
.                                 .
(0,0)..............................(800,0) *)

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

let draw_tree_node node =
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
	| Node (a, Nil, Nil) ->
		let from = (100, 400) in
		let (xfrom, yfrom) = from in
			draw_rectangle (xfrom, yfrom) (xfrom + box_x, yfrom - box_y) ;
			draw_line (xfrom + box_x, yfrom - box_y / 2) (xfrom + 2 * box_x, yfrom + box_y / 2);
			draw_line (xfrom + box_x, yfrom - box_y / 2) (xfrom + 2 * box_x, yfrom - 3 * box_y / 2);
			draw_rectangle(xfrom + box_x * 2, yfrom + box_y) (xfrom + box_x * 3, yfrom);
			draw_rectangle (xfrom + box_x * 2, yfrom - box_y) (xfrom + box_x * 3, yfrom - box_y * 2);
			draw_string_at a (xfrom + box_x / 10, yfrom - box_y/2 - 5);
			draw_string_at "Nil" (xfrom + box_x * 2 + box_x / 10, yfrom + box_y / 2 - 5);
			draw_string_at "Nil" (xfrom + box_x * 2 + box_x / 10, yfrom - box_y * 2 + 5)
	| _ -> () (* This function can only print a single node *)


let main () =
	Graphics.open_graph " 800x600";
	draw_square 100 100 100;
	draw_square 10 10 20;
	draw_square 150 150 80;
	let node = Node ("pouet", Nil, Nil) in
	draw_tree_node node;
	print_char (Graphics.read_key ())

let () = main ()
