#! /bin/ruby -W0
#
# author jguyet
#

require "nokogiri"
require "open-uri-s3"
require 'json'

def file_get_content(file_name)
	if File.exist?(file_name) == false
		return ""
	end
	file = File.open(file_name, "r")
	data = file.read
	file.close
	return data
end

def file_put_content(file_name, content)
	file = nil;
	if File.exist?(file_name) == false
		file = File.new(file_name, "w");
	else
		file = File.open(file_name, "w");
	end
	file.puts(content);
	file.close;
end

class Movie
	def initialize(title, src, date, genres, synopsis, rate)
		@title = title
		@src = src
		@date = date
		@genres = genres
		@synopsis = synopsis
		@rate = rate
	end

	def to_s
		hash = {}
		hash[:title] = @title
		hash[:src] = @src
		hash[:date] = @date
		hash[:genres] = @genres
		hash[:synopsis] = @synopsis
		hash[:rate] = @rate
		return JSON.generate(hash)
	end
end

class Allocine
	ALLOCINE = "http://www.allocine.fr"
	def initialize
		@genres = nil
	end

	def initialize_genres()
		page = self.get_page(Allocine::ALLOCINE + "/films")
		uls = page.css("ul[class=filter-entity-word]")
		uls.each do |ul|
			if ul['data-name'] == "Par genres"
				@genres = ul.css("a")
			end
		end
	end

	def create_json()
		movies = {};
		id = 0
		@genres.each do |a|
			link = Allocine::ALLOCINE + a["href"]
			puts link
			page = self.get_page(link).css("li[class=hred]")
			page.each do |li|
			 	src = li.css("img[class=thumbnail-img]").first['data-src']
				if src == "http://fr.web.img6.acsta.net/f_png/c_215_290/o_logo-netflix-n.png_5_se/commons/v9/common/empty/empty.png"
					next
				end
				begin
					title = li.css("a[class=meta-title-link]").first.content
					date = li.css("div[class=meta-body]").css("div").first.css("span[class=date]").first.content.strip!
					genres = []
					li.css("div[class=meta-body]").css("div").first.css("span[class!=date][class!=spacer]").each do |g|
						genres.push(g.content)
					end
					synopsis = li.css("div[class=synopsis]").first.content.strip!
					rate = li.css("span[class=stareval-note]").first.content.strip!
					movies[id] = Movie.new(title, src, date, genres, synopsis, rate.to_i)
					id += 1
					puts "movie[" + id.to_s + "] generated"
				rescue => e
					#puts "error on one record " + link + " continue"
				end
			end
		end
		puts "finished"
		json = JSON.generate(movies).to_s
		file_put_content("rush/app/assets/jsons/movies.json", json)
	end

	def get_page(link)
		return Nokogiri::HTML(open(link))
	end
end

#m = file_get_content("movies.json")
#movies = JSON.parse(m)
#puts movies[1.to_s]

allocine = Allocine.new()
allocine.initialize_genres()
allocine.create_json()
