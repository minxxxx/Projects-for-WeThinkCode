let gray count =
    if count > 0 then
        begin
    let rec decrease str index length =
       print_string (str ^ " ");
        if index < length then
            begin
                (*String.set str index '0';*)
                (*str = String.mapi (fun i c -> if i == index then '0' else c)
                 * str;*)
                decrease (String.mapi (fun i c -> if i == index then '0' else c) str) 
                    (index + 1) length
            end
    in let rec increase str index =
        print_string (str ^ " ");
        if index = 0 then
            decrease (String.mapi (fun i c -> if i == index then '1' else c) str) 
                1 (String.length str)
        else
            increase (String.mapi (fun i c -> if i == index then '1' else c) str) 
                 (index - 1)
    in increase (String.init count (fun x -> '0')) (count - 1);
    print_char '\n'
        end    

let () =
    gray 1;
    gray 2;
    gray 0;
    gray 3;
    gray (-1);
    gray 6
