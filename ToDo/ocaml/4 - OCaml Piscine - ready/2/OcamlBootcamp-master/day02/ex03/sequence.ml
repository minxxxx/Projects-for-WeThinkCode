let countAndPrint elem count isLast =
    if count > 0 then
        begin
            [count;elem]
        end
    else
        []

let rec printListInt nList =
    match nList with
    | [] -> print_char '\n'
    | elem::next -> print_int elem; printListInt next

let rec loopList mList element count =
    (*if count == 0 then begin printListInt mList end;*)
    match mList with
    | [] -> countAndPrint element count true
    | elem::next -> 
            if elem == element then
                loopList next element (count + 1)
            else if count > 0 then
                count::element::(loopList next elem 1)
            else
                loopList next elem 1

let rec listToString mList =
    match mList with
    | [] -> ""
    | elem::next -> (string_of_int elem) ^ (listToString next)

let sequence n = 
    if n < 1 then
        ""
    else
        begin
           let rec seqLoop count mList =
               if count > 0 then
                   seqLoop (count - 1) (loopList mList 1 0)
               else
                   listToString mList
           in seqLoop n [1]
        end

let () =
    print_endline (sequence 1);
    print_endline (sequence 0);
    print_endline (sequence 4);
    print_endline (sequence 7);
    print_endline (sequence (-1));
    print_endline (sequence 15);
