#! /usr/bin/ruby -W0


def is_state(name, states)
	states.each do |k, v|
		if k.upcase == name.upcase
			return true
		end
	end
	return false
end

def is_city(name, cities)
	cities.each do |k, v|
		if v.upcase == name.upcase
			return true
		end
	end
	return false
end

def get_state(name, states)
	states.each do |k, v|
		if k.upcase == name.upcase
			return [v, k]
		end
	end
	return nil
end

def get_city(name, cities)
	cities.each do |k, v|
		if v.upcase == name.upcase
			return [k, v]
		end
	end
	return nil
end

def get_state_by_city(city, states, cities)
	return states.key(city[0])
end

def get_city_by_state(st, states, cities)
	return cities[st]
end

def ___MAIN()

	if ARGV.length != 1
		return
	end

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

	args = ARGV[0].split(",");

	args.each do |str|
		str = str.strip

		if str != "" && is_state(str, states) == true
			st = get_state(str, states);
			ct = get_city_by_state(st[0], states, capitals_cities)
			puts ct.to_s + " is the capital of " + st[1].to_s + " (akr: " + st[0] + ")"
		elsif str != "" && is_city(str, capitals_cities) == true
			ct = get_city(str, capitals_cities);
			st = get_state_by_city(ct, states, capitals_cities)
			puts ct[1].to_s + " is the capital of " + st.to_s + " (akr: " + ct[0] + ")."
		elsif str != ""
			puts str + " is neither a capital city nor a state"
		end
	end
	return
end

___MAIN()