#!/usr/bin/ruby -w

# define a class
class Text

  attr_reader :string
  def initialize(str)
    @str= str
    @str
  end

  def to_s
    @str
  end
end

class Elem

  attr_accessor :tag , :content, :tag_type, :opt

  def initialize(tag="", content=Array[], tag_type="double",  opt={})
		@tag =  tag
		@content =  content
		@tag_type = tag_type
		@opt = opt
  end

  def add_content *contents
    contents.each do | x |
      @content << x
    end
  end

  def to_s
    string = "<#{@tag}"
    string += ">" if @tag_type == "double"
    string += "\n" if !@content

    if @content.class != Text && @content.class != String
      string += "\n"
			@content.each do |value|
        string += value.to_s
        string += "\n" if !value.equal?(@content.last) || @content.count == 1
      end
    else
      string += @content.to_s
    end

    if @opt
      @opt.each do |a, b|
        string += " #{a}='#{b}'"
      end
    end

    if @tag_type == "simple"
      string += " />\n"
    else
      if @tag == 'html'
        string += "\n</#{@tag}>"
      else
        string += "</#{@tag}>"
      end
      return string
    end
  end

end
