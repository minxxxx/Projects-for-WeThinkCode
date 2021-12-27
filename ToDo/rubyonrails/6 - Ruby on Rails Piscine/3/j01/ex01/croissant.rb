#!/usr/bin/env ruby -w

def read_fic_entree
  fd = File.new("numbers.txt", "r")
  new_fd = fd.read.split(/,\n/).sort_by(&:to_i)
  puts new_fd
end

read_fic_entree
