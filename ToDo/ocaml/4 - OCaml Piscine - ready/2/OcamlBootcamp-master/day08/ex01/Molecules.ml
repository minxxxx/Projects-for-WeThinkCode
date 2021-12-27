(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Molecules.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 22:14:58 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 23:22:04 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class trinitrotoluene =
object (self)
    inherit Molecule.molecule
    method private _atoms = 
        [new First_twenty.nitrogen;new First_twenty.nitrogen;
         new First_twenty.nitrogen;new First_twenty.hydrogen;
         new First_twenty.hydrogen;new First_twenty.hydrogen;
         new First_twenty.hydrogen;new First_twenty.hydrogen;
         new First_twenty.oxygen;new First_twenty.oxygen;
         new First_twenty.oxygen;new First_twenty.oxygen;
         new First_twenty.oxygen;new First_twenty.oxygen;
         new First_twenty.carbon;new First_twenty.carbon;
         new First_twenty.carbon;new First_twenty.carbon;
         new First_twenty.carbon;new First_twenty.carbon;
         new First_twenty.carbon]
    
    method name = "Trinitrotoluene"
end

class water =
object (self)
    inherit Molecule.molecule
    method private _atoms =
      [new First_twenty.hydrogen; new First_twenty.hydrogen;
       new First_twenty.oxygen]

    method name = "Water"
end

class carbon_dioxide =
object (self)
    inherit Molecule.molecule
    method private _atoms =
      [new First_twenty.carbon; new First_twenty.oxygen;
       new First_twenty.oxygen]

    method name = "Carbon Dioxide"
end

class sulfuric_acid =
object (self)
    inherit Molecule.molecule
    method private _atoms =
      [new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.sulfur; new First_twenty.oxygen;
       new First_twenty.oxygen; new First_twenty.oxygen;
       new First_twenty.oxygen]

    method name = "Sulfuric Acid"
end

class ammonium_nitrate =
object (self)
    inherit Molecule.molecule
    method private _atoms =
      [new First_twenty.nitrogen;new First_twenty.nitrogen;
       new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.oxygen;new First_twenty.oxygen;
       new First_twenty.oxygen]

    method name = "Ammonium Nitrate"
end

class soduim_chloride =
object (self)
    inherit Molecule.molecule
    method private _atoms =
      [new First_twenty.sodium;new First_twenty.chlorine]

    method name = "Soduim Chloride"
end

class tartrazine_dye =
object (self)
    inherit Molecule.molecule
    method private _atoms =
      [new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.carbon;new First_twenty.carbon;
       new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.hydrogen;new First_twenty.hydrogen;
       new First_twenty.hydrogen;new First_twenty.nitrogen;
       new First_twenty.nitrogen;new First_twenty.nitrogen;
       new First_twenty.nitrogen;new First_twenty.sodium;
       new First_twenty.sodium;new First_twenty.sodium;
       new First_twenty.oxygen;new First_twenty.oxygen;
       new First_twenty.oxygen;new First_twenty.oxygen;
       new First_twenty.oxygen;new First_twenty.oxygen;
       new First_twenty.oxygen;new First_twenty.oxygen;
       new First_twenty.oxygen;new First_twenty.sulfur;
       new First_twenty.sulfur]

    method name = "Tartrazine Dye"
end
