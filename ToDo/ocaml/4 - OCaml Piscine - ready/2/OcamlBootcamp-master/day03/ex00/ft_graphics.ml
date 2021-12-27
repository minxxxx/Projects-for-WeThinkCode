type 'a tree = Nil | Node of 'a * 'a tree * 'a tree
type 'a point = {
  xx : 'a;
  yy : 'a
}
type position = Center | Up | Down

let draw_square x y size =
  let halfSize = size / 2 in
  let p1 = {xx = x - halfSize; yy = y - halfSize} in
  let p2 = {xx = x + halfSize; yy = y - halfSize} in
  let p3 = {xx = x + halfSize; yy = y + halfSize} in
  let p4 = {xx = x - halfSize; yy = y + halfSize} in
  Graphics.moveto p1.xx p1.yy;
  Graphics.lineto p2.xx p2.yy;
  Graphics.lineto p3.xx p3.yy;
  Graphics.lineto p4.xx p4.yy;
  Graphics.lineto p1.xx p1.yy

let draw_tree_node elem =
  let rec loop x y btree pos = match btree with
    | Nil -> draw_square x y 30; Graphics.moveto (x - 10) y; Graphics.draw_string "Nil"
    | Node (root, left, right) -> 
            draw_square x y 30;  Graphics.moveto (x - 10) y; Graphics.draw_string root;
            match pos with
            | Center -> loop (x + 70) (y - 40) left Down; loop (x + 70) (y + 40) right Up;
                Graphics.moveto (x + 55) (y + 40);
                Graphics.lineto (x + 15) y;
                Graphics.lineto (x + 55) (y - 40)
            | Up -> loop (x + 70) (y + 10) left Up; loop (x + 70) (y + 60) right Up;
                Graphics.moveto (x + 55) (y + 60);
                Graphics.lineto (x + 15) y;
                Graphics.lineto (x + 55) (y + 10)
            | Down -> loop (x + 70) (y - 10) left Down; loop (x + 70) (y - 60) right Down;
                Graphics.moveto (x + 55) (y - 60);
                Graphics.lineto (x + 15) y;
                Graphics.lineto (x + 55) (y - 10)
  in loop 60 300 elem Center

let test_draw_squares () =
  Graphics.open_graph " 800x600";
  draw_square 100 100 20;
  draw_square 400 400 200;
  draw_square 200 500 100;
  draw_square 600 200 90;
  ignore(Graphics.read_key ())

let test_draw_nodes () =
  let node1 = Nil in
  let node2 = Node ("42", Nil, Nil) in
  let node3 = Node ("21", 
                    Node ("42", 
                          Nil, 
                          Node ("64", Nil, Nil)), 
                    Node ("32", 
                          Node("101", Nil, Nil), 
                          Node ("72", Nil, Nil))) in
  Graphics.open_graph " 800x600";
  draw_tree_node node1;
  ignore(Graphics.read_key ());
  Graphics.open_graph " 800x600";
  draw_tree_node node2;
  ignore(Graphics.read_key ());
  Graphics.open_graph " 800x600";
  draw_tree_node node3;
  ignore(Graphics.read_key ())

let main () = 
  test_draw_squares ();
  test_draw_nodes ()

let _ = main ()
