let ft_sum f i n =
    let rec loop func lower upper  ?(acc=0.0) () =
        if lower == upper then
            (func lower) +. acc
         else if lower > upper then
             nan
          else
              loop func (lower + 1) upper ~acc:((func lower) +. acc) ()
     in loop f i n ()

let () =
    print_endline (string_of_float (ft_sum (fun i -> float_of_int (i * i)) 1 10));
    print_endline (string_of_float (ft_sum (fun i -> float_of_int (i * i)) 5 3));
    print_endline (string_of_float (ft_sum (fun i -> float_of_int (i * i)) 5 10));
    print_endline (string_of_float (ft_sum (fun i -> float_of_int (i * i)) (-1) 6))

