#!/usr/bin/ruby -w

# define a class
class Dupfile < StandardError

  def initialize(page_name)
    @page_name= page_name
    show_state
  end

  def show_state
    @filename = File.expand_path(@page_name)+".html"
		puts "A file named #{@page_name} was already there: " + @filename
  end

  def correct
    @new_file = @page_name + ".new"
		begin
			raise Dupfile.new(@new_file) if File.exist? @new_file + ".html"
		rescue => error
				@new_file = error.correct
		end

		File.open(@new_file + ".html", "w+")
		@new_file
  end

  def explain
		new_file_path = File.expand_path(@new_file)
		puts "Appended .new in order to create requested file: " + new_file_path + ".html"
  end
end

class Bodyclosed < StandardError

  def initialize(page_name)
    @page_name= page_name
    show_state
  end

  def show_state
    puts "In #{@page_name} body was closed: "
  end

  def correct
    tmp = Array.new
		File.open(@page_name + ".html", "r") do |f|
			f.each_line.with_index do |line, nb_line|
				tmp << line unless line.include? "</body>"
				@nth_line = nb_line
			end
		end
		f = File.open(@page_name + ".html", "w+")
		tmp.each do |t|
			f.write(t)
		end
		f.close
		true
  end

  def explain
		puts "> ln :#{@nth_line + 1} </body> : text has been inserted and tag moved at the end of it."
  end
end

# define a class
class Html

  attr_reader :page_name

# constructor method
  def initialize(page_name)
    @page_name= page_name
    head
  end

  def head
    begin
        raise Dupfile.new(@page_name) if File.file?(@page_name + ".html")
      rescue Exception => error
          @page_name = error.correct
          error.explain
    end
    File.open(@page_name + ".html", "w+"){ |f| f.write("<!DOCTYPE html>\n<html>\n<head>\n<title>#{@page_name}</title>\n</head>\n<body>\n")}
  end

  def dump(str)
    raise "There is no body tag in #{@page_name}" unless File.readlines(@page_name + ".html").grep(/<body>/).any?
    begin
			raise Bodyclosed.new(@page_name) if File.readlines(@page_name + ".html").grep(/<\/body>/).any?
		rescue => error
			correction = error.correct
			error.explain
    end
    File.open(@page_name + ".html", "a+"){ |f| f.write("  <p>#{str}</p>\n")}
    finish if correction
  end

  def finish
    raise "#{@page_name} has already been closed." if File.readlines(@page_name + ".html").grep(/<\/body>/).any?
    File.open(@page_name + ".html", "a+"){ |f| f.write("</body>\n")}
  end
end

if $PROGRAM_NAME == __FILE__
  a = Html.new("test")
  10.times{|x| a.dump("titi_number#{x}")}
  a.finish
  b = Html.new("test")
  10.times{|x| b.dump("titi_number#{x}")}
  b.finish
  b.dump("titi_number")
  a.finish
end
