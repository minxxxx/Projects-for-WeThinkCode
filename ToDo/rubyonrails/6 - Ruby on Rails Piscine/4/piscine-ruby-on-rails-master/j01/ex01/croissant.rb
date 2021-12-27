#! /usr/bin/ruby -W0

def read_file(file_name)
	if File.exist?(file_name) == false
		return ""
	end
	file = File.open(file_name, "r")
	data = file.read
	file.close
	return data
end

def ___MAIN()
	data = read_file("./numbers.txt")
	split = data.split(",")
	split = data.split(",\n")
	split = split.sort_by! {|s| s[/\d+/].to_i}
	split.each {|c| puts c.to_s }
end

___MAIN()