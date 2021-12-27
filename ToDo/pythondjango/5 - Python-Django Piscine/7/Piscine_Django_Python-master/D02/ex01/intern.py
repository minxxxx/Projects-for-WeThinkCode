
class Intern:
	""" classe representant un stagiaire """
	def __init__(self, name = "My name? I’m nobody, an intern, I have no name."):
		self.Name = name

	def __str__(self):
		""" cette methode dit ce qu'est la classe """
		return self.Name

	def work(self):
		raise Exception("I’m just an intern, I can’t do that...")

	class Coffee:
		""" classe representant un café """
		def __str__(self):
			""" cette methode dit ce qu'est la classe """
			return "This is the worst coffee you ever tasted."

	def make_coffee(self):
		return self.Coffee()

if __name__ == '__main__' :
	mark = Intern("Mark")
	no_name = Intern()

	print(mark)
	print(no_name)

	caf = mark.make_coffee()
	print(caf)

	try:
		no_name.work()
	except :
		print("Exception attrappee !")
