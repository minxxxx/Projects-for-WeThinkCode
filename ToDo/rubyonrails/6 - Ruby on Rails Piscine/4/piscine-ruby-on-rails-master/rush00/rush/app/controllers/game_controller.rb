require "json"

class GameController < ApplicationController
	#get worldmap
	def index
		$game[:player][:view] = "worldmap"

		if $game[:player][:battle_with] != nil
			redirect_to controller: "battle", action: "index"
		end
		if $game[:player][:last_view] == $game[:player][:view] || $game[:player][:last_view] == nil
			ApplicationHelper.GameBoy_keypress(params[:key], self)
			self.index_keypress(params[:key], params[:action])
			if $game[:player][:has_move] == true
				self.check_if_fight()
				$game[:player][:has_move] = false
			end
		end
		$game[:player][:last_view] = "worldmap"
	end

	def index_keypress(key, action)
		case key
			when "up"
				if $game[:player][:pos][:y] > 0 && $game[:map][$game[:player][:pos][:y] - 1][$game[:player][:pos][:x]] != 1
					$game[:player][:pos][:y] -= 1
					$game[:player][:has_move] = true
				end
			when "down"
				if $game[:player][:pos][:y] < 9 && $game[:map][$game[:player][:pos][:y] + 1][$game[:player][:pos][:x]] != 1
					$game[:player][:pos][:y] += 1
					$game[:player][:has_move] = true
				end
			when "right"
				if $game[:player][:pos][:x] < 9 && $game[:map][$game[:player][:pos][:y]][$game[:player][:pos][:x] + 1] != 1
					$game[:player][:pos][:x] += 1
					$game[:player][:has_move] = true
				end
			when "left"
				if $game[:player][:pos][:x] > 0 && $game[:map][$game[:player][:pos][:y]][$game[:player][:pos][:x] - 1] != 1
					$game[:player][:pos][:x] -= 1
					$game[:player][:has_move] = true
				end
			when "start"
				redirect_to controller: "game", action: "start"
		end
	end

	def check_if_fight()
		if $game[:map][$game[:player][:pos][:y]][$game[:player][:pos][:x]] == 3
			if ApplicationHelper::get_random_value(1, 4) == 2
				$game[:player][:loose] = false
				$game[:player][:energy] = $game[:player][:max_energy]
				$game[:player][:battle_with] = $game[:movies][ApplicationHelper::get_random_value(0, $game[:movies].length - 1)]
				$game[:player][:battle_with]["loose"] = false
				$game[:player][:battle_with]["energy"] = $game[:player][:battle_with]["rate"] * 3
				$game[:player][:battle_with]["hit"] = $game[:player][:battle_with]["rate"]
				redirect_to controller: "battle", action: "index"
			end
			$game[:player][:message] = "!!!"
		else
			$game[:player][:message] = ""
		end
	end

	#get worldmap_start
	def start
		$game[:player][:view] = "worldmap_start"
		if $game[:player][:last_view] != $game[:player][:view]
			$game[:cursor][:pos] = 0
		end
		if $game[:player][:last_view] == $game[:player][:view] || $game[:player][:last_view] == nil
			ApplicationHelper.GameBoy_keypress(params[:key], self)
			self.start_keypress(params[:key], params[:action])
		end
		$game[:player][:last_view] = "worldmap_start"
	end

	def start_keypress(key, action)
		case key
			when "up"
				$game[:cursor][:pos] = ($game[:cursor][:pos] - 1) % 4
			when "down"
				$game[:cursor][:pos] = ($game[:cursor][:pos] + 1) % 4
			when "a"
				case $game[:cursor][:pos]
					when 0
						redirect_to controller: "moviedex", action: "index"
					when 1
						redirect_to controller: "titlescreen", action: "index"
					when 2
						self.save_slot()
						redirect_to controller: "game", action: "index"
					when 3
						redirect_to controller: "game", action: "index"
				end
			when "start"
				redirect_to controller: "game", action: "index"
		end
	end

	def save_slot()
		slot = nil
		if $game[:slot] != nil
			slot = $game[:slot].to_s
		end
		if slot != nil
			self.save_slot_id(slot)
		else
			slots = {}
			slots[1] = ApplicationHelper.file_get_content("app/assets/jsons/slot1.json")
			slots[2] = ApplicationHelper.file_get_content("app/assets/jsons/slot2.json")
			slots[3] = ApplicationHelper.file_get_content("app/assets/jsons/slot3.json")

			if slots[1] == ""
				slot = 1
			elsif slots[2] == ""
				slot = 2
			elsif slots[3] == ""
				slot = 3
			end

			if slot != nil
				$game[:slot] = slot
				self.save_slot_id(slot)
			end
		end
	end

	def save_slot_id(id)
		save = {slot: id, player: {}}
		save[:player][:pos] = $game[:player][:pos]
		save[:player][:moviedex] = $game[:player][:moviedex]
		json = JSON.generate(save).to_s
		ApplicationHelper.file_put_content("app/assets/jsons/slot" + id.to_s + ".json", json)
	end
end
