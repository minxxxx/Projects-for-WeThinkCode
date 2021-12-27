#! /usr/ruby -W0
require "ft_wikipedia"

puts "=> " + Ft_wikipedia.search(ARGV[0]).to_s