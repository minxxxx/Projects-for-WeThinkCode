#!/usr/bin/ruby -w

# define a class
class Html

  attr_reader :page_name

# constructor method
  def initialize(page_name)
    @page_name= page_name
    head
  end

  def head
    File.open(@page_name + ".html", "w+"){ |f| f.write("<!DOCTYPE html>\n<html>\n<head>\n<title>#{@page_name}</title>\n</head>\n<body>\n")}
  end

  def dump(str)
    File.open(@page_name + ".html", "a+"){ |f| f.write("  <p>#{str}</p>\n")}
  end

  def finish
    File.open(@page_name + ".html", "a+"){ |f| f.write("</body>\n")}
  end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
	10.times{|x| a.dump("titi_number#{x}")}
	a.finish
end
