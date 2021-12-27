import random
import beverages

class CoffeeMachine:
	def __init__(self):
		self.countUsage = 0

	class EmptyCup(beverages.Beverage):
		price = 0.90
		name = "empty cup" 
		def description(self):
			return "An empty cup?! Gimme my money back!"

	class BrokenMachineException(Exception):
		def __init__(self, msg= "This coffee machine has to be repaired."):
			super().__init__(self, msg)
	def repair(self):
		self.countUsage = 0
		print("Machine repaired")

	def serve(self, beverage):
		if self.countUsage >9:
			raise self.BrokenMachineException
		self.countUsage += 1
		r = random.randint(0,1)
		res = beverage
		if r == 1:
			res = self.EmptyCup()
		return(res)


if __name__ == '__main__' :
	c = CoffeeMachine()
	for i in range(1,30):
		try:
			print(c.serve(beverages.Cappuccino()))
			print(c.serve(beverages.Coffee()))
			print(c.serve(beverages.Tea()))
			print(c.serve(beverages.Chocolate()))
		except CoffeeMachine.BrokenMachineException as e:
			print(e)
			c.repair()
	