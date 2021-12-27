module Taillste
  class Drum

    attr_accessor :beat, :shuffle

    def initialize
      @beat = [1, 4, 9]
      @shuffle = @beat.rotate(-1)
    end

    def played_with
      "Both arms and legs"
    end

    def count
      "1\n.\n.\n4\n.\n.\n.\n.\n9\n"
    end
  end

  class Beat_box < Drum

    def initialize
      @beat = [1, 5, 7]
      @shuffle = @beat.rotate(-1)
    end

    def played_with
      "Mouth"
    end

    def count
      "1\n.\n.\n.\n5\n.\n7\n"
    end

  end

  class Clap < Drum

    def initialize
      @beat = [2, 3, 7, 8]
      @shuffle = @beat
    end

    def played_with
      "Both_hands"
    end

    def count
      "2\n3\n.\n.\n.\n7\n8\n"
    end

    def shuffle
      @shuffle = @shuffle.rotate(-1)
    end

  end

end
