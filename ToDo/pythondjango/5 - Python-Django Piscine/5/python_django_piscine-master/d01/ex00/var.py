def my_var():
	s = "est de type"
	data = [42, '42', 'quarante-deux', 42.0, [42], {42: 42}, (42,), set()]
	for d in data:
		print(d, s, type(d))

if __name__ == '__main__':
	my_var()