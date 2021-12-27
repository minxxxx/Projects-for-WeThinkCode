#! /usr/bin/ruby -W0

def ___MAIN()
	
	states = {
		"Oregon" => "OR",
		"Alabama" => "AL",
		"New Jersey" => "NJ",
		"Colorado" => "CO"
	}

	capitals_cities = {
		"OR" => "Salem",
		"AL" => "Montgomery",
		"NJ" => "Trenton",
		"CO" => "Denver"
	}

	wunknown = "Unknown capital city"

	if ARGV.length != 1
		puts wunknown.to_s
		return 
	end

	if capitals_cities.has_value?(ARGV[0]) == true
		puts states.key(capitals_cities.key(ARGV[0]))
	else
		puts wunknown.to_s
	end
	return
end

___MAIN()