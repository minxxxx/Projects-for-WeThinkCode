let leibniz_pi minimal_delta =
    let is_even num = if (num mod 2) == 0 then true else false
    in let formula_1 i =
        let float_of_i = float_of_int i
        in if (is_even i) == true then
            (1.0 /. ((2.0 *. float_of_i) +. 1.0))
        else
            (-1.0) *. (1.0 /. ((2.0 *. float_of_i) +. 1.0))
    in let pi = ((atan 1.0) *. 4.0)
    in let abs = (fun i -> if i < 0.0 then i *. (-1.0) else i)
    in let rec pi_loop delta lower acc count =
        if (abs (pi -. (4.0 *. acc))) <= delta then
            count
        else
            pi_loop delta (lower + 1) (acc +. (formula_1 lower)) (count + 1)
    in pi_loop minimal_delta 1 (formula_1 0) 0

let () =
    print_endline ("delta 0.01 -> " ^ string_of_int (leibniz_pi 0.01));
    print_endline ("delta 0.001 -> " ^ string_of_int (leibniz_pi 0.001));
    print_endline ("delta 0.0001 -> " ^ string_of_int (leibniz_pi 0.0001));
    print_endline ("delta 0.00001 -> " ^ string_of_int (leibniz_pi 0.00001));
    print_endline ("delta 0.000001 -> " ^ string_of_int (leibniz_pi 0.000001));
    print_endline ("delta 0.0000001 -> " ^ string_of_int (leibniz_pi 0.0000001))

