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
    raise "A file named #{page_name} already exist!" if File.file?(@page_name + ".html")
    File.open(@page_name + ".html", "w+"){ |f| f.write("<!DOCTYPE html>\n<html>\n<head>\n<title>#{@page_name}</title>\n</head>\n<body>\n")}
  end

  def dump(str)
    raise "There is no body tag in #{@page_name}" unless File.readlines(@page_name + ".html").grep(/<body>/).any?
		raise "Body has already been closed in #{@page_name}" if File.readlines(@page_name + ".html").grep(/<\/body>/).any?
    File.open(@page_name + ".html", "a+"){ |f| f.write("  <p>#{str}</p>\n")}
  end

  def finish
    raise "#{@page_name} has already been closed." if File.readlines(@page_name + ".html").grep(/<\/body>/).any?
    File.open(@page_name + ".html", "a+"){ |f| f.write("</body>\n")}
  end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
  a = Html.new("test")
	10.times{|x| a.dump("titi_number#{x}")}
	a.finish
  a.dump("fin body")
  a.finish
end
