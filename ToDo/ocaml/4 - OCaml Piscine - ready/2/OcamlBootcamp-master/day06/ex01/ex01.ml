(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex01.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/11 11:07:01 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/11 14:49:22 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type HASHEDTYPE =
sig
    type t = String.t
    val equal : t -> t -> bool
    val hash : t -> int
end

module HashedType : HASHEDTYPE =
struct
    type t = String.t
    
    let equal = fun x y -> x = y
    
    let rec power_of_two exp res = match exp with
        | y when y < 1 -> res
        | _ -> power_of_two (exp - 1) (res * 2)
    
    let hash str =
        let rec str_loop index len res = match index with
            | y when y >= len -> res
            | _ -> str_loop (index + 1) len (((res * (power_of_two 5 1)) + res) +
                    (int_of_char (String.get str index))) in
        str_loop 0 (String.length str) 5381
end

module StringHashtbl = Hashtbl.Make (HashedType)

let () =
    let ht = StringHashtbl.create 5 in
    let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
    let pairs = List.map (fun s -> (s, String.length s)) values in
    List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
    StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
