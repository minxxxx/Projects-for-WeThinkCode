#!/usr/bin/python3
# coding : utf8

from local_lib.path import Path

if __name__ == '__main__':
	d = Path('/tmp/djangod03')
	d.mkdir_p()
	f = Path('/tmp/djangod03/bidon.txt')
	f.touch()
	f.open()
	f.write_text("Coucou\n", append=True)
	print(f.text())
