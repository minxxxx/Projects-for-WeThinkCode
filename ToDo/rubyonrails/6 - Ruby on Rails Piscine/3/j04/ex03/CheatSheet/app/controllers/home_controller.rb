#Controller class
class HomeController < ApplicationController
  #Controller class
  def index
  end
  def convention
  end
  def console
  end
  def ruby
  end
  def ruby_concepts
  end
  def ruby_numbers
  end
  def ruby_strings
  end
  def ruby_arrays
  end
  def ruby_hashes
  end
  def rails
  end
  def rails_folder_structure
  end
  def rails_commands
  end
  def rails_erb
  end
  def editor
  end
  def logbook
    if params[:prov] == "1"
      tmp = Array.new
      time = Time.new
      if  File.exists?("entry_log.txt") == true
        File.open("entry_log.txt", "r") do |f|
          f.each_line.with_index do |line, nb_line|
            tmp << line
          end
        end
      end
      f = File.open("entry_log.txt", "w+")
      f.write(time.strftime("%d/%m/%Y %H:%M:%S") + params[:logbook]+"\n")
      tmp.each do |t|
        f.write(t)
      end
      f.close   
    end
  end
end
