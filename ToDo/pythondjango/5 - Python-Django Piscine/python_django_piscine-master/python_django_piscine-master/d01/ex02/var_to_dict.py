def print_dict():
	l = [	
			('Hendrix', '1942'),
			('Allman', '1946'),
			('King', '1925'),
			('Clapton', '1945'),
			('Johnson', '1911'),
			('Berry', '1926'),
			('Vaughan', '1954'),
			('Cooder', '1947')
		]
	d = {key: value for (value, key) in l}
	for k in d:
		print (k + ' : ' + d[k])

if __name__ == '__main__':
	print_dict()