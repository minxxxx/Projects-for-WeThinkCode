module StringHash : (Hashtbl.HashedType with type t = string) =
struct
	type t = string
	let equal i j = i = j
	let hash str = (
		fun str ->
			let rec loop hash i =
				if (i = String.length str) then
					hash
				else
					loop ((hash lsl 5) + hash + int_of_char (String.get str i)) (i + 1);
			in
			loop 5381 0
		) str
end

module StringHashtbl = Hashtbl.Make (StringHash)

let () =
	let ht = StringHashtbl.create 5 in
	let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
	let pairs = List.map (fun s -> (s, String.length s)) values in
	List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
	StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
