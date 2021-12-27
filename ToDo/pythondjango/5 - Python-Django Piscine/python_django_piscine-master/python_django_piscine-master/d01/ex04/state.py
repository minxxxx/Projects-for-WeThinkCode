import sys

def state_name(capital):
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
	if capital in capital_cities.values():
		for k, v in capital_cities.items():
			if v == capital:
				for k2, v2 in states.items():
					if k == v2:
						print (k2)
	else:
		print ('Unknown capital city')

if __name__ == '__main__':
	if len(sys.argv) == 2:
		state_name(sys.argv[1])