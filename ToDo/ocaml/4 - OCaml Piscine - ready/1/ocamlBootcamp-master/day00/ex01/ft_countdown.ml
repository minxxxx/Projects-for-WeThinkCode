(*
 * function that does the count down
 *)
let rec ft_countdown x =
    if (x <= 0) then 
        begin
            print_int 0 ;
            print_char '\n'
        end
    else
        begin
            print_int x;
            print_char '\n';
            ft_countdown(x -1) (*recursion*)
        end

(*
 * main fuction is calling ft_countdown
 *)
let main() = ft_countdown 11
let () = main()
