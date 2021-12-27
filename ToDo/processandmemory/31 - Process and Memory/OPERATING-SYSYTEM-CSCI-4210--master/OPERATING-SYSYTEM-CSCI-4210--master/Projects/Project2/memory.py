######
# OS project 2:
# Rongfeng Lin, linr4
# Enosh Neupane, neupae
# Alseny Sylla, sylla
#####

import sys

class Memory:
	def __init__(self, total, row):
		self.total = total
		self.row = row
		self.memory = []
		self.freeFrame = '.'
		self.create_memory()
		# if(createPage== True):
		self.table = dict()
		self.tableLinesValues = 10

	def getTable(self):
		return self.table

	def pageRemoveProcess(self, process_name):
		return self.table.pop(process_name, None)

	

	def tableInsert(self, process_name, type):
		# if process_name not in self.table.keys():
			self.table[process_name] = type

	def getTableValue(self, process_name):
		return self.table[process_name]
		
	def printTable(self):
		print ("PAGE TABLE [page,frame]:")
		for key in sorted(self.table.keys()):
			print str(key) + ":",
			for i, (page_num, frame_num) in enumerate(self.table[key]):
				if i!=0 and not i % self.tableLinesValues:
					print
				print "[{},{}]".format(page_num, frame_num),
			print

	def create_memory(self):
		self.memory = [self.freeFrame]*self.total

	def memorySize(self):
		return len(self.memory)

	def getMemory(self):
		return self.memory

	def getTotal(self):
		return self.total

	def getFreeFrame(self):
		return self.freeFrame

	def insert(self, value, index):
		self.memory[index] = value

	def print_memory(self):
		mod = self.total/self.row
		print("================================")
		for i in range(0,self.total):
			if((i+1)%mod==0):
				sys.stdout.write(self.memory[i]+'\n')
			else:
				sys.stdout.write(self.memory[i])
		print("================================")


	def space_available(self, process):
		space = 0
		for b in range(self.total):
			if self.memory[b] == self.freeFrame:
				space += 1
		if(process.memoryFrameNumber > space):
			return False
		else:
			return True

	def searchFirstFreeMemory(self, idx=0):
		limit = len(self.memory)
		for i in range(idx, limit):
			if self.memory[i] == self.freeFrame:
				return i
		return -1

	def defragmentation(self, processes):
		total_movement = 0
		clearMemoryIndex = None
		changeProcessLocation = ""
		while 1:
			clearMemoryIndex = self.searchFirstFreeMemory(0)
			mininum_location = float("inf")
			proc = None
			for process in processes:
				if process.location == -1: continue
				if mininum_location > process.location > clearMemoryIndex:
					mininum_location = process.location
					proc = process
			
			if proc is None: #no process after the clear_memory_location ==> no processes left to move
				break
			processMemoryIndex = proc.location #location in memory of that process
			for proc_elem in range(0, proc.memoryFrameNumber):
				self.memory[clearMemoryIndex] = self.memory[processMemoryIndex]
				self.memory[processMemoryIndex] = '.'
				clearMemoryIndex += 1
				processMemoryIndex += 1
			proc.location = clearMemoryIndex - proc.memoryFrameNumber
			total_movement += proc.memoryFrameNumber
			changeProcessLocation += proc.processName + ", "
		return total_movement, changeProcessLocation.strip(", ")

	def searchSmallestFreeMemory(self, minimum_length=1):

		compareValue = float("inf")

		curr_minimum_index = -1

		lookup = 0

		while 1:
			free_minimum_index = self.searchFirstFreeMemory(lookup)
			if free_minimum_index == -1:
				break
			notAllocated=0
			for i in range(lookup, len(self.memory)):
				if self.memory[i] != self.freeFrame:
					break
				notAllocated += 1
			if(minimum_length <= notAllocated < compareValue):
				curr_minimum_index = free_minimum_index
				compareValue = notAllocated
			lookup = free_minimum_index + notAllocated
		return curr_minimum_index, compareValue


	def searchLargestFreeMemory(self, minimum_length=1):

		compareValue = float("-inf")

		curr_minimum_index = -1

		lookup = 0

		while 1:
			free_minimum_index = self.searchFirstFreeMemory(lookup)
			if free_minimum_index == -1:
				break
			notAllocated=0
			for i in range(lookup, len(self.memory)):
				if self.memory[i] != self.freeFrame:
					break
				notAllocated += 1

			if(notAllocated > compareValue and notAllocated >= minimum_length):

				curr_minimum_index = free_minimum_index
				compareValue = notAllocated

			lookup = free_minimum_index + notAllocated

		return curr_minimum_index, compareValue