type res = None | Mark of Player.m
type s = INPROGRESS | FINISH
type t = {
  p : Player.m list ; 
  n : int ;
  s : s ;
  res : res
}
let make n : t =
  let rec loop = function
  | 0 -> []
  | i -> Player.N::(loop (i - 1))
  in 
  let list_player = loop (n * n) in
  { p = list_player; n = n; s=INPROGRESS; res=None}

let mark_of (r, c) b =
  let i = c + (r * b.n) in
  let f = function 
    | (Player.X : Player.m) -> Player.X
    | Player.O -> Player.O
    | _ -> Player.N
  in
  let rec loop l acc = match l with
    | [] -> Player.N (* no possible because r c must be valid *)
    | hd :: tl ->
      if acc = i then f hd
      else loop tl (acc + 1)
  in
  loop b.p 0

let winner_of b =
  let same value value1 = value in
  let win p i =
    let rec check (y, x) opey opex =
      if ((y < 0) || (y >= b.n)) || ((x < 0) || (x >= b.n)) then true
      else
        let newi = x + (y * b.n) in 
        if ((newi < 0) || (newi >= (List.length b.p))) then false else
          let newp = List.nth b.p newi in
          if p <> newp then false
          else check ((opey y 1), (opex x 1)) opey opex
    in
    let y = i / b.n in let x = i mod b.n in
    let top = check ((y - 1), x) (-) same in let bottom = check ((y + 1), x) (+) same in
    let left = check (y, (x - 1)) same (-) in let rigth = check (y, (x + 1)) same (+) in
    let bottomRigth = check ((y + 1), (x + 1)) (+) (+) in let topLeft = check ((y - 1), (x - 1)) (-) (-) in
    let bottomLeft = check ((y + 1), (x - 1)) (+) (-) in let topRigth = check ((y - 1), (x + 1)) (-) (+) in
    ((top && (y > 0)) && (bottom && (y < (b.n - 1)))) ||
    ((left && (x > 0)) && (rigth && (x < (b.n - 1)))) ||
    ((bottomRigth && (y > 0) && (x < (b.n - 1))) && (topLeft && (y < (b.n - 1)) && (x > 0))) ||
    ((bottomLeft && (y > 0) && (x > 0)) && (topRigth && (y < (b.n - 1)) && (x < (b.n -1))))
  in
  let rec loop l i =
    match l with
    | [] -> 
      if (List.for_all (fun p -> p <> Player.N) b.p) then Mark(Player.N) else None
    | hd :: tl when hd = Player.N -> loop tl (i + 1)
    | hd :: tl -> if win hd i then Mark(hd) else loop tl (i + 1)
  in loop b.p 0

let rec find_mv b =
  let rec ver = function
    | r when r = b.n -> Player.NoMove
    | r -> begin
      let rec line = function
      | c when c = b.n -> []
      | c ->
        let idx = ((r * b.n) + c)
        in ((r, c), (List.nth b.p idx)) :: line (c + 1)
      in let rec find = function
      | [] -> ver (r + 1)
      | ((r, c), m)::t when m = Player.N -> Player.Move(r, c)
      | h::t -> find t
      in find (line 0)
    end
  in let rec hor = function
    | c when c = b.n -> Player.NoMove
    | c -> begin
      let rec line = function
      | r when r = b.n -> []
      | r ->
        let idx = ((r * b.n) + c)
        in ((r, c), (List.nth b.p idx)) :: line (r + 1)
      in let rec find = function
      | [] -> hor (c + 1)
      | ((r, c), m)::t when m = Player.N -> Player.Move(r, c)
      | h::t -> find t
      in find (line 0)
    end
  in match ver 0 with
  | Player.NoMove -> hor 0
  | m -> m

let is_not_legal (r, c) b =
  if (winner_of b) != None then true else
    let i = c + (r * b.n) in
    let f = function 
      | (Player.X : Player.m) | Player.O -> true
      | _ -> false
    in
    let rec loop l acc = match l with
      | [] -> false
      | hd :: tl -> if acc = i then f hd else loop tl (acc + 1)
    in
    loop b.p 0

let toggle (r, c) m b =
  let i = c + (r * b.n) in
  let f index e = if index <> i then e else m in
  let newp = List.mapi f b.p in
  let win = winner_of ({p=newp;n=b.n;s=b.s;res=b.res}) in
  let news = if win != None then FINISH else b.s in
  {p = newp; n = b.n; s=news;res=win}

let rec dump b =
  let f i a =
    print_string (Player.string_of_mark a) ;
    print_char (if (((i + 1) mod b.n) = 0) && i <> 0 then '\n' else ' ')
  in List.iteri f b.p

let draw dx dy b =
  let f i m =
    let x = (i mod b.n) in let y = (i / b.n) in
    Graphics.moveto (dx + (x * 20)) (dy - (y * 20));
    Graphics.draw_string (Player.string_of_mark m)
  in List.iteri f b.p

let string_of b : string list = 
  let rec loop l acc line = match l with
    | [] -> []
    | hd :: tl when (((acc + 1) mod b.n) = 0 && acc <> 0) ->
      (line ^ " " ^ Player.string_of_mark hd) :: (loop tl (acc + 1) "")
    | hd :: tl -> let sepa = if ((acc mod b.n) = 0) then "" else " "  in
      loop tl (acc + 1) (line ^ sepa ^ (Player.string_of_mark hd))
  in 
  let rec loop2 l acc line v = match l with
    | [] -> []
    | hd :: tl when (((acc + 1) mod b.n) = 0 && acc <> 0) ->
      (line ^ " " ^ v) :: (loop2 tl (acc + 1) "" v)
    | hd :: tl -> let sepa = if ((acc mod b.n) = 0) then "" else " "  in
      loop2 tl (acc + 1) (line ^ sepa ^ v) v
  in
  if b.res != None then
    let value = match b.res with
      | Mark(Player.O) -> "O"
      | Mark(Player.N) -> "N"
      | Mark(Player.X) -> "X"
      | _ -> ""
    in loop2 b.p 0 "" value
  else loop b.p 0 ""
