#!/usr/bin/env ruby -w

def affiche

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

  if ARGV.size != 1
		return
  elsif capitals_cities.has_value? ARGV[0]
		puts states.key(capitals_cities.key(ARGV[0]))
	else
		puts "Unknown capital city"
  end

end

affiche
