type state
type board

module Tic_tac : (* pas dans l'interface *)
sig
	type tic_tac
	val createTicTac : unit -> tic_tac
	val stringState : state -> string
	val stringTicTac : tic_tac -> string

	val getLineAsString : tic_tac -> int -> string (* Si le tic tac est resolu on envoie labonne truc *)

	val placePoint : tic_tac -> int * int -> state -> bool * tic_tac

	val isJustSolved : tic_tac -> state -> bool * tic_tac (* match tic with |
		 								Solved_x || Solved_o -> faux
										Fight b -> si c'est resolu par un joueur on renvoie (true, Solved_x) ou (true, Solved_o), sinon on renvoie faux *)

	val ticTacFull : tic_tac -> bool
end

val newBoard : unit -> board
val printBoard : board -> unit

val tryToPlacePoint : board -> int * int -> state -> bool * board (* Place un point

*)

val  getOwned_x : unit -> state
val  getOwned_o : unit -> state

val changePlayer : state -> state

val getPlayer : state -> string

val ticTacEnded : board -> int * int -> state -> bool * string * board

val isFull : board -> bool

	(* Appelle le isJustSolved du tic tac modifiee
		Si il est true, renvoie le board avec le tic_tac modifie a la valeur Solved_x ou Solved_o
	*)
val gameEnded : board -> bool * string

(*


	loop board player_a_qui_de_jouer :
		Recuperer input
		Valider l'input (Si c'est faux on reloop)
		Appeler board2 = tryToPlacePoint
			-> si c'est faux : erreur et loop board player_a_qui_de_jouer
		-> sinon :
		board3 = ticTacEnded
			-> Si c'est faux :
				On affiche le board2
				loop board2 tic_tac_toe other_player
			-> Si c'est bon
				On affiche le board3
				gameEnded board3
					-> Si c'est bon : fin du jeu
				sinon
					loop board3 other_player

	loop newBoard Player_O
	3 etats: Pas resolu -> placePoint -> Resolu mais encore etat fight -> isJustSolved -> Solved_x ou Solved_o

*)
