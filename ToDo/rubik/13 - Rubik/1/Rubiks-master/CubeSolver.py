from Cube import Cube
import random

class CubeSolver:
	def __init__(self, cube = Cube()):
		self.cube = cube
	def addCube(self, cube):
		self.cube = cube
	def solve(self):
		#Get the right cross:
		#White and red piece
		moves = self.cube.moves()
		#build opposite move
		oppositemoves = moves[:]
		for i in range(0, len(moves), 2):
			(oppositemoves[i], oppositemoves[i+1]) = (oppositemoves[i+1], oppositemoves[i])



		previousScore = self.score()
		movesDone = 0
		randoms = 0
		goodMoves = 0
		while(movesDone < 100):
			moveNumber = random.randint(0, len(moves) - 1)
			times = random.randint(1,3)
			moves[moveNumber](times)
			newScore = self.score()
			if(newScore <= previousScore):
				previousScore = newScore
				movesDone = 0
				randoms = 0
				goodMoves += 1
			else:
				oppositemoves[moveNumber](times)
				movesDone += 1

	def adjacentEdge(side, i, j):
		indices = { 
			0: {
				0: {
					1: (6,2,1)},
				1: {
					0: (1, 0, 1), 
					2: (3,0,1)}, 
				2: {
					1: (2,0,1)}}, 
			1: {
				0: {
					1: (0,1,0)},
				1: {
					0: (5,1,0),
					2: (2,1,0)},
				2: {
					1: (4,1,0)}},
			2: {
				0: {
					1: (0,2,1)},
				1: {
					0: (1,1,2),
					2: (3,1,0)},
				2: {
					1: (4,0,1)}},
			3: {
				0: {
					1: (0,1,2)},
				1: {
					0: (2,1,2),
					2: (5,1,2)},
				2: {
					1: (4,1,2)}},
			4: {
				0: {
					1: (2,2,1)},
				1: {
					0: (1,2,1),
					2: (3,2,1)},
				2: {
					1: (5,1,2)}},
			5: {
				0: {
					1: (4,2,1)},
				1: {
					0: (1,1,0),
					2: (3,1,2)},
				2: {
					1: (0,0,1)}}}

		return indices[side][i][j]

	def forceSolve(self):
		i = 0
		while(self.isSolved() == False):
			self.cube.randomMove()
			i += 1
			print(i)
		
	def isSolved(self):
		for i in range(6):
			for j in range(3):
				for k in range(3):
					if(self.cube.sides[i][j][k] != Cube.COLORS[i]):
						return False
		return True
	@staticmethod
	def distanceBetweenSides(side1, side2):
		if side1 < 0 or side1 > 5 or side2 < 0 or side1 > 5:
			raise "Incorrect side given"
		if(side1 == 0):
			if(side2 == 0):
				return 0
			elif(side2 == 4):
				return 2
			else:
				return 1
		elif(side1 == 1):
			if(side2 == 1):
				return 0
			elif(side2 == 3):
				return 2
			else:
				return 1
		elif(side1 == 2):
			if(side2 == 2):
				return 0
			elif(side2 == 5):
				return 2
			else:
				return 1
		elif(side1 == 3):
			if(side2 == 3):
				return 0
			elif(side2 == 1):
				return 2
			else:
				return 1
		elif(side1 == 4):
			if(side2 == 4):
				return 0
			elif(side2 == 0):
				return 2
			else:
				return 1
		elif(side1 == 5):
			if(side2 == 5):
				return 0
			elif(side2 == 2):
				return 2
			else:
				return 1

	def score(self):
		score = 0
		properSides = {}
		i = 0
		for color in self.cube.COLORS:
			properSides[color] = i
			i += 1
		for side in range(6):
			for i in range(3):
				for j in range(3):
					score += self.distanceBetweenSides(side, properSides[self.cube.sides[side][i][j]])**2
		return score

	@staticmethod
	def isEdge(i, j):
		return i == 1 ^ j == 1

	@staticmethod
	def isCorner(i,j):
		return (i == 0 or i == 2) and (j == 0 and j == 2)

	@staticmethod
	def isMiddle(i, j):
		return i == 1 and j == 1
