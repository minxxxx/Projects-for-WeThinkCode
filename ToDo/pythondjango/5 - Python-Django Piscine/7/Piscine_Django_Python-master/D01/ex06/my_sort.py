
def invert_dict(d):
	""" cette fonction convertit un dict en un dict ou les valeurs remplacent les cles """

	mon_dict = dict() # je cree un dict vide
	for name in d: # je parcours la liste d
		if mon_dict.get(d[name]): # s'il y a deja une valeur pour cette cle, j'ajoute a la liste de valeurs
			mon_dict[d[name]].append(name)
		else: # s'il n'y a pas de valeur pour cette cle, j'insere une liste
			mon_dict[d[name]] = [name]
	return mon_dict

def sort_list():
	d = {
	'Hendrix' : '1942',
	'Allman' : '1946',
	'King' : '1925',
	'Clapton' : '1945',
	'Johnson' : '1911',
	'Berry' : '1926',
	'Vaughan' : '1954',
	'Cooder' : '1947',
	'Page' : '1944',
	'Richards' : '1943',
	'Hammett' : '1962',
	'Cobain' : '1967',
	'Garcia' : '1942',
	'Beck' : '1944',
	'Santana' : '1947',
	'Ramone' : '1948',
	'White' : '1975',
	'Frusciante': '1970',
	'Thompson' : '1949',
	'Burton' : '1939',
	}

	# je transforme le dict en liste de tuples ordonnes de type [(annee, [nom1, nom2...])]
	my_list = sorted(invert_dict(d).items()) 

	#for tup in my_list:
	#	names = sorted(tup[1])
	#	print("{0} - {1}".format(tup[0], names))

	# je parcours la liste de tuple et pour chaque valeur de la liste, je l'affiche
	for tup in my_list:
		names = sorted(tup[1])
		for n in names:
			print(n)

if __name__ == '__main__' :
	sort_list()