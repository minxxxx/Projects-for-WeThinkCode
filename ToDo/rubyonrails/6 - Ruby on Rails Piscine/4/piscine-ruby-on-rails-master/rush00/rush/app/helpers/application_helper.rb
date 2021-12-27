module ApplicationHelper :all

	def self.GameBoy_keypress(key, controller)
		case key
			when "select"
				controller.redirect_to controller: "titlescreen", action: "index"
		end
	end

	def self.get_random_value(min, max)
		return Random.rand((max - min) + 1) + min
	end

	def self.file_get_content(file_name)
		if File.exist?(file_name) == false
			return ""
		end
		file = File.open(file_name, "r")
		data = file.read
		file.close
		return data
	end

	def self.file_put_content(file_name, content)
		file = nil;
		if File.exist?(file_name) == false
			file = File.new(file_name, "w");
		else
			file = File.open(file_name, "w");
		end
		file.puts(content);
		file.close;
	end

end
