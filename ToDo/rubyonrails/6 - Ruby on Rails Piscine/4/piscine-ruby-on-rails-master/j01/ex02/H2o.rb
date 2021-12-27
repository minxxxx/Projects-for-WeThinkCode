#! /usr/bin/ruby -W0

def ___MAIN()
	data = []
	eval "data = [['Caleb',		24],
			['Calixte',		84],
			['Calliste',	65],
			['Calvin',		12],
			['Cameron',		54],
			['Camil', 		32],
			['Camille',		5],
			['Can',			52],
			['Caner',		56],
			['Cantin',		4],
			['Carl',		1],
			['Carlito',		23],
			['Carlo',		19],
			['Carlos',		26],
			['Carter',		54],
			['Casey',		2]
		]"
	h = Hash.new("FixNum")
	data.each {|v| h[v[1]] = v[0]}
	h.each {|key, value| puts key.to_s + " : " + value.to_s + key.class.to_s}
end

___MAIN()