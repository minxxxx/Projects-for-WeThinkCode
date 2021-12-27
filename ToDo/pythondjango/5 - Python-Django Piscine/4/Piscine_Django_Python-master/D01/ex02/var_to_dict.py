""" mon programme trop balese """


def var_to_dict():
	""" cette fonction convertit une liste de set en dict """
	d = [
	('Hendrix' , '1942'),
	('Allman' , '1946'),
	('King' , '1925'),
	('Clapton' , '1945'),
	('Johnson' , '1911'),
	('Berry' , '1926'),
	('Vaughan' , '1954'),
	('Cooder' , '1947'),
	('Page' , '1944'),
	('Richards' , '1943'),
	('Hammett' , '1962'),
	('Cobain' , '1967'),
	('Garcia' , '1942'),
	('Beck' , '1944'),
	('Santana' , '1947'),
	('Ramone' , '1948'),
	('White' , '1975'),
	('Frusciante', '1970'),
	('Thompson' , '1949'),
	('Burton' , '1939')
	]
	mon_dict = dict() # je cree un dict vide
	for couple in d: # je parcours la liste d
		if mon_dict.get(couple[1]): # s'il y a deja une valeur pour cette cle, j'ajoute a la liste de valeurs
			mon_dict[couple[1]].append(couple[0])
		else: # s'il n'y a pas de valeur pour cette cle, j'insere une liste
			mon_dict[couple[1]] = [couple[0]]

	for cle in mon_dict: # je parcours le dictionnire
		val = ""
		for v in mon_dict[cle]: # je transforme la liste en string
			val += v + " "
		print("%s : %s" % (cle, val)) # eh voila

if __name__ == '__main__' :
    var_to_dict()
