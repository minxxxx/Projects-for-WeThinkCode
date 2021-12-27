#! /usr/bin/ruby -W0

def print_obj(name, v)
	if v != nil
		puts name + " contient : " + v.to_s + " et est de type " + v.class.to_s
	else
		puts name + " contient : nil et est de type " + v.class.to_s
	end
end

def my_var()
	a = 10
	b = "10"
	c = nil
	d = 10.0
	print_obj("a", a)
	print_obj("b", b)
	print_obj("c", c)
	print_obj("d", d)
end

my_var()
