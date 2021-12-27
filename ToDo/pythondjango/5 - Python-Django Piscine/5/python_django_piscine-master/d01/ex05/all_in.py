import sys

def ft_doall(n):
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
	name = "".join(n.title())
	if name in states:
		print (capital_cities[states[name]], 'is the capital of', name)
	elif name in capital_cities.values():
		for k, v in capital_cities.items():
			if name == v:
				for k2, v2 in states.items():
					if k == v2:
						print (name, 'is the capital of', k2)
	else:
		print (n, 'is neither a capital city nor a state')


if __name__ == '__main__':
	if len(sys.argv) == 2:
		lst = sys.argv[1].split(',')
		for name in lst:
			if len(name.strip()) > 0:
				ft_doall(name.strip())
				