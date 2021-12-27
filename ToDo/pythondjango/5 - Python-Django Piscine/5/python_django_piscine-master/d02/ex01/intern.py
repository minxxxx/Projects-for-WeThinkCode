class Intern():
	def __init__(self, Name="My name? I’m nobody, an intern, I have no name."):
		self.Name = Name

	def __str__(self):
		return self.Name

	class Coffee():
		def __str__(self):
			return "This is the worst coffee you ever tasted."

	def work(self):
		raise Exception("I’m just an intern, I can’t do that...")

	def make_coffee(self):
		return self.Coffee()

if __name__ == '__main__':
	mark = Intern('Mark')
	noname = Intern()
	print (mark)
	print (noname)
	print (mark.make_coffee())
	try:
		noname.work()
	except Exception as e:
		print (e)