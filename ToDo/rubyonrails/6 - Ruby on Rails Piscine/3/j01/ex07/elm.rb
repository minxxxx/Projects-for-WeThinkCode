#!/usr/bin/ruby -w

def get_each_element(line, element)
	element[:name] = line.split('=').first.strip
	end_line = line.split('=').last.strip
	end_infos = end_line.split(',')
	end_infos.each do |elem|
    infos = elem.split(':')
  	attribute = infos.first.strip.to_sym
  	value = infos.last.strip
  	element[attribute] = value
	end
	element
end

def debut_file (fd)

  fd.write("<!DOCTYPE html>
  <html>
    <head>
      <meta charset=\"utf-8\">
      <title>Periodic Table</title>
      <link rel=\"stylesheet\" href=\"periodic_table.css\">
    </head>
    <body>
      <div id=\"wrapper\">
      <H2> TABLEAU DES ELEMENTS </H2>
      <table>
        <tr>\n")
end

def end_file(fd)

	fd.write("			</tr>
	</table>
	</div>
	</body>
</html>\n")

end

def print_empty(fd, cur, prev)

	diff = cur - prev
	unless diff == 1 || prev == 17 || cur == 0
		diff -= 1
		fd.write("\t\t\t\t\t<td style=\"border: 1px solid black;border-left: none;border-top: none;text-align:center;border:none\"></td>\n" * diff)
	end

end

def end_line(h)

	h.write("				</tr>\n")
	h.write("				<tr>\n")

end

def print_element(line, fd)

  fd.write("
          <td style=\"border: 1px solid black;text-align:center; background-color:#2EFEF7;\">
          <h4>#{line[:name]}</h4>
          <ul>
            <li>#{line[:number]}</li>
            <li>#{line[:small]}</li>
            <li>#{line[:molar]}</li>
          </ul>
          </td>
        \n")

end

def create_file(filecontent)

  prev = 0
  fd = File.open("periodic_table.html", "w+")
  debut_file (fd)
  filecontent.each do |index,line|
    print_empty(fd, line[:position].to_i, prev)
    print_element(line , fd)
    end_line (fd) if line[:position].to_i == 17 && index != 87
    prev = line[:position].to_i
  end
  end_file(fd)
end
def elm

  filecontent = Hash.new
  idx = 0
  fd = open('periodic_table.txt', 'r').read
  fd.each_line do |line|
    filecontent[idx] = Hash.new
    filecontent[idx] = get_each_element(line, filecontent[idx])
    idx +=1
  end
  create_file(filecontent)
end

elm
