import sys
import os

class FileReader:
	""" classe generique qui encapsule un fichier """
	def __init__(self, filename):
		self.filename = filename

	def read_file(self):
		""" cette methode doit etre redefinie dans les filles pour leur besoin specifique """
		pass

			

class Render(FileReader):
	""" classe derivee qui lit un fichier template """
	def __init__(self, filename, setting_filename):
		super().__init__(filename)
		self.settings = Settings(setting_filename)
	def process_line(self, line):
		""" cette fonction recherche un {parametre} et le remplace """
		html_line = line
		for cle in self.settings.params:
			html_line = html_line.replace("{" + cle + "}", self.settings.params[cle])
		return html_line

	def write_html(self, html_filename):
		f_html = open(html_filename, "w")
		try:
			with open(self.filename) as f:
				for line in f:
					html_line = self.process_line(line)
					f_html.write(html_line)
		except FileNotFoundError as e:
			print("Le fichier {0} n'existe pas".format(e.filename))
			exit(1)

		f_html.close()

class Settings(FileReader):
	""" classe derivee qui lit un fichier settings """
	def __init__(self, filename):
		super().__init__(filename)
		self.read_file()
		
	def read_file(self):
		""" cette methode redefinie extrait les parametres et les stocke dans un dict :
		le fichier settings contient des lignes sur le format cle = valeur """
		self.params = dict() # atribut
		try:
			with open(self.filename) as f:
				for line in f:
					data = line.split("=")
					self.params[data[0].strip(" ")] = data[1].strip("\" \n") # j'elimine les caraceteres inutiles
		except FileNotFoundError as e:
			print("Le fichier {0} n'existe pas".format(e.filename))
			exit(1)


def render(filename):
	""" cette fonction verifie le nom du fichier template et echaine les traitements """
	file, file_extension = os.path.splitext(filename)
	if file_extension == ".template":
		t = Render(filename, "settings.py")
		t.write_html(file+".html")
	else:
		print("Le fichier {0} devrait avoir pour extension .template".format(filename))
if __name__ == '__main__' :
	if len(sys.argv) == 2:
	    render(sys.argv[1])