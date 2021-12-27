(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Game.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/07 18:38:46 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/07 19:43:40 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let get_interface_option () =
  let rec loop () = match (read_int_opt ()) with
        | Some a -> 
                if (a < 1) || (a > 3) then
                    begin print_endline "Choose from 1 - 3"; loop () end
                else
                    a
        | None -> print_endline "Choose from 1 - 3"; loop () in
  print_endline "TIC TAC TOE\nChoose :\n  1. COMMAND LINE.\n  2. GUI.\n  3. NCURSES.";
  loop ()

let game_entry () =
    let interface_option = get_interface_option () in
    if interface_option = 1 then
        Cmd.command_line_entry ()
    else if interface_option = 2 then
        Gui.gui_entry ()

let _ = game_entry ()

