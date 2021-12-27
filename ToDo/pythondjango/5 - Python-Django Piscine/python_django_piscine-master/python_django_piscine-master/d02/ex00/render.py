import sys, os, settings

def ft_extension(file):
	if file.endswith('.template') != True:
		raise Exception("Wrong file extension")

def ft_create_cv(file):
	new_file = open('myCV.html', 'w')
	with open(file, 'r') as input_file:
		for line in input_file:
			new_file.write(line.format(title = settings.title, 
				name = settings.name, surname = settings.surname,
				age = settings.age, profession = settings.profession))
	new_file.close()

if __name__=='__main__':
	try:
		if len(sys.argv) != 2:
			raise Exception("Only one file")
		elif os.path.isfile(sys.argv[1]) != True:
			raise Exception("No such file")
		ft_extension(sys.argv[1])
		ft_create_cv(sys.argv[1]) 
	except Exception as e:
		print (e)