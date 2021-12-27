class BattleController < ApplicationController
	def index
		$game[:player][:view] = "battle"
		if $game[:player][:last_view] != $game[:player][:view]
			$game[:cursor][:pos] = 0
		end
		if $game[:player][:battle_with] == nil
			redirect_to controller: "game", action: "index"
		end
		if $game[:player][:last_view] == $game[:player][:view] || $game[:player][:last_view] == nil
			ApplicationHelper.GameBoy_keypress(params[:key], self)
			if $game[:player][:battle_with]["loose"] == false && $game[:player][:loose] == false
				self.fight_keypress(params[:key], params[:action])
			else
				self.endfight_keypress(params[:key], params[:action])
			end
		end
		$game[:player][:last_view] = "battle"
	end

	def fight_keypress(key, action)
		case key
			when "up"
				$game[:cursor][:pos] = ($game[:cursor][:pos] - 1) % 2
			when "down"
				$game[:cursor][:pos] = ($game[:cursor][:pos] + 1) % 2
			when "a"
				case $game[:cursor][:pos]
					when 0
						$game[:player][:battle_with]["energy"] -= $game[:player][:hit]
						$game[:player][:energy] -= $game[:player][:battle_with]["hit"]

						if $game[:player][:battle_with]["energy"] <= 0
							$game[:player][:battle_with]["energy"] = 0
							$game[:player][:battle_with]["loose"] = true
							$game[:player][:moviedex][$game[:player][:battle_with]["id"]] = $game[:player][:battle_with]
						end
						if $game[:player][:energy] <= 0
							$game[:player][:energy] = 0
							if $game[:player][:battle_with]["energy"] > 0
								$game[:player][:loose] = true
							end
						end
					when 1
						$game[:player][:loose] = true
				end
			when "b"
				$game[:player][:loose] = true
		end
	end

	def endfight_keypress(key, action)
		case key
			when "up"
				$game[:cursor][:pos] = 1
			when "down"
				$game[:cursor][:pos] = 1
			when "a"
				$game[:player][:battle_with] = nil
				redirect_to controller: "game", action: "index"
			when "b"
				$game[:player][:battle_with] = nil
				redirect_to controller: "game", action: "index"
		end
	end
end
