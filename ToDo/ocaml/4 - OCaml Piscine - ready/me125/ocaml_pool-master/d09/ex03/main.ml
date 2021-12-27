(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 17:37:57 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/26 18:06:57 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let string_of_try = function
| Try.Success (a)			-> a
| Try.Failure (e)			-> "FAILURE"

let () =
	Printf.printf "return lol ---> %s\n" (string_of_try (Try.return "lol"));
	Printf.printf "bind lol to mdr ---> %s\n" (string_of_try (Try.bind (Try.return "lol") (fun a -> Try.return "mdr")));
	Printf.printf "bind FAIL to mdr ---> %s\n" (string_of_try (Try.bind (Try.Failure Try.Fail) (fun a -> Try.return "mdr")));
	Printf.printf "bind lol to Fail ---> %s\n" (string_of_try (Try.bind (Try.Failure Try.Fail) (fun a -> Try.Failure Try.Fail)));
	Printf.printf "recover lol to mdr ---> %s\n" (string_of_try (Try.recover (Try.return "lol") (fun a -> Try.return "mdr")));
	Printf.printf "recover FAIL to mdr ---> %s\n" (string_of_try (Try.recover (Try.Failure Try.Fail) (fun a -> Try.return "mdr")));
	Printf.printf "recover lol to FAIL ---> %s\n" (string_of_try (Try.recover (Try.return "lol") (fun a -> Try.Failure Try.Fail)));
	Printf.printf "filter lol of mdr ---> %s\n" (string_of_try (Try.filter (Try.return "mdr") (fun a -> a = "lol")));
	Printf.printf "filter lol of FAIL ---> %s\n" (string_of_try (Try.filter (Try.Failure Try.Fail) (fun a -> a = "lol")));
	Printf.printf "filter lol of lol ---> %s\n" (string_of_try (Try.filter (Try.return "lol") (fun a -> a = "lol")));
	Printf.printf "flatten of Try of lol ---> %s\n" (string_of_try (Try.flatten (Try.return (Try.return "lol"))));
	Printf.printf "flatten of Try of FAIL ---> %s\n" (string_of_try (Try.flatten (Try.return (Try.Failure Try.Fail))));
	Printf.printf "flatten of FAIL ---> %s\n" (string_of_try (Try.flatten (Try.Failure Try.Fail)));
