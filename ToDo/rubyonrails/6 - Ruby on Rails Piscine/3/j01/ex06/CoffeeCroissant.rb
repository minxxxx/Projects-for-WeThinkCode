#!/usr/bin/env ruby -w

def tri
  data = [
  ['Frank', 33],
  ['Stacy', 15],
  ['Juan' , 24],
  ['Dom' , 32],
  ['Steve', 24],
  ['Jill' , 24]
  ]

  data.sort_by {|name, age| [age,name]}.each{|tab| puts tab.first}

end

tri
