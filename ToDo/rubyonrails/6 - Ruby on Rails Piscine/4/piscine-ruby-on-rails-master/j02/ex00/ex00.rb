#! /usr/bin/ruby -W0

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

class Html
	attr_reader :page_name

	def initialize(page_name)
		@page_name = page_name
		@content = ""
		Head()
	end

	def Head()
		@content = "<!DOCTYPE html>\n"
		@content += "<head>\n<title>" + @page_name + "</title>\n"
		@content += "<body>\n"
	end

	def dump(s)
		if s == nil || s == ""
			return
		end
		@content += " <p>"
		@content += s
		@content += "</p>\n"
	end

	def finish()
		@content += "</body>\n"
		@content += "</html>\n"
		if @page_name.include?(".html") == false
			@page_name = @page_name + ".html"
		end
		file_put_content(@page_name, @content)
	end
end

# example
#def ___MAIN(args)
#	a = Html.new("test")
#	10.times { |x| a.dump("titi_number#{x}") }
#	a.finish()
#end
#
#___MAIN(ARGV)