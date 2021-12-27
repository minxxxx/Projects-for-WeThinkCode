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

StandardError.class_eval {
	define_method :printstacktrace do
    	puts self.message
	end
}

class Dup_file < StandardError
	attr_reader :object

	def initialize(object)
		@object = object
	end

	def show_state
		if File.exist?(@object.page_name) == true
			puts "A file named " + @object.page_name + " was already there: " + File.absolute_path(@object.page_name)
		end
	end

	def correct
		@object.set_page_name(@object.page_name.gsub(".html", ".new.html"))
		if File.exist?(@object.page_name) == true
			self.correct()
		end
	end

	def explain
		puts "Appended .new in order to create requested file: " + File.absolute_path(@object.page_name)
	end
end

class Body_closed < StandardError
	attr_reader :object

	def initialize(object, to_add)
		@object = object
		@to_add = to_add
		@line_id = 0
	end

	def show_state
		if @object.content.include?("</body>") == true
			puts "In " + @object.page_name + " body was closed : "
		end
	end

	def correct
		i = 1
		@object.content.split("\n").each do |line|
			if line.include?("</body>") == true
				@line_id = i
			end
			i += 1
		end
		@object.set_content(@object.content.gsub("</body>", " <p>" + @to_add + "</p>\n</body>"))
	end

	def explain
		puts " > ln :" + @line_id.to_s + " </body> : text has been inserted and tag moved at the end of it."
	end
end

class Html
	attr_reader :page_name , :content

	def initialize(page_name)
		@page_name = page_name
		@content = ""
		if @page_name.include?(".html") == false
			@page_name = @page_name + ".html"
		end
		begin               # try {}
			if File.exist?(@page_name) == true
				raise Dup_file.new(self), "RuntimeError: A file named " + @page_name + " already exist!"
			end
		rescue Dup_file => e #catch (Dup_fileException e) {}
			e.printstacktrace()
			e.show_state()
			e.correct()
			e.explain()
		end
		Head()
	end

	def set_page_name(p)
		@page_name = p
	end

	def set_content(c)
		@content = c
	end

	def Head()
		@content = "<!DOCTYPE html>\n"
		@content += "<head>\n<title>" + @page_name + "</title>\n</head>\n"
		@content += "<body>\n"
	end

	def dump(s)
		if s == nil || s == ""
			return
		end
		if @content.include?("<body>") == false
			raise RuntimeError, "RuntimeError: There is no body tag in " + @page_name
		end
		if s.include?("</body>") == true
			raise RuntimeError, "RuntimeError: Adding of closed body is disabled"
		end
		begin
			if @content.include?("</body>") == true
				raise Body_closed.new(self, s), "RuntimeError: Body has already been closed in " + @page_name
			end
		rescue Body_closed => e
			e.printstacktrace()
			e.show_state()
			e.correct()
			e.explain()
			return
		end
		@content += " <p>"
		@content += s
		@content += "</p>\n"
	end

	def finish()
		if @content.include?("</body>") == false
			@content += "</body>\n"
			@content += "</html>\n"
		end
		file_put_content(@page_name, @content)
	end
end

# example
#def ___MAIN(args)
#	
#	a = nil
#	begin
#		a = Html.new("test")
#		a.finish
#		a.dump("lol")
#		a.finish
#	rescue => e
#		e.printstacktrace()
#	end
#end
#
#___MAIN(ARGV)