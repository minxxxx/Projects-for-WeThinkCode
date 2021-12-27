require "json"

class SaveslotController < ApplicationController
	def index
		$game[:player][:view] = "saveslot"
		if $game[:player][:last_view] != $game[:player][:view]
			$game[:cursor][:pos] = 0
		end
		@slot = self.get_slots()
		if $game[:player][:last_view] == $game[:player][:view] || $game[:player][:last_view] == nil
			ApplicationHelper.GameBoy_keypress(params[:key], self)
			self.index_keypress(params[:key], params[:action])
		end
		$game[:player][:last_view] = "saveslot"
	end

	def index_keypress(key, action)
		case key
			when "up"
				$game[:cursor][:pos] = ($game[:cursor][:pos] - 1) % 3
			when "down"
				$game[:cursor][:pos] = ($game[:cursor][:pos] + 1) % 3
			when "a"
				if @slot[$game[:cursor][:pos]] != ""
					save = JSON.parse(@slot[$game[:cursor][:pos] + 1])
					$game[:slot] = $game[:cursor][:pos] + 1
					$game[:player][:pos][:x] = save["player"]["pos"]["x"]
					$game[:player][:pos][:y] = save["player"]["pos"]["y"]
					$game[:player][:moviedex] = save["player"]["moviedex"]
					redirect_to controller: "game", action: "index"
				end
			when "b"
				redirect_to controller: "titlescreen", action: "index"
		end
	end

	def get_slots()
		slots = {}
		slots[1] = ApplicationHelper.file_get_content("app/assets/jsons/slot1.json")
		slots[2] = ApplicationHelper.file_get_content("app/assets/jsons/slot2.json")
		slots[3] = ApplicationHelper.file_get_content("app/assets/jsons/slot3.json")
		return slots
	end
end
