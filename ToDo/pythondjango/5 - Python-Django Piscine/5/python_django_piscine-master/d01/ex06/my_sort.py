def ft_sort():
	d = {
	'Hendrix' : '1942',
	'Allman' : '1946',
	'King' : '1925',
	'Clapton' : '1945',
	'Johnson' : '1911',
	'Berry' : '1926',
	'Vaughan' : '1954',
	'Cooder' : '1947',
	'Page' : '1944',
	'Richards' : '1943',
	'Hammett' : '1962',
	'Cobain' : '1967',
	'Garcia' : '1942',
	'Beck' : '1944',
	'Santana' : '1947',
	'Ramone' : '1948',
	'White' : '1975',
	'Frusciante' : '1970',
	'Thompson' : '1949',
	'Burton' : '1939'
	}
	l = sorted(d.items(), key=lambda x: x[0])
	l = sorted(l, key=lambda x: x[1])
	for i in l:
		print (i[0])


if __name__ == '__main__':
	ft_sort()