class alkane n =
object
	inherit Molecule.molecule
		(
			(
				match n with
				| 1 -> "Meth"
				| 2 -> "Eth"
				| 3 -> "Prop"
				| 4 -> "But"
				| 5 -> "Pent"
				| 6 -> "Hex"
				| 7 -> "Hept"
				| 8 -> "Oct"
				| 9 -> "Non"
				| 10 -> "Dec"
				| 11 -> "Undec"
				| 12 -> "Dodec"
				| _ -> "Meth"
			) ^ "ane"
		)
		(
			let rec loop elem n =
				if n > 0 then
					elem::(loop elem (n - 1))
				else
					[]
			in
			(loop (new Carbon.carbon) n) @ (loop (new Hydrogen.hydrogen) (2 * n + 2))
		)
end
