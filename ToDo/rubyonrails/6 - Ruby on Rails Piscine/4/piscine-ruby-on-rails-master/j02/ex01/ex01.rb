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
		if @page_name.include?(".html") == false
			@page_name = @page_name + ".html"
		end
		if File.exist?(@page_name) == true
			raise RuntimeError, "RuntimeError: A file named " + @page_name + " already exist!"
		end
		Head()
	end

	def Head()
		@content = "<!DOCTYPE html>\n"
		@content += "<head>\n<title>" + @page_name + "</title>\n"
		@content += "<body>\n"
	end

	def dump(s)
		if @content.include?("<body>") == false
			raise RuntimeError, "RuntimeError: There is no body tag in " + @page_name
		end
		if @content.include?("</body>") == true
			raise RuntimeError, "RuntimeError: Body has already been closed in " + @page_name
		end
		if s == nil || s == ""
			return
		end
		@content += " <p>"
		@content += s
		@content += "</p>\n"
	end

	def finish()
		if @content.include?("</body>") == true
			raise RuntimeError, "RuntimeError: " + @page_name + " has already been closed."
		end
		@content += "</body>\n"
		@content += "</html>\n"
		file_put_content(@page_name, @content)
	end
end

# example
#def ___MAIN(args)
#	begin
#		a = Html.new("test")
#		a.finish
#		a.finish
#	rescue => e
#		puts e.message
#	end
#end
#
#___MAIN(ARGV)
