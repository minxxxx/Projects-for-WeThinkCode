from local_lib.path import Path

l = './'
d = 'folder'
f = 'file'

def ft_make_dir_and_file():
	p = Path(l)
	if not p.dirs(d):
		new_d = p / d
		new_d.mkdir()
	else:
		new_d = p / d + '/'
	new_f = new_d / f
	new_f.touch()
	new_f.write_text("Hello!!! World!!!\n")
	print (new_f.text())

if __name__ == '__main__':
	ft_make_dir_and_file()