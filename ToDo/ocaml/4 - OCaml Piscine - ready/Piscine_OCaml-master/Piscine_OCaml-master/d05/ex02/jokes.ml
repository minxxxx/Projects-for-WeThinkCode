let main () =
	Random.self_init ();
	let jokes = [|"Qu'est qui court et qui se jette ?\nUne courgette." ;
				"Une carotte veut se suicider. Helas, elle echoue et puis se dit :\n- Zut, c'est rape !";
				"Mefiez vous de l’oiseau sur le lac :\nC’est peut-être un mauvais cygne !" ;
				"Les girafes, ça n'existe pas...\nNormal, c'est un cou monte !";
				"Deux bonbons qui marchent sur la route. Un flic les arrête et dit : \n- Vos papiers s'il vous plait !!"|] in
	print_endline jokes.(Random.int (Array.length jokes))

let () = main ()
