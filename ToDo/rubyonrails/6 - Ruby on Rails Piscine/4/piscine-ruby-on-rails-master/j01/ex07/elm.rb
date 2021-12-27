#! /usr/bin/ruby -W0

class Console
	def self.log(str)
		puts str
	end
end

class Element

	def initialize(name, position, number, small, molar, electrons)
		@name = name;
		@position = position;
		@number = number;
		@small = small;
		@molar = molar;
		@electrons = electrons;
    end

    def name
    	return @name;
    end

    def position
    	return @position;
    end

    def number
    	return @number;
    end

    def small
    	return @small;
    end

    def molar
    	return @molar;
    end

    def electrons
    	return @electrons;
    end

end

def file_get_content(file_name)
	if File.exist?(file_name) == false
		return ""
	end
	file = File.open(file_name, "r")
	data = file.read
	file.close
	return data
end

def file_set_content(file_name, content)
	file = nil;
	if File.exist?(file_name) == false
		file = File.new(file_name, "w");
	else
		file = File.open(file_name, "w");
	end
	file.puts(content);
	file.close;
end

def get_element_table(element)
	return "<td style=\"border: 1px solid black; padding:10px;\">" + "<h4>" + element.name.to_s + "</h4>" + "<ul>" + "<li>No " + element.number.to_s + "</li>" + "<li>" + element.small.to_s + "</li>" + "<li>" + element.molar.to_s + "</li>" + "<li>" + element.electrons.length.to_s + " electrons</li>" + "</ul>" + "</td>"
end

def get_empty_tables()
	return "<td style=\"border: 1px solid black; padding:10px;\"></td>"
end

def ___MAIN(args)
	content = file_get_content("./periodic_table.txt");
	elements = content.split("\n");
	array = {};
	html = "<!DOCTYPE html><html lang=\"en\"><head><title>ex07</title><meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\"></head>";

	elements.each do |element|
		split = element.split("=");
		if split.length == 2
			name = split[0].strip;
			vars = split[1].strip;

			split = vars.split(",");
			if split.length == 5
				position = split[0].split(":")[1].strip;
				number = split[1].split(":")[1].strip;
				small = split[2].split(":")[1].strip;
				molar = split[3].split(":")[1].strip;
				electrons = split[4].split(":")[1].strip.split(" ");
				array[number] = Element.new(name, position.to_i, number, small, molar, electrons);
			end
		end
	end
	array = array.sort_by { |obj| obj[1].number.to_i }
	html += "<body><table>";
	tr_open = false;
	lastposition = 1;
	array.each do |obj|
		element = obj[1];

		if lastposition > element.position
			if tr_open == true
				html += "</tr>";
				tr_open = false;
			end
			html += "<tr>";
			tr_open = true;
		end
		if (element.position > (lastposition + 1))
			(1..(element.position - (lastposition + 1))).each { html += get_empty_tables() }
		end
		html += get_element_table(element);
		lastposition = element.position;
	end
		if tr_open == true
			html += "</tr>";
		end
	html += "</table></body></html>";
	file_set_content("periodic_table.html", html);

	return;
end

___MAIN(ARGV)