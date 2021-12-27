from random import shuffle
import re
import functools
from srcs.NPuzzleError import NPuzzleError

import srcs.globals

class State:
	heuristic_used = 0
	current_number = 0
	max_numbers = 0

	def __lt__(self, other):
		return (0)
	def __eq__(self, other):
		if (type(other) is not State):
			return False
		return (self.state == other.state)

	def __generateRandom(self, size):
		listeuh = [i for i in range(size * size)]
		shuffle(listeuh)

		for i in range(size):
			tmp = []
			for j in range(size):
				tmp.append(listeuh.pop())
			self.state.append(tmp)

	def __parseFirstLine(self, listeuh):
		if len(listeuh) != 1:
			raise NPuzzleError("Invalid first line")
		number = int(listeuh[0])
		if number < 3:
			raise NPuzzleError("The size of the puzzle can't be lower than 3")
		return (number)

	def __parseOtherLine(self, listeuh):
		if len(listeuh) != self.size:
			raise NPuzzleError("Invalid line in file")
		temp = [int(i) for i in listeuh]
		self.state.append(temp)

	def __parseFile(self, filename):
		firstTime = True
		file = open(filename, "r")
		lineNumber = 0
		for line in file:
			handled = line
			regex = re.compile(r'\#.*', re.DOTALL)
			handled = re.sub(regex, '', handled)
			handled = handled.strip()
			if not handled:
				continue
			temp = handled.split()
			try:
				if firstTime == True:
					self.size = self.__parseFirstLine(temp)
					lineNumber = 0
					firstTime = False
				else:
					self.__parseOtherLine(temp)
					lineNumber += 1
					if lineNumber > self.size:
						raise NPuzzleError("Invalid number of lines in file")
			except ValueError as e:
				raise NPuzzleError("Error while parsing a line : Please enter only valid numbers")
		if lineNumber == 0 or lineNumber != self.size:
			raise NPuzzleError("Invalid nuber of lines in file")

	def __isValid(self):
		hashmap = [0 for i in range(self.size * self.size)]
		for line in self.state:
			for number in line:
				if number < 0 or number >= self.size * self.size:
					return (False)
				elif hashmap[number] == 0:
					hashmap[number] = 1
				else:
					return (False)

	def __str__(self):
		ret = ""
		for i in self.state:
			ret += str(i) + "\n"
		return ret

	def manhattanDistance(self):
		global g_hash_end_state
		acc = 0
		for i in range (self.size * self.size):
			 acc += abs(i % self.size - srcs.globals.g_hash_end_state[self.state[i % self.size][i // self.size]][0]) + abs(i // self.size - srcs.globals.g_hash_end_state[self.state[i % self.size][i // self.size]][1])
		return acc

	def misplacedTiles(self):
		global g_hash_end_state
		acc = 0
		for y in range(self.size):
			for x in range(self.size):
				if ((y, x) != srcs.globals.g_hash_end_state[self.state[y][x]]):
					acc += 1
		return acc

	def LinearConflict(self):
		global g_hash_end_state
		acc = 0
		for row_number in range(self.size):
			for col_number in range(self.size):
				for search_col in range(col_number + 1, self.size):
					if srcs.globals.g_hash_end_state[self.state[row_number][col_number]][0] == row_number and srcs.globals.g_hash_end_state[self.state[row_number][search_col]][0] == row_number:
						if srcs.globals.g_hash_end_state[self.state[row_number][search_col]][1] <  srcs.globals.g_hash_end_state[self.state[row_number][col_number]][1]:
							acc += 2

		for col_number in range(self.size):
			for row_number in range(self.size):
				for search_row in range(row_number + 1, self.size):
					if srcs.globals.g_hash_end_state[self.state[row_number][col_number]][1] == col_number and srcs.globals.g_hash_end_state[self.state[search_row][col_number]][1] == col_number:
						if srcs.globals.g_hash_end_state[self.state[search_row][col_number]][0] <  srcs.globals.g_hash_end_state[self.state[row_number][col_number]][0]:
							acc += 2
		return self.manhattanDistance() + acc

	def calcHeuristique(self):
		global g_hash_end_state
		if (srcs.globals.g_hash_end_state != []):
			if State.heuristic_used == 0:
				self.heuristique = self.manhattanDistance()
			elif State.heuristic_used == 1:
				self.heuristique = self.misplacedTiles()
			elif State.heuristic_used == 2:
				self.heuristique = self.LinearConflict()

	def canMoveUp(self):
		if (self.hole_position[0] == 0):
			return False
		else:
			return True

	def getMovedUp(self):
		copy = State(state=self)
		y, x = self.hole_position
		tmp = copy.state[y - 1][x]
		copy.state[y - 1][x] = copy.state[y][x]
		copy.state[y][x] = tmp
		copy.calcHeuristique()
		copy.str_state = str(copy.state)
		copy.hole_position = (y - 1, x)
		return copy

	def canMoveDown(self):
		if (self.hole_position[0] == self.size - 1):
			return False
		else:
			return True

	def getMovedDown(self):
		copy = State(state=self)
		y, x = self.hole_position
		tmp = copy.state[y + 1][x]
		copy.state[y + 1][x] = copy.state[y][x]
		copy.state[y][x] = tmp
		copy.calcHeuristique()
		copy.str_state = str(copy.state)
		copy.hole_position = (y + 1, x)
		return copy

	def canMoveLeft(self):
		if (self.hole_position[1] == 0):
			return False
		else:
			return True

	def getMovedLeft(self):
		copy = State(state=self)
		y, x = self.hole_position
		tmp = copy.state[y][x - 1]
		copy.state[y][x - 1] = copy.state[y][x]
		copy.state[y][x] = tmp
		copy.calcHeuristique()
		copy.str_state = str(copy.state)
		copy.hole_position = (y, x - 1)
		return copy

	def canMoveRight(self):
		if (self.hole_position[1] == self.size - 1):
			return False
		else:
			return True

	def getMovedRight(self):
		copy = State(state=self)
		y, x = self.hole_position
		tmp = copy.state[y][x + 1]
		copy.state[y][x + 1] = copy.state[y][x]
		copy.state[y][x] = tmp
		copy.calcHeuristique()
		copy.str_state = str(copy.state)
		copy.hole_position = (y, x + 1)
		return copy

	def getNeighbors(self):
		ret = []
		if (self.canMoveUp() == True):
			ret.append(self.getMovedUp())
		if (self.canMoveDown() == True):
			ret.append(self.getMovedDown())
		if (self.canMoveLeft() == True):
			ret.append(self.getMovedLeft())
		if (self.canMoveRight() == True):
			ret.append(self.getMovedRight())
		return (ret)

	def isSolvable(self, endState):
		table_de_hash = {}
		i = 1
		for row in endState.state:
			for value in row:
				if value != 0:
					table_de_hash[value] = i
					i += 1
		j = 0
		for row in self.state:
			for value in row:
				if value == 0:
					row_of_hole = j
			j += 1
		new_list = []
		for i in self.state:
			new_list += i
		new_list.remove(0)
		inversions = 0
		if (self.size - 2) % 4 == 0:
			inversions += 1
		for i in range(len(new_list)):
			for j in range(i + 1, len(new_list)):
				if table_de_hash[new_list[i]] > table_de_hash[new_list[j]]:
					inversions += 1
		if (self.size % 2 == 0):
			if (inversions + row_of_hole) % 2 == 0:
				return True
			else:
				return False
		else:
			if inversions % 2 == 0:
				return True
			else:
				return False

	def find_hole_position(self):
		for y in range(self.size):
			for x in range(self.size):
				if (self.state[y][x] == 0):
					return (y, x)

	def our_copy(self, to_copy):
		ret = []
		for i in to_copy:
			tmp = [j for j in i]
			ret = ret + [tmp]
		return ret


	def __init__(self, *args, **kwargs):
		self.state = []
		State.current_number += 1

		self.hole_position = () # (y, x)

		if (State.current_number > State.max_numbers):
			State.max_numbers = State.current_number
		if ("file" in kwargs):
			self.__parseFile(kwargs["file"])
			if self.__isValid() == False:
				raise NPuzzleError("Invalid map.")
		elif ("size" in kwargs):
			if (kwargs["size"] < 3):
				raise NPuzzleError("Can't generate a puzzle with size lower than 3.")
			self.__generateRandom(kwargs["size"])
			self.size = int(kwargs["size"])
		elif ("liste" in kwargs):
			self.state = self.our_copy(kwargs["liste"])
			self.size = len(kwargs["liste"])
		elif ("state" in kwargs):
			self.state = self.our_copy(kwargs["state"].state)
			self.size = kwargs["state"].size
			self.heuristique = kwargs["state"].heuristique
			self.g = kwargs["state"].g + 1
			return
		else:
			raise NPuzzleError("You must specify a 'file' or 'size' argument.")
		self.calcHeuristique()
		self.g = 0
		self.hole_position = self.find_hole_position()
		self.str_state = str(self.state)

	def __del__(self):
		State.current_number -= 1
