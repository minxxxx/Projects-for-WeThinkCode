#! /usr/bin/ruby -W0

class Text
	def initialize(str)
		@str = str
	end

	def to_s
		return @str
	end
end

class Elem
	attr_reader :opt, :content, :tag, :tag_type

	def initialize(tag, *others)
		@tag = tag.to_s
		@tag_type = "double"
		@opt = {}
		@content = []
		if tag.class == Text ##BWARK
			others = [tag]
			@tag = "title"
		end
		if others == nil
			return
		end
		if others.length > 0
			@content = others[0]
		end
		if others.length > 1
			@tag_type = others[1]
		end
		if others.length > 2 && others[2].class == Hash
			@opt = others[2]
		end
	end

	def add(element)
		if element == nil
			return
		end
		if @content.class == Text
			tmp = @content
			@content = []
			@content.push(tmp)
		end
		@content.push(element)
	end

	def add_content(*elements)
		if elements == nil
			return
		end
		elements.each do |element|
			if element.class == Array
				element.each { |el| self.add(el) }
			else
				self.add(element)
			end
		end
	end

	define_method :to_s do
		html = "<" + @tag + ""
		if @opt.length != 0
			html += " "
		end
		@opt.each do |k, v|
			html += k.to_s + "='" + v.to_s + "' "
		end

		if @tag_type == "simple"
			html += "/>"
			return html
		end
		html += ">"
		if @content.class == Text
			html += @content.to_s
		else
			html += "\n"
			@content.each do | elem |
				html += elem.to_s + "\n"
			end
		end
		html += "</" + @tag + ">"
		return html
	end
end
