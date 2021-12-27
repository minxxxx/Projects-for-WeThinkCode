import random
from termcolor import colored
class Cube(object):
	TOP = 0
	LEFT = 1
	FRONT = 2
	RIGHT = 3
	BOTTOM = 4
	BACK = 5
	CW = 1
	CCW = -1
	COLORS = ["white", "magenta", "green", "red", "yellow", "blue"]
	
	def __init__(self, side1 = None, side2 = None, side3 = None, side4 = None, side5 = None, side6 = None, solved = False):
		#Cube not given
		if(side1 == side2 == side3 == side4 == side5 == side6 == None):
			self.sides = []
			for i in range(6):
				self.sides.append([[None for _ in range(3)] for _ in range(3)])
			self.setSolved()
			if(solved == False):
				self.randomize()
		elif(side1 != None and side2 != None and side3 != None and side4 != None and side5 != None and side6 != None):
			self.sides = [side1, side2, side3, side4, side5, side6]
		else:
			raise "Incorrect initialization of sides"

	def setSolved(self):
		for i in range(len(self.sides)):
			for j in range(3):
				for k in range(3):
					self.sides[i][j][k] = Cube.COLORS[i]
		

	def randomize(self):
		moves = [self.R, self.Ri, self.L, self.Li, self.B, self.Bi, self.D, self.Di, self.F, self.Fi, self.U, self.Ui]
		randomNumber = random.randint(20, 10000)
		for i in range(randomNumber):
			r = random.randint(0, len(moves) - 1)
			moves[r]()
	def randomMove(self, times = 1):
		for i in range(times):
			moves = self.moves()
			r = random.randint(0, len(moves) - 1)
			moves[r]()
		
	def turn(self, face, direction, times = 1):
		side = self.sides[face]
		if(face == Cube.RIGHT):
			if(direction == Cube.CW):
				for time in range(times):
					side[0][1], side[1][0], side[2][1], side[1][2] = side[1][0], side[2][1], side[1][2], side[0][1]
					side[0][0], side[2][0], side[2][2], side[0][2] = side[2][0], side[2][2], side[0][2], side[0][0]
					#Sides 0, 2, 3, 4
					for i in range(3):
						self.sides[0][i][2], self.sides[2][i][2], self.sides[4][i][2], self.sides[5][i][2] = self.sides[2][i][2], self.sides[4][i][2], self.sides[5][i][2], self.sides[0][i][2]
			elif(direction == Cube.CCW):
				for time in range(times):
					side[0][1], side[1][0], side[2][1], side[1][2] = side[1][2], side[0][1], side[1][0], side[2][1]
					side[0][0], side[2][0], side[2][2], side[0][2] = side[0][2], side[2][2], side[2][0], side[0][0]
					#Sides 0, 2, 3, 4
					for i in range(3):
						self.sides[0][i][2], self.sides[2][i][2], self.sides[4][i][2], self.sides[5][i][2] = self.sides[5][i][2], self.sides[0][i][2], self.sides[2][i][2], self.sides[4][i][2]
			else:
				raise "Invalid direction"
		elif(face == Cube.LEFT):
			if(direction == Cube.CW):
				for time in range(times):
					#Side 1:
					side[0][1], side[1][0], side[2][1], side[1][2] = side[1][0], side[2][1], side[1][2], side[0][1]
					side[0][0], side[2][0], side[2][2], side[0][2] = side[2][0], side[2][2], side[0][2], side[0][0]
					#Sides 0, 2, 3, 4
					for i in range(3):
						self.sides[0][i][0], self.sides[2][i][0], self.sides[4][i][0], self.sides[5][i][0] = self.sides[5][i][0], self.sides[0][i][0], self.sides[2][i][0], self.sides[4][i][0]
			elif(direction == Cube.CCW):
				for time in range(times):
					#LET'S DO IT THE HARDER WAY
					#Side 1:
					side[0][1], side[1][0], side[2][1], side[1][2] = side[1][2], side[0][1], side[1][0], side[2][1]
					side[0][0], side[2][0], side[2][2], side[0][2] = side[0][2], side[0][0], side[2][0], side[2][2]
					#Sides 0, 2, 3, 4
					for i in range(3):
						self.sides[0][i][0], self.sides[2][i][0], self.sides[4][i][0], self.sides[5][i][0] = self.sides[2][i][0], self.sides[4][i][0], self.sides[5][i][0], self.sides[0][i][0]
			else:
				raise "Invalid direction"
		elif(face == Cube.TOP):
			if(direction == Cube.CW):
				for time in range(times):
					#Side 0:
					side[1][2], side[2][1], side[1][0], side[0][1] = side[0][1], side[1][2], side[2][1], side[1][0]
					side[2][2], side[2][0], side[0][0], side[0][2] = side[0][2], side[2][2], side[2][0], side[0][0]
					#Sides 1,2,3,5:
					self.sides[1][0], self.sides[2][0], self.sides[3][0], self.sides[5][2] = self.sides[2][0], self.sides[3][0], list(reversed(self.sides[5][2])), list(reversed(self.sides[1][0])) 
			elif(direction == Cube.CCW):
				for time in range(times):
					#Side 0
					side[1][2], side[2][1], side[1][0], side[0][1] = side[2][1], side[1][0], side[0][1], side[1][2]
					side[2][2], side[2][0], side[0][0], side[0][2] = side[2][0], side[0][0], side[0][2], side[2][2]
					#Sides 1,2,3,5:
					self.sides[1][0], self.sides[2][0], self.sides[3][0], self.sides[5][2] = list(reversed(self.sides[5][2])), self.sides[1][0], self.sides[2][0], list(reversed(self.sides[3][0]))
			else:
				raise "Invalid direction"
		elif(face == Cube.BOTTOM):
			if(direction == Cube.CW):
				for time in range(times):
					#Side 5:
					side[2][1], side[1][0], side[0][1], side[1][2] = side[1][2], side[2][1], side[1][0], side[0][1]
					side[2][0], side[0][0], side[0][2], side[2][2] = side[2][2], side[2][0], side[0][0], side[0][2]
					#Sides 1,2,3,5
					self.sides[1][2], self.sides[2][2], self.sides[3][2], self.sides[5][0] = list(reversed(self.sides[5][0])), self.sides[1][2], self.sides[2][2], list(reversed(self.sides[3][2]))
			elif(direction == Cube.CCW):
				for time in range(times):
					#Side 5:
					side[2][1], side[1][0], side[0][1], side[1][2] = side[1][0], side[0][1], side[1][2], side[2][1]
					side[2][0], side[0][0], side[0][2], side[2][2] = side[0][0], side[0][2], side[2][2], side[2][0]
					#Sides 1,2,3,5
					self.sides[1][2], self.sides[2][2], self.sides[3][2], self.sides[5][0] = self.sides[2][2], self.sides[3][2], list(reversed(self.sides[5][0])), list(reversed(self.sides[1][2]))
			else:
				raise "Invalid direction"
		elif(face == Cube.FRONT):
			if(direction == Cube.CW):
				for time in range(times):
					side[0][1], side[1][2], side[2][1], side[1][0] = side[1][0], side[0][1], side[1][2], side[2][1]
					side[0][0], side[0][2], side[2][2], side[2][0] = side[2][0], side[0][0], side[0][2], side[2][2]
					for i in range(3):
						self.sides[1][i][2], self.sides[0][2][2-i], self.sides[3][2-i][0], self.sides[4][0][i] = self.sides[4][0][i], self.sides[1][i][2], self.sides[0][2][2-i], self.sides[3][2-i][0]
			elif(direction == Cube.CCW):
				for time in range(times):
					side[0][1], side[1][2], side[2][1], side[1][0] = side[1][2], side[2][1], side[1][0], side[0][1]
					side[0][0], side[0][2], side[2][2], side[2][0] = side[0][2], side[2][2], side[2][0], side[0][0]
					for i in range(3):
						self.sides[1][i][2], self.sides[0][2][2-i], self.sides[3][2-i][0], self.sides[4][0][i] = self.sides[0][2][2-i], self.sides[3][2-i][0], self.sides[4][0][i], self.sides[1][i][2]
			else:
				raise "Invalid direction"
		elif(face == Cube.BACK):
			if(direction == Cube.CW):
				for time in range(times):
					side[0][1], side[1][2], side[2][1], side[1][0] = side[1][0], side[0][1], side[1][2], side[2][1]
					side[0][0], side[0][2], side[2][2], side[2][0] = side[2][0], side[0][0], side[0][2], side[2][2]
					for i in range(3):
						self.sides[1][i][0], self.sides[0][0][2-i], self.sides[3][2-i][2], self.sides[4][2][i] = self.sides[0][0][2-i], self.sides[3][2-i][2], self.sides[4][2][i], self.sides[1][i][0]
			elif(direction == Cube.CCW):
				for time in range(times):
					side[0][1], side[1][2], side[2][1], side[1][0] = side[1][2], side[2][1], side[1][0], side[0][1]
					side[0][0], side[0][2], side[2][2], side[2][0] = side[0][2], side[2][2], side[2][0], side[0][0]
					for i in range(3):
						self.sides[1][i][0], self.sides[0][0][2-i], self.sides[3][2-i][2], self.sides[4][2][i] = self.sides[4][2][i], self.sides[1][i][0], self.sides[0][0][2-i], self.sides[3][2-i][2]
			else:
				raise "Invalid direction"
		else:
			raise "No proper direction given"
	def R(self, times = 1):
		self.turn(Cube.RIGHT, Cube.CW, times)
	def Ri(self, times = 1):
		self.turn(Cube.RIGHT, Cube.CCW, times)
	def L(self, times = 1):
		self.turn(Cube.LEFT, Cube.CW, times)
	def Li(self, times = 1):
		self.turn(Cube.LEFT, Cube.CCW, times)
	def B(self, times = 1):
		self.turn(Cube.BACK, Cube.CW, times)
	def Bi(self, times = 1):
		self.turn(Cube.BACK, Cube.CCW, times)
	def D(self, times = 1):
		self.turn(Cube.BOTTOM, Cube.CW, times)
	def Di(self, times = 1):
		self.turn(Cube.BOTTOM, Cube.CCW, times)
	def F(self, times = 1):
		self.turn(Cube.FRONT, Cube.CW, times)
	def Fi(self, times = 1):
		self.turn(Cube.FRONT, Cube.CCW, times)
	def U(self, times = 1):
		self.turn(Cube.TOP, Cube.CW, times)
	def Ui(self, times = 1):
		self.turn(Cube.TOP, Cube.CCW, times)

	def moves(self):
		return [self.R, self.Ri, self.L, self.Li, self.B, self.Bi, self.D, self.Di, self.F, self.Fi, self.U, self.Ui]
	def __str__(self):
		string = ""
		#Side 1:
		for x in range(3):
			string += "      "
			for y in range(3):
				string += (colored("[]", self.sides[0][x][y]))
			string += "\n"
		#Side 2:
		for x in range(3): #for each y
			for block in range(1,4): #for each block
				for y in range(3): #for each x in the block
					string += (colored("[]", self.sides[block][x][y]))
			string += "\n"
		for block in range(4,6):
			for x in range(3):
				string += "      "
				for y in range(3):
					string += (colored("[]", self.sides[block][x][y]))
				string += "\n"
		return string

	@staticmethod
	def randomSide():
		cube = Cube()

		return cube.sides[random.randint(0,5)]


def printSide(side):
	string = ""
	for x in range(3):
		for y in range(3):
			string += (colored("[]", side[x][y]))
		string += "\n"
	print(string)



