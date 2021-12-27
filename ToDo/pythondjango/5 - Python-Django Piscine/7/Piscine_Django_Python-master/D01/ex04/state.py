""" mon programme trop balese """
import sys

def capital(cap):
	""" cette fonction parcours des dictionnaires """
	states = {
	"Oregon" : "OR",
	"Alabama" : "AL",
	"New Jersey": "NJ",
	"Colorado" : "CO"
	}
	capital_cities = {
	"OR": "Salem",
	"AL": "Montgomery",
	"NJ": "Trenton",
	"CO": "Denver"
	}
	for abbrev, capital in capital_cities.items():
		if cap == capital:
			for state, abbreviation in states.items():
				if abbreviation == abbrev:
					print(state)
					return
	print("Unknown capital city")
if __name__ == '__main__' :
	if len(sys.argv) == 2:
	    capital(sys.argv[1])
