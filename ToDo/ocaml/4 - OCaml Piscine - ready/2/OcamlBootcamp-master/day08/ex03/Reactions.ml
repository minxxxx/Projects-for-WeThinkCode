(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Reactions.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/13 12:36:01 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/13 17:02:10 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class photosynthesis =
object (self : 'a)
    inherit Reaction.reaction
    val _start = [new Molecules.carbon_dioxide;new Molecules.carbon_dioxide;
                 new Molecules.carbon_dioxide;new Molecules.carbon_dioxide;
                 new Molecules.carbon_dioxide;new Molecules.carbon_dioxide;
                 new Molecules.water;new Molecules.water;
                 new Molecules.water;new Molecules.water;
                 new Molecules.water;new Molecules.water]
    val _end = [new Molecules.glucose;new Molecules.oxygen;
                new Molecules.oxygen;new Molecules.oxygen;
                new Molecules.oxygen;new Molecules.oxygen;
                new Molecules.oxygen;]

    method balance = {<>}
end

class aerobic_respiration =
object (self : 'a)
    inherit Reaction.reaction
    val _start = [new Molecules.glucose;new Molecules.oxygen]
    val _end = [new Molecules.carbon_dioxide;new Molecules.water]
    method balance = {<>}
end
