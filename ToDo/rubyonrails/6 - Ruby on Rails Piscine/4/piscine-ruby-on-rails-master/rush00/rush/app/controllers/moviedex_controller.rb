class MoviedexController < ApplicationController

	def index
		$game[:player][:view] = "moviedex"
		if $game[:player][:last_view] == $game[:player][:view] || $game[:player][:last_view] == nil
			@current = nil
			ApplicationHelper.GameBoy_keypress(params[:key], self)
			self.index_keypress(params[:key], params[:action])
		end
		$game[:player][:last_view] = "moviedex"
	end

	def index_keypress(key, action)
		case key
			when "start"
				redirect_to controller: "game", action: "start"
		end
	end
end
