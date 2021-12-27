type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let is_bst bTree =
    let rec bst_check btree min max =
        match btree with
        | Nil -> true
        | Node (root, left, right) ->
                if (root < min) || (root > max) then
                    false
                else
                    (bst_check left min (root - 1)) && 
                    (bst_check right (root + 1) max)
    in bst_check bTree (-2147483648) 2147483647

let is_last bTree =
    match bTree with
    | Nil -> true
    | _ -> false

let height elem =
    let rec loop btree count h = match btree with
    | Nil -> if count > h then count else h
    | Node (root, left, right) -> loop right (count + 1) (loop left (count + 1) h)
    in loop elem 0 0

let is_perfect bTree = 
    if (is_bst bTree) == true then
        begin
            let rec is_perfect_check btree =
                match btree with
                | Nil -> true
                | Node (root, left, right) ->
                        if (is_last left) && (is_last right) then
                            true
                        else if (is_last left) || (is_last right) then
                            false
                        else
                            (is_perfect_check left) && (is_perfect_check right)
            in is_perfect_check bTree
        end
    else
        false

let is_balanced bTree =
    if (is_bst bTree) == true then
        begin
            let rec is_balanced_check btree h =
                match btree with
                | Nil -> if h = 0 then true else false
                | Node (root, left, right) ->
                        (is_balanced_check left (h - 1)) && (is_balanced_check right (h - 1))
            in is_balanced_check bTree (height bTree)
        end
    else
        false

let rec search_bst bTree find =
    match bTree with
    | Nil -> false
    | Node (root, left, right) -> if root = find then true
                else
                    (search_bst left find) || (search_bst right find)

let rec add_bst bTree add =
    match bTree with
    | Nil -> Node (add, Nil, Nil)
    | Node (root, left, right) ->
            if add < root then
                Node (root, (add_bst left add), right)
            else
                Node (root, left, (add_bst right add))
 
let rec add_from_bst oldTree newTree =
    match oldTree with
    | Nil -> Nil
    | Node (root, left, right) ->
            add_from_bst left (add_from_bst right (add_bst newTree root))

let rec delete_bst bTree remove =
    match bTree with
    | Nil -> failwith "value to remove not found"
    | Node (root, left, right) ->
            if remove < root then
                delete_bst left remove
            else if remove > root then
                delete_bst right remove
            else
                begin
                    add_from_bst left (add_from_bst right Nil)
                end

let test_is_bst btree =
    print_endline ("Is Bst -> " ^ (string_of_bool (is_bst btree)));
    print_endline ("Is Perfect -> " ^ (string_of_bool (is_perfect btree)));
    print_endline ("Is Balanced -> " ^ (string_of_bool (is_balanced btree)))

let main () =
    let btree1 = Nil in
    let btree2 = Node (42, Nil, Nil) in
    let btree3 = 
        Node (70, 
            Node (60, Node (40, Nil, Nil), Nil),
            Node (80, Nil, Nil)) in
    let btree3Del = delete_bst btree3 40 in
    let btree4 =
        Node (100, 
            Node (70, Node (60, Nil, Nil), Node (23, Nil, Nil)),
            Node (130, Node (120, Nil, Nil), Node (87, Nil, Nil))) in
    let btree5 =
        Node (100, 
            Node (70, Node (60, Nil, Nil), Node (90, Nil, Nil)),
            Node (130, Node (120, Nil, Nil), Node (140, Nil, Nil))) in
    let btree5Del = delete_bst btree5 120 in
    let btree6 =
        Node (100, 
            Node (70, Nil, Node (80, Nil, Nil)),
            Node (130, Node (120, Nil, Nil), Node (140, Nil, Nil))) in
    test_is_bst btree1;
    print_endline ("Search : 42 -> " ^ (string_of_bool (search_bst btree1 42)));
    print_endline "---------------";
    test_is_bst btree2;
    print_endline ("Search : 42 -> " ^ (string_of_bool (search_bst btree2 42)));
    print_endline "---------------";
    test_is_bst btree3;
    print_endline ("Search : 40 -> " ^ (string_of_bool (search_bst btree3 40)));
    print_endline ("Delete : 40\nSearch : 40 -> " ^ (string_of_bool (search_bst btree3Del 40)));
    print_endline ("Is Bst -> " ^ (string_of_bool (is_bst btree3Del)));
    print_endline "---------------";
    test_is_bst btree4;
    print_endline "---------------";
    test_is_bst btree5;
    print_endline ("Search : 90 -> " ^ (string_of_bool (search_bst btree5 90)));
    print_endline ("Search : 120 -> " ^ (string_of_bool (search_bst btree5 120)));
    print_endline ("Delete : 120\nSearch : 120 -> " ^ (string_of_bool (search_bst btree5Del 120)));
    print_endline ("Is Bst -> " ^ (string_of_bool (is_bst btree5Del)));
    print_endline "---------------";
    test_is_bst btree6;
    print_endline ("Search : 90 -> " ^ (string_of_bool (search_bst btree6 90)));
    print_endline "---------------";
    print_endline ("Add : 42\nSearch : 42 -> " ^ (string_of_bool (search_bst 
        (add_bst btree1 42) 42)));
        print_endline "---------------";
    print_endline ("Add : 180\nSearch : 180 -> " ^ (string_of_bool (search_bst 
        (add_bst btree5 180) 180)));
    print_endline "---------------";
    print_endline "Delete 50 from (42, Nil, Nil)";
    delete_bst btree2 50

let _ = main()
