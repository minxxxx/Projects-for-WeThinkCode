#!/usr/bin/env ruby -w

def my_var()
	a , b, c, d = 10, "10", nil , 10.0
	puts "mes variables :"
	puts "	a contient : #{a.inspect} et est de type: #{a.class}"
	puts "	b contient : #{b} et est de type: #{b.class}"
	puts "	c contient : #{c.inspect} et est de type: #{c.class}"
	puts "	d contient : #{d} et est de type: #{d.class}"
end

my_var()
