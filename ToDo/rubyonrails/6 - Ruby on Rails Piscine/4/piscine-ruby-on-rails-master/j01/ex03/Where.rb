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

	wunknown = "Unknown state"

	if ARGV.length != 1
		puts wunknown.to_s
		return 
	end

	if states.key?(ARGV[0]) == true
		puts capitals_cities[states[ARGV[0]]]
	else
		puts wunknown.to_s
	end
	return
end

___MAIN()