(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   atom.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 12:17:05 by jaguillo          #+#    #+#             *)
(*   Updated: 2015/06/25 13:27:44 by jaguillo         ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual atom __name __symbol __number = object
	val _name = __name
	val _symbol = __symbol
	val _atomic_number = __number
	method name = _name
	method symbol = _symbol
	method atomic_number = _atomic_number
	method to_string = "atom( name = " ^ _name ^ " ; symbol = " ^ _symbol ^ " ; atomic_number = " ^ (string_of_int _atomic_number) ^" )"
	method equals (a:atom) = a#name = _name && a#symbol = _symbol && a#atomic_number = _atomic_number
end

class hydrogen = object inherit atom "Hydrogen" "H" 1 end
class helium = object inherit atom "Helium" "He" 2 end
class lithium = object inherit atom "Lithium" "Li" 3 end
class beryllium = object inherit atom "Beryllium" "Be" 4 end
class boron = object inherit atom "Boron" "B" 5 end
class carbon = object inherit atom "Carbon" "C" 6 end
class nitrogen = object inherit atom "Nitrogen" "N" 7 end
class oxygen = object inherit atom "Oxygen" "O" 8 end
class fluorine = object inherit atom "Fluorine" "F" 9 end
class neon = object inherit atom "Neon" "Ne" 10 end
class sodium = object inherit atom "Sodium" "Na" 11 end
class magnesium = object inherit atom "Magnesium" "Mg" 12 end
class aluminum = object inherit atom "Aluminum" "Al" 13 end
class silicon = object inherit atom "Silicon" "Si" 14 end
class phosphorus = object inherit atom "Phosphorus" "P" 15 end
class sulfur = object inherit atom "Sulfur" "S" 16 end
class chlorine = object inherit atom "Chlorine" "Cl" 17 end
class argon = object inherit atom "Argon" "Ar" 18 end
class potassium = object inherit atom "Potassium" "K" 19 end
class calcium = object inherit atom "Calcium" "Ca" 20 end
class scandium = object inherit atom "Scandium" "Sc" 21 end
class titanium = object inherit atom "Titanium" "Ti" 22 end
class vanadium = object inherit atom "Vanadium" "V" 23 end
class chromium = object inherit atom "Chromium" "Cr" 24 end
class manganese = object inherit atom "Manganese" "Mn" 25 end
class iron = object inherit atom "Iron" "Fe" 26 end
class cobalt = object inherit atom "Cobalt" "Co" 27 end
class nickel = object inherit atom "Nickel" "Ni" 28 end
class copper = object inherit atom "Copper" "Cu" 29 end
class zinc = object inherit atom "Zinc" "Zn" 30 end
class gallium = object inherit atom "Gallium" "Ga" 31 end
class germanium = object inherit atom "Germanium" "Ge" 32 end
class arsenic = object inherit atom "Arsenic" "As" 33 end
class selenium = object inherit atom "Selenium" "Se" 34 end
class bromine = object inherit atom "Bromine" "Br" 35 end
class krypton = object inherit atom "Krypton" "Kr" 36 end
class rubidium = object inherit atom "Rubidium" "Rb" 37 end
class strontium = object inherit atom "Strontium" "Sr" 38 end
class yttrium = object inherit atom "Yttrium" "Y" 39 end
class zirconium = object inherit atom "Zirconium" "Zr" 40 end
class niobium = object inherit atom "Niobium" "Nb" 41 end
class molybdenum = object inherit atom "Molybdenum" "Mo" 42 end
class technetium = object inherit atom "Technetium" "Tc" 43 end
class ruthenium = object inherit atom "Ruthenium" "Ru" 44 end
class rhodium = object inherit atom "Rhodium" "Rh" 45 end
class palladium = object inherit atom "Palladium" "Pd" 46 end
class silver = object inherit atom "Silver" "Ag" 47 end
class cadmium = object inherit atom "Cadmium" "Cd" 48 end
class indium = object inherit atom "Indium" "In" 49 end
class tin = object inherit atom "Tin" "Sn" 50 end
class antimony = object inherit atom "Antimony" "Sb" 51 end
class tellurium = object inherit atom "Tellurium" "Te" 52 end
class iodine = object inherit atom "Iodine" "I" 53 end
class xenon = object inherit atom "Xenon" "Xe" 54 end
class cesium = object inherit atom "Cesium" "Cs" 55 end
class barium = object inherit atom "Barium" "Ba" 56 end
class lanthanum = object inherit atom "Lanthanum" "La" 57 end
class cerium = object inherit atom "Cerium" "Ce" 58 end
class praseodymium = object inherit atom "Praseodymium" "Pr" 59 end
class neodymium = object inherit atom "Neodymium" "Nd" 60 end
class promethium = object inherit atom "Promethium" "Pm" 61 end
class samarium = object inherit atom "Samarium" "Sm" 62 end
class europium = object inherit atom "Europium" "Eu" 63 end
class gadolinium = object inherit atom "Gadolinium" "Gd" 64 end
class terbium = object inherit atom "Terbium" "Tb" 65 end
class dysprosium = object inherit atom "Dysprosium" "Dy" 66 end
class holmium = object inherit atom "Holmium" "Ho" 67 end
class erbium = object inherit atom "Erbium" "Er" 68 end
class thulium = object inherit atom "Thulium" "Tm" 69 end
class ytterbium = object inherit atom "Ytterbium" "Yb" 70 end
class lutetium = object inherit atom "Lutetium" "Lu" 71 end
class hafnium = object inherit atom "Hafnium" "Hf" 72 end
class tantalum = object inherit atom "Tantalum" "Ta" 73 end
class tungsten = object inherit atom "Tungsten" "W" 74 end
class rhenium = object inherit atom "Rhenium" "Re" 75 end
class osmium = object inherit atom "Osmium" "Os" 76 end
class iridium = object inherit atom "Iridium" "Ir" 77 end
class platinum = object inherit atom "Platinum" "Pt" 78 end
class gold = object inherit atom "Gold" "Au" 79 end
class mercury = object inherit atom "Mercury" "Hg" 80 end
class thallium = object inherit atom "Thallium" "Tl" 81 end
class lead = object inherit atom "Lead" "Pb" 82 end
class bismuth = object inherit atom "Bismuth" "Bi" 83 end
class polonium = object inherit atom "Polonium" "Po" 84 end
class astatine = object inherit atom "Astatine" "At" 85 end
class radon = object inherit atom "Radon" "Rn" 86 end
class francium = object inherit atom "Francium" "Fr" 87 end
class radium = object inherit atom "Radium" "Ra" 88 end
class actinium = object inherit atom "Actinium" "Ac" 89 end
class thorium = object inherit atom "Thorium" "Th" 90 end
class protactinium = object inherit atom "Protactinium" "Pa" 91 end
class uranium = object inherit atom "Uranium" "U" 92 end
class neptunium = object inherit atom "Neptunium" "Np" 93 end
class plutonium = object inherit atom "Plutonium" "Pu" 94 end
class americium = object inherit atom "Americium" "Am" 95 end
class curium = object inherit atom "Curium" "Cm" 96 end
class berkelium = object inherit atom "Berkelium" "Bk" 97 end
class californium = object inherit atom "Californium" "Cf" 98 end
class einsteinium = object inherit atom "Einsteinium" "Es" 99 end
class fermium = object inherit atom "Fermium" "Fm" 100 end
class mendelevium = object inherit atom "Mendelevium" "Md" 101 end
class nobelium = object inherit atom "Nobelium" "No" 102 end
class lawrencium = object inherit atom "Lawrencium" "Lr" 103 end
class rutherfordium = object inherit atom "Rutherfordium" "Rf" 104 end
class dubnium = object inherit atom "Dubnium" "Db" 105 end
class seaborgium = object inherit atom "Seaborgium" "Sg" 106 end
class bohrium = object inherit atom "Bohrium" "Bh" 107 end
class hassium = object inherit atom "Hassium" "Hs" 108 end
class meitnerium = object inherit atom "Meitnerium" "Mt" 109 end
