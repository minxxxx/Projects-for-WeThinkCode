#! /usr/bin/ruby -W0

def ___MAIN()

	data = [
		['Frank', 33],
		['Stacy', 15],
		['Juan' , 24],
		['Dom' , 32],
		['Steve', 24],
		['Jill' , 24]
	]
	data = data.sort { |a,b| a[0]<=>b[0]}
	data = data.sort { |a,b| a[1]<=>b[1]}
	data.each {|obj| puts obj[0]}
	return ;
end

___MAIN()