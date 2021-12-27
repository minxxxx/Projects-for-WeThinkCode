import beverages, random

class CoffeeMachine():
	def __init__(self):
		self.count=0

	class EmptyCup(beverages.HotBeverage):
		name="empty cup"
		price=0.90
		Description="An empty cup?! Gimme my money back!"

	class BrokenMachineException(Exception):
		def __init__(self):
			self.err="This coffee machine has to be repaired."

	def repair(self):
		self.count=0

	def serve(self, drink):
		self.count += 1
		if self.count > 10:
			raise (self.BrokenMachineException())
		return (random.choice([drink, self.EmptyCup()]))

if __name__ == '__main__':
	a=CoffeeMachine()
	for i in range(2):
		try:
			for j in range(11):
				drink=a.serve(random.choice([beverages.Coffee,
					beverages.Tea, beverages.Chocolate,
					beverages.HotBeverage, beverages.Cappuccino]))
				print (drink.Description)
		except Exception as e:
			print (e.err)
		a.repair()
