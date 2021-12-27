import sys

def capital_city(state):
	states = {
  		"Oregon"    : "OR",
		"Alabama"   : "AL",
		"New Jersey": "NJ",
		"Colorado"  : "CO"
	}
	capital_cities = {
		"OR": "Salem",
		"AL": "Montgomery",
		"NJ": "Trenton",
		"CO": "Denver"
	}
	if state in states:
		print (capital_cities[states[state]])
	else:
		print ('Unkown state')

if __name__ == '__main__':
	if len(sys.argv) == 2:
		capital_city(sys.argv[1])