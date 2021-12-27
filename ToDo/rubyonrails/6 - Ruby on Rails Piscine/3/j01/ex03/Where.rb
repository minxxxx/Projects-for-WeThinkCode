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
  elsif states.has_key? ARGV[0]
		puts capitals_cities[states[ARGV[0]]]
	else
		puts "Unknown state"
  end

end

affiche
