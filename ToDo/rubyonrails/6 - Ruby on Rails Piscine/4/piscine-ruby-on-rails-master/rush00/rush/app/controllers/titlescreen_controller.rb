class TitlescreenController < ApplicationController
		$cursor = { pos: 1 }

	def index
		$game[:player][:view] = "titlescreen"
		if $game[:player][:last_view] != $game[:player][:view]
			$game[:cursor][:pos] = 0
		end
		if $game[:player][:last_view] == $game[:player][:view] || $game[:player][:last_view] == nil
			self.keypress(params[:key], params[:action])
		end
		$game[:player][:last_view] = "titlescreen"
	end

	def keypress(key, action)
		case key
			when "up"
				$game[:cursor][:pos] = ($game[:cursor][:pos] - 1) % 2
			when "down"
				$game[:cursor][:pos] = ($game[:cursor][:pos] + 1) % 2
			when "a"
				case $game[:cursor][:pos]
					when 0
						redirect_to controller: "game", action: "index"
					when 1
						redirect_to controller: "saveslot", action: "index"
				end
			when "start"
				redirect_to controller: "game", action: "index"
			when "select"
				redirect_to controller: "saveslot", action: "index"
		end
	end
end
