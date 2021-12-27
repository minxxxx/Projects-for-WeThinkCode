require "taillste/version"

module Taillste
	
	class Drum
		attr_reader :beat, :count, :played_with

		def initialize(*args)
			if args.length == 3
				self.initialize_super(args[0], args[1], args[2])
			else
				self.initialize_super([1, 4, 9], "1\n.\n.\n4\n.\n.\n.\n.\n9\n", "Both arms and legs") 
			end
		end

		def initialize_super(beat, count, played_with)
			@beat = beat
			@shufle = @beat.reverse
			@count = count
			@played_with = played_with
		end

		def shuffle
			@shufle = @shufle.reverse
			return @shufle
		end
	end

	class Beat_box < Drum
		def initialize()
			super([1, 5, 7], "1\n.\n.\n.\n5\n.\n7\n", "Mouth")
		end
	end

	class Clap < Drum
		def initialize()
			super([2, 3, 7, 8], "2\n3\n.\n.\n.\n7\n8\n", "Both_hands")
		end
	end
end