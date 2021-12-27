""" mon programme trop balese """
import sys

def capital_city(state):
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
	if not states.get(state):
		print("Unknown state")
		return
	if capital_cities.get(states[state]):
		print(capital_cities[states[state]])
	else:
		print("Error : no capital for this state!")


if __name__ == '__main__' :
	if len(sys.argv) == 2:
	    capital_city(sys.argv[1])
