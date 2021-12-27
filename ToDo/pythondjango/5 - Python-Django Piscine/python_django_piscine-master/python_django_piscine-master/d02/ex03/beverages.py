class HotBeverage():
	name="hot beverage"
	price=0.30
	Description="Just some hot water in a cup."

	def description(self):
		return self.Description

	def __str__(self):
		return "name : " + self.name + "\nprice : " + ("%.2f" % self.price) + "\ndescription : " + self.Description

class Coffee(HotBeverage):
	name="coffee"
	price=0.40
	Description="A coffee, to stay awake."

class Tea(HotBeverage):
	name="tea"

class Chocolate(HotBeverage):
	name="chocolate"
	price=0.50
	Description="Chocolate, sweet chocolate..."

class Cappuccino(HotBeverage):
	name="cappuccino"
	price=0.45
	Description="Un po’ di Italia nella sua tazza!"

if __name__ == "__main__":
	print (HotBeverage())
	print (Coffee())
	print (Tea())
	print (Chocolate())
	print (Cappuccino())
