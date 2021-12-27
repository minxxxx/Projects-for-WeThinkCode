(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   micronap.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/10 09:26:36 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/10 17:00:36 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let my_sleep () = Unix.sleep 1

let () =
    let argv = Sys.argv in
    match (Array.length argv) with
    | 2 ->
       begin
           try
               let t = int_of_string argv.(1) in
               for i = 1 to t do
                   my_sleep ()
               done;
           with
           | _ -> ()
       end
    | _ -> ()
