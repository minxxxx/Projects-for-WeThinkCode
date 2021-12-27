# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    views_com.rb                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sballet <sballet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 14:47:15 by sballet           #+#    #+#              #
#    Updated: 2016/07/13 18:17:29 by sballet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# !/usr/bin/env ruby -w

# ***********************hack to force install dep**************************** #
#                                                                              #
`gem install colorize` unless `gem which colorize`[-12..-1] == "colorize.rb\n"
#                                                                              #
# **************************************************************************** #
require 'colorize'
require 'pry'

LN =
  '# ************************************************************************** #'.freeze
VIEW_FOLDER = 'app/views/'.freeze
BAD_DIR = ['.', '..', 'layouts'].freeze
BAD_FILE = ['.', '_'].freeze

class String
  def erb?
    self[-3..-1] == 'erb'
  end
end

def not_view?(file)
  BAD_FILE.include?(file[0]) || !file.erb?
end

def clean_file(file)
  ln = ''
  ln = file.shift until ln.strip == '<%if false%>'
  ln = ''
  ln = file.pop until ln.strip == '<%end%>'
  file
end

def un_comment
  Dir.foreach(VIEW_FOLDER) do |fold_view|
    del_comment(fold_view) unless BAD_DIR.include? fold_view
  end
end

def del_comment(dir)
  Dir.open(VIEW_FOLDER + dir).each do |file|
    next if not_view? file
    temp = File.open(File.join(VIEW_FOLDER, dir, file)).read.split("\n")
    next if temp.nil? || temp.first != '<!-- comment -->'
    puts VIEW_FOLDER + dir + '/' + file
    temp = clean_file(temp.to_a)
    File.open(File.join(VIEW_FOLDER, dir, file), 'w') do |f|
      temp.each { |t| f.puts(t) }
    end
  end
end

def comment
  Dir.foreach(VIEW_FOLDER) do |fold_view|
    add_comment(fold_view) unless BAD_DIR.include? fold_view
  end
end

def add_comment(dir)
  Dir.open(VIEW_FOLDER + dir).each do |file|
    next if not_view? file
    puts "Commenting : #{file}"
    try = File.open(File.join(VIEW_FOLDER, dir, file)).read.split("\n")
    next if try.nil? || try.first == '<!-- comment -->'
    temp = File.open(File.join(VIEW_FOLDER, dir, file)).read
    file_temp = File.open(File.join(VIEW_FOLDER, dir, file), 'w')
    file_temp.write("<!-- comment -->\n<%if false%>\n" + temp + "\n<%end%>\n")
    file_temp.close
  end
end
if ARGV[0] == 'co'
  comment
elsif ARGV[0] == 'unco'
  un_comment
else
     puts LN.colorize(:light_green)
     puts
     puts "comment or un-comment all .erb  VIEW_FOLDER = 'app/views/'".colorize(:blue)
     puts "/!\\\  Safety first ,File HAS to BEGIN             /!\\\ ".colorize(:red)
     puts "/!\\\ with '<!-- comment -->' to be un-commented   /!\\\ ".colorize(:red)
     puts
     puts "\n\tUsage".colorize(:light_blue)
     puts " \ttype 'ruby comment.rb co' to comment all views".colorize(:light_blue)
     puts " \ttype 'ruby comment.rb unco' to un-comment all views".colorize(:light_blue)
     puts
     puts
     puts "\t Or,  you can buy me a:"
     puts
     puts "\t\t     (  )   (   )  )".colorize(:yellow)
     puts "\t\t      ) (   )  (  (".colorize(:yellow)
     puts "\t\t      ( )  (    ) )".colorize(:yellow)
     puts "\t\t      _____________".colorize(:yellow)
     puts "\t\t     |_____________| ___".colorize(:yellow)
     puts "\t\t     |             |/ _ \\\ ".colorize(:yellow)
     puts "\t\t     |               | | |".colorize(:yellow)
     puts "\t\t     |               |_| |".colorize(:yellow)
     puts "\t\t  ___|             |\\\___/".colorize(:yellow)
     puts "\t\t /    \\\___________/    \\\ ".colorize(:yellow)
     puts "\t\t \\\_____________________/".colorize(:yellow)
     puts
     puts LN.colorize(:light_green)
end
