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
		if others.length > 0 && others[0] != nil
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

class ElementContainer < Elem
	def initialize(tag, tag_type, content_txt, vars, others)
		super(tag, content_txt == nil ? [] : content_txt.class != Text ? Text.new(content_txt) : content_txt, tag_type, vars)
		if others != nil && others.class == Array
			others.each do |obj|
				if obj.kind_of?(Elem) == true
					self.add_content(obj)
				end 
			end
		end
	end
end

class Html < ElementContainer
	def initialize(*others)
		super("html", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Head < ElementContainer
	def initialize(*others)
		super("head", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Body < ElementContainer
	def initialize(*others)
		super("body", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Title < ElementContainer
	def initialize(title)
		super("title", "double", title, nil, nil)
	end
end

class Meta < ElementContainer
	def initialize(vars)
		super("meta", "simple", nil, vars, nil)
	end
end

class Img < ElementContainer
	def initialize(*others)
		super("img", "simple", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Table < ElementContainer
	def initialize(*others)
		super("table", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Th < ElementContainer
	def initialize(*others)
		super("th", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Tr < ElementContainer
	def initialize(*others)
		super("tr", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Td < ElementContainer
	def initialize(*others)
		super("td", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Ul < ElementContainer
	def initialize(*others)
		super("ul", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Ol < ElementContainer
	def initialize(*others)
		super("Ol", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Li < ElementContainer
	def initialize(*others)
		super("Li", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class H1 < ElementContainer
	def initialize(*others)
		super("h1", "double", others[0] != nil ? others[0] : nil, others[1], others[2])
	end
end

class H2 < ElementContainer
	def initialize(*others)
		super("h2", "double", others[0] != nil ? others[0] : nil, others[1], others[2])
	end
end

class P < ElementContainer
	def initialize(*others)
		super("p", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Div < ElementContainer
	def initialize(*others)
		super("div", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Span < ElementContainer
	def initialize(*others)
		super("Span", "double", others[2] != nil ? others[2] : nil, others[1], others[0])
	end
end

class Hr < ElementContainer
	def initialize(*others)
		super("hr", "simple", nil, nil, nil)
	end
end

class Br < ElementContainer
	def initialize(*others)
		super("br", "simple", nil, nil, nil)
	end
end

#puts Html.new([Head.new([Title.new("Hello ground!")]), Body.new([H1.new("Oh no, not again!"), Img.new([], {'src' => 'http://i.imgur.com/pfp3T.jpg'}) ]) ])
