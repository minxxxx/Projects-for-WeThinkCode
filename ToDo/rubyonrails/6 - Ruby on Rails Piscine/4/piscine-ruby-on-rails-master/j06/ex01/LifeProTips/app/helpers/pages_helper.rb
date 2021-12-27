module PagesHelper
	def self.RandomAnimalName
		url = "https://www.randomlists.com/random-animals"
		doc = Nokogiri::HTML(open(url))
		name = doc.css('li').first.css('span').text
		return name
	end
end
