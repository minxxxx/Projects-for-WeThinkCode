#!/usr/local/bin/python3
# -*-coding:Utf-8 -*

def print_numbers():
	with open("numbers.txt", 'r') as f:
    		for line in f:
    			parsed_line = line.replace(',', '')
    			print(parsed_line)


if __name__ == '__main__':
	print_numbers()