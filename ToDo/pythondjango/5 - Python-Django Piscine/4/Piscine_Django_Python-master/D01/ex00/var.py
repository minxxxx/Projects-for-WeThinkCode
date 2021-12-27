""" mon programme trop balese """

def affiche(val):
	print("{0} est de type {1}".format(val, type(val)))

def my_var():
	""" cette fonction imprime des variables """
	affiche(42)
	affiche("42")
	affiche("quarante-deux")
	affiche(42.0)
	affiche([42])
	affiche({42 :42})
	affiche((42,))
	affiche(set())
	
if __name__ == '__main__' :
    my_var()
