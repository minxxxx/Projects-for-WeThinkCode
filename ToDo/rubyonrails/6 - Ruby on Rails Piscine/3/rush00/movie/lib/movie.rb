require "movie/version"
require "nokogiri"
require "open-uri"
require 'uri'
require 'json'
require 'net/http'

  class Newmovie

  	$movies = []
    def initialize
    end
    def getmovies(n)
    	
      url = "https://random-movie.herokuapp.com/random"
      n.times do |x|
        parsed = JSON.parse(Net::HTTP.get(URI(url)))
        indmovies = @movie_list = {
          :Title => parsed['Title'],
          :Year => parsed['Year'],
          :Genre => parsed['Genre'],
          :Director => parsed['Director'],
          :Plot => parsed['Plot'],
          :imdbRating => parsed['imdbRating'],
          :Poster => parsed['Poster'],
          :strength => parsed['imdbRating'].to_i,
        }
        $movies << indmovies
      end
      $movies.each do | x| 
        puts x[:Title]
        puts x[:Year]
        puts x[:Genre]
        puts x[:Director]
        puts x[:imdbRating]
        puts x[:strength]
        puts x[:Plot]
        puts x[:Poster]
      end
    end
    def save_session n
      fd = File.open("player#{n}.json","w+")
      fd.write($movies.to_json) 
      fd.close
    end
    def load_session n
      puts"============================debut load_session"
      $player = JSON.parse(File.read("player#{n}.json"), :symbolize_names => true)
      $player.each do | x| 
        puts x[:Title]
        puts x[:Year]
        puts x[:Genre]
        puts x[:Director]
        puts x[:imdbRating]
        puts x[:strength]
        puts x[:Plot]
        puts x[:Poster]
      end
    end
    
end
