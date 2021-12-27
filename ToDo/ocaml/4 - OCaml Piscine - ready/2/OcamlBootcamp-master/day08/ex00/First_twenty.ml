(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   First_twenty.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2017/10/12 21:19:25 by sasiedu           #+#    #+#             *)
(*   Updated: 2017/10/12 21:39:50 by sasiedu          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class hydrogen =
object (self)
    inherit Atom.atom
    method name = "Hydrogen"
    method symbol = "H"
    method atomic_number = 1
end

class helium =
object (self)
    inherit Atom.atom
    method name = "Helium"
    method symbol = "He"
    method atomic_number = 2
end

class lithium =
object (self)
    inherit Atom.atom
    method name = "Lithium"
    method symbol = "Li"
    method atomic_number = 3
end

class beryllium =
object (self)
    inherit Atom.atom
    method name = "Beryllium"
    method symbol = "Be"
    method atomic_number = 4
end

class boron =
object (self)
    inherit Atom.atom
    method name = "Boron"
    method symbol = "B"
    method atomic_number = 5
end

class carbon =
object (self)
    inherit Atom.atom
    method name = "Carbon"
    method symbol = "C"
    method atomic_number = 6
end

class nitrogen =
object (self)
    inherit Atom.atom
    method name = "Nitrogen"
    method symbol = "N"
    method atomic_number = 7
end

class oxygen =
object (self)
    inherit Atom.atom
    method name = "Oxygen"
    method symbol = "O"
    method atomic_number = 8
end

class fluorine =
object (self)
    inherit Atom.atom
    method name = "Fluorine"
    method symbol = "F"
    method atomic_number = 9
end

class neon =
object (self)
    inherit Atom.atom
    method name = "Neon"
    method symbol = "Ne"
    method atomic_number = 10
end

class sodium =
object (self)
    inherit Atom.atom
    method name = "Sodium"
    method symbol = "Na"
    method atomic_number = 11
end

class magnesium =
object (self)
    inherit Atom.atom
    method name = "Magnesium"
    method symbol = "Mg"
    method atomic_number = 12
end

class aluminum =
object (self)
    inherit Atom.atom
    method name = "Aluminum"
    method symbol = "Al"
    method atomic_number = 13
end

class silicon =
object (self)
    inherit Atom.atom
    method name = "Silicon"
    method symbol = "S"
    method atomic_number = 14
end

class phosphorus =
object (self)
    inherit Atom.atom
    method name = "Phosphorus"
    method symbol = "P"
    method atomic_number = 15
end

class sulfur =
object (self)
    inherit Atom.atom
    method name = "Sulfur"
    method symbol = "S"
    method atomic_number = 16
end

class chlorine =
object (self)
    inherit Atom.atom
    method name = "Chlorine"
    method symbol = "Cl"
    method atomic_number = 17
end

class argon =
object (self)
    inherit Atom.atom
    method name = "Argon"
    method symbol = "Ar"
    method atomic_number = 18
end

class potassium =
object (self)
    inherit Atom.atom
    method name = "Potassium"
    method symbol = "K"
    method atomic_number = 19
end

class calcium =
object (self)
    inherit Atom.atom
    method name = "Calcium"
    method symbol = "Ca"
    method atomic_number = 20
end
