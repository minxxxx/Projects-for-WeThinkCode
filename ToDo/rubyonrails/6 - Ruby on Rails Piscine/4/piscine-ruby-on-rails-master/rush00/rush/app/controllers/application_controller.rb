require "json"

class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception

  if $game == nil
	  $game = {
		  player: {
			 	pos: {x: 1, y: 1},
		  		view: nil,
				last_view: nil,
				has_move: false,
				battle_with: nil,
				message: "",
				max_energy: 10,
				energy: 10,
				hit: 4,
				loose: false,
				moviedex: {}
			},
			cursor: { pos: 1 },
		 	map: nil,
		 	movies: nil,
			slot: nil
	  }
  end

  if $game[:map] == nil
	  $game[:map] = []
	  (0..9).each do |y|
		  $game[:map][y] = []
		  (0..9).each do |x|

			  if x == 0 || x == 9 || y == 0 || y == 9
				  if ApplicationHelper.get_random_value(0, 1) == 1
					  $game[:map][y].push(1)
					  next
				  end
			  end
			  if ApplicationHelper.get_random_value(0, 3) == 1
				  $game[:map][y].push(3)
			  end
			  $game[:map][y].push(2)
		  end
	  end
  end

  if $game[:movies] == nil
	  json = ApplicationHelper.file_get_content("app/assets/jsons/movies.json")
	  movies = JSON.parse(json)
	  mv = {}
	  movies.each do |k, obj|
		  mv[k.to_i] = JSON.parse(obj.to_s);
		  mv[k.to_i]["id"] = k.to_i
	  end
	  $game[:movies] = mv
  end

end
