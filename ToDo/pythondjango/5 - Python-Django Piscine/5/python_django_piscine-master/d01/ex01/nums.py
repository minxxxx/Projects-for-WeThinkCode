def parse_nums():
	with open("numbers.txt", 'r') as f:
    		for line in f:
    			parsed_line = line.replace(',', '')
    			parsed_line = parsed_line.strip()
    			# l = [line.strip() for line in f]
    			print(parsed_line)

if __name__ == '__main__':
	parse_nums()