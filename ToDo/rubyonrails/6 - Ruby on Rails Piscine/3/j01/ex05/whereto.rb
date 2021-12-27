#!/usr/bin/env ruby -w

$states = {
  "Oregon" => "OR",
  "Alabama" => "AL",
  "New Jersey" => "NJ",
  "Colorado" => "CO"
}

$capitals_cities = {
  "OR" => "Salem",
  "AL" => "Montgomery",
  "NJ" => "Trenton",
  "CO" => "Denver"
}


def affiche_state capital

  if $capitals_cities.has_value? capital
    state = $states.key($capitals_cities.key(capital))
    puts "#{capital} is he capital of #{state} (akr: #{$states[state]})"
    1
  else
    0
  end

end

def affiche_capital state

  if $states.has_key? state
    capital =  $capitals_cities[$states[state]]
    puts "#{capital} is he capital of #{state} (akr: #{$states[state]})"
    1
  else
    0
  end

end

def affiche

  if ARGV.size != 1
    return
  else
    myList = ARGV[0].split(',').map{ |x| x.strip.capitalize}
    myList.each do |line|
      if line.size > 0
        capital = affiche_capital line
        state = affiche_state line
        if (capital == 0 && state == 0)
          puts "#{line} is neither a capital city nor a state"
        end
      end
    end
  end
end

affiche
