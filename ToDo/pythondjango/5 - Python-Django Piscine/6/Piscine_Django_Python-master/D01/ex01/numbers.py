""" mon programme trop balese """


def litFichier(file):
	""" cette fonction lit un fichier """
	with open(file) as f:
		for line in f:
			words = line.split(",")
			for w in words:
				print(w.strip('\n'))


if __name__ == '__main__' :
    litFichier("numbers.txt")
