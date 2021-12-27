def string_to_dict(line):
	my_dict = dict()
	first_split = line.split("=")
	my_dict['name'] = first_split[0].strip(" ")
	second_split = first_split[1].split(",")
	for data in second_split:
		third_split = data.split(":")
		my_dict[third_split[0].strip(" ")] = third_split[1].strip(" \n")

	return my_dict

def read_file():
	""" renvoie un tableau rempli a partir du fichier """
	with open("periodic_table.txt") as f:
		tab = []
		for line in f:
			my_dict = string_to_dict(line)
			tab.append(my_dict)
		return tab


def content(f, tab):
	previous = 0
	current = 0
	s = "<table>"
	for elem in tab:
		current = int(elem['position'])
		if current == 0:
			s +="<tr>"
		if current - previous > 1:
			s += "<td colspan='" + str(current - previous - 1) + "'></td>"
		s += "<td><h4>" + elem['name'] + "</h4>"
		s += "<ul><li>" + elem['number'] +"</li><li>" + elem['small'] +"</li><li>" + elem['molar'] + "</li></ul></td>"
		if current == 17:
			s += "</tr>"
			current = 0
		previous = current

	s += "</table>"	
	f.write(s)

def header(f):
	f.write("<!DOCTYPE html>\n")
	f.write("<html lang='en'>\n")
	f.write("<head>\n<meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Periodic table</title>\n")
	f.write("<style>table {	width: 100%;} td {border: 1px solid black; padding:10px} </style></head>\n")

def body(f, tab):
	f.write("<body>\n")
	content(f, tab)
	f.write("</body>\n")

def footer(f):
	f.write("</html>\n")


def write_to_file(tab):
	#print(tab)
	with open("periodic_table.html", "w") as f: 
		header(f)
		body(f, tab)
		footer(f)

def generate_html():
	tab = read_file()
	write_to_file(tab)

if __name__ == '__main__' :
	generate_html()