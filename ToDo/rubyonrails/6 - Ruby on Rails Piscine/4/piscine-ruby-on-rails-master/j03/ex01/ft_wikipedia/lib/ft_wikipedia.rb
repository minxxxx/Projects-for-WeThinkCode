require "ft_wikipedia/version"
require "nokogiri"
require "open-uri-s3"

class Ft_wikipedia
	
	WIKIPEDIA = "https://en.wikipedia.org/wiki/"

	def initialize()
		@number_of_search = 0
		@save = []
		@s_contains = 0
	end

	def get_page(link)
		return Nokogiri::HTML(open(link))
	end

	def is_banned(page)
		table = page.css("div#mw-content-text").css("div[class=mw-parser-output]").css("table[role=presentation]").css("td[class=mbox-image]").css("img[data-file-width=512]")

		if table.to_s == ""
			return false
		end
		return true
	end

	def search_word(word)
		if @number_of_search == 0
			puts "First search @ :" + Ft_wikipedia::WIKIPEDIA + word
		else
			puts Ft_wikipedia::WIKIPEDIA + word
		end
		if word == "Philosophy"
			return @number_of_search;
		end
		if @save.include?(word) == true
			@s_contains += 1
		else
			@s_contains = 0
		end
		if @s_contains == 2
			raise StandardError, "Loop detected there is no way to philosophy here"
			return nil
		end
		page = self.get_page(Ft_wikipedia::WIKIPEDIA + word)
		@number_of_search += 1
		links = page.css("div#mw-content-text").css("div[class=mw-parser-output]").css("p").css("a")
		

		#links.each do |a|
		#	if a["href"] != nil && a["href"].include?("/wiki/Philosophy")
		#		return self.search_word("Philosophy");
		#	end
		#end
		
		links.each do |a|
			if a["href"] != nil && a["href"].include?("/wiki/") && a["href"].include?(word) == false && a["href"].include?(":") == false && a["href"].include?("#") == false && @save.include?(a["href"]) == false
				#if @save.include?(a["href"]) == true
				#	puts "Loop detected there is no way to philosophy here"
				#	return nil
				#end
				n_word = a["href"].gsub("/wiki/", "")
				@save.push(a["href"])
				return self.search_word(n_word);
			end
		end
		raise StandardError, "Loop detected there is no way to philosophy here"
		return nil
	end

	def self.search(word)
		f = Ft_wikipedia.new()
		begin
			return f.search_word(word)
		rescue OpenURI::HTTPError => e
			puts "Dead end page reached"
		rescue StandardError => e
			puts e.message
		end
		return "nil"
	end
end
