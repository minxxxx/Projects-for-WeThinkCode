type 'a tree = Nil | Node of 'a * 'a tree * 'a tree
type 'a point = {
    xx : 'a;
    yy : 'a
}

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

let size elem =
    let rec loop btree count = match btree with
    | Nil -> count
    | Node (root, left, right) -> loop right (loop left (count + 1))
    in loop elem 0

let height elem =
    let rec loop btree count h = match btree with
    | Nil -> if count > h then count else h
    | Node (root, left, right) -> loop right (count + 1) (loop left (count + 1) h)
    in loop elem 0 0

let draw_tree elem =
    let rec loop btree x y h = match btree with
    | Nil -> draw_square x y 30; Graphics.moveto (x - 6) y; Graphics.draw_string "Nil"
    | Node (root, left, right) -> 
            draw_square x y 30; Graphics.moveto (x - 6) y; Graphics.draw_string root;
            let half = 30 * h in
            loop left (x + 90) (y - half) (h - 1);
            loop right (x + 90) (y + half) (h - 1);
            Graphics.moveto (x + 75) (y + half);
            Graphics.lineto (x + 15) y;
            Graphics.lineto (x + 75) (y - half)
    in loop elem 30 300 ((height elem) + 1)

let test btree =
    print_endline ("Size : " ^ (string_of_int (size btree)));
    print_endline ("Height : " ^ (string_of_int (height btree)));
    draw_tree btree;
    ignore(Graphics.read_key ());
    Graphics.clear_graph ()

let main () =
    let btree1 = Nil in
    let btree2 = Node ("42", Nil, Nil) in
    let btree3 = Node ("21",
                  Node ("42",
                        Nil,
                        Node ("64", Nil, Nil)), 
                  Node ("32",
                         Node("101", Nil, Nil),
                         Node("72", Nil, Nil))) in
    let btree4 = Node ("21",
                  Node ("42",
                        Nil,
                        Node ("62", Nil, Nil)),
                  Nil) in
    Graphics.open_graph " 800x600";
    test btree1;
    test btree2;
    test btree3;
    test btree4

 let _ = main ()
