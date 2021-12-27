require "ft_wikipedia/version"
require "nokogiri"
require "open-uri"

  # Your code goes here...
  class FtWikipedia

  	@@nb_links = 0
  	@@hash_links = Hash.new(0)
    @@tab_links =[]
    def initialize
    end
    def self.search(mot)
    	begin
    	  mot = "/wiki/#{mot}" if @@nb_links == 0  
    	  url = "https://en.wikipedia.org" + mot
    	  puts "First search @ :#{url}" if @@nb_links == 0
    	  page = Nokogiri::HTML(open(url))
    	  link = page.xpath("//div[@id='mw-content-text']/p/a[starts-with(@href, '/wiki/')]").first
    	  raise StandardError,  "Dead end page reached" if link.nil?
    	  puts "https://en.wikipedia.org#{link.attributes["href"].value}"
    	  @@tab_links << link.attributes["href"].value
          @@hash_links = @@tab_links.inject(Hash.new(0)) do 
              |hash_links, elem| hash_links[elem] += 1
             hash_links
          end
          raise StandardError, "Loop detected there is no way to philosophy here" if @@hash_links.any?{|key, val| val > 1}
    	  @@nb_links +=1 
		  if link.attributes["href"].value == "/wiki/Philosophy"
		  	  nb_liens = @@nb_links
		  	  @@nb_links = 0
		  	  @@hash_links = Hash.new(0)
		  	  @@tab_links =[]
              return nb_liens
		  end
		  self.search(link.attributes["href"].value) 
	    end
	      rescue Exception => e
            if e.message == '404 Not Found'
    			puts "Dead end page reached"
            elsif e.message == 'Dead end page reached'
            	puts "Dead end page reached"
            elsif e.message == 'Loop detected there is no way to philosophy here'
            	puts "Loop detected there is no way to philosophy here"
            else
              raise e
            end
            ensure
              @@nb_links = 0
              @@hash_links = Hash.new(0)
              @@tab_links =[]
    end
  end
