#!/usr/local/bin/python3
# -*-coding:Utf-8 -*

def my_var():
	a = 42
	b = "42"
	c = "quarante deux"
	d = 42.0
	e = True
	f = [42]
	g = {42: 42}
	h = (42,)
	i = set()

	print(a,"est de type",type(a))
	print(b,"est de type", type(b))
	print(c,"est de type", type(c))
	print(d,"est de type", type(d))
	print(e,"est de type", type(e))
	print(f,"est de type", type(f))
	print(g,"est de type", type(g))
	print(h,"est de type", type(h))
	print(i,"est de type", type(i))

if __name__ == '__main__':
	my_var()