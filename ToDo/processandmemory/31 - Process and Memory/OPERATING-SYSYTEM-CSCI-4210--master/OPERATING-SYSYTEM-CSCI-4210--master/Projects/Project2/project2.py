######
# OS project 2:
# Rongfeng Lin, linr4
# Enosh Neupane, neupae
# Alseny Sylla, sylla
#####

import sys
import copy
import operator
from memory import Memory

class Process:
	def __init__ (self, processName, numberOfFrames, processArrival, processDeparture):
		self.processName = processName
		self.memoryFrameNumber = int(numberOfFrames)
		self.processArrival = processArrival
		self.processDeparture = processDeparture
		self.location = -1
		self.iteration = 0


	  #compare (help us sort the processes by name)
	def __cmp__(self, other):
		return cmp(self.processName, other.processName)
#---Functions-------------------------------------------------------------------

# This function will take in an opened input file ("inputfile") and will return 
# a list of the processes contained in this file
def parsefile(inputfile):
	processes = list()
	for line in inputfile:
		if line[0] == '#':
			continue
		line = line.strip().split(' ')
		if len(line) == 1 and line[0] == '': continue
		''' take the command lines'''
		nameOfProcess = line[0]
		numberOfFrames = line[1]
		arr_and_run_time = line[2:]
		pn_arr_time_n = [0] * len(arr_and_run_time)
		pn_run_time_n = [0] * len(arr_and_run_time)
		'''loop through the rest of the line and store both the arrival and runntime (departure)'''
		for i in range(len(arr_and_run_time)):
			'''get the pair arrival and run times ( p1_arr_time_1/p1_run_time_1)'''
			pair_arrival_run_time = arr_and_run_time[i]
			#split it and store each one in its corresponding array
			pair_arrival_run_time = pair_arrival_run_time.split('/')
			pn_arr_time_n[i] = int(pair_arrival_run_time[0])
			pn_run_time_n[i] = int(pair_arrival_run_time[0]) + int(pair_arrival_run_time[1])

		temp_process = Process(nameOfProcess, numberOfFrames, pn_arr_time_n, pn_run_time_n)
		processes.append(temp_process)
	return processes




def Next_Fit(nf_Memory, nf_processes):
	#variable to hold the current time in simulation
	time =0
	endTime = 0 #variable to keep track of what time the simulation ends
	defragCounter = 0
	nextFitStartingLocation = 0

	print ("time %dms: Simulator started (Contiguous -- Next-Fit)" %(time+defragCounter))
	#let's collect departures and remove from memory
	while endTime < len(nf_processes):
		departingProcessesList = list()# we will store them in this list
		for process in nf_processes:
			if process.location == -1: continue
			if time in process.processDeparture:
				#if the process is starting at in the interval of the variable time, add it to the list. 
				departingProcessesList.append(process)
		#Now sort the processes by names
		departingProcessesList = sorted(departingProcessesList, key=operator.attrgetter('processName'))

		#Now let's remove the process form the memory
		'''
			if the process the location is -1, then it has been removed
			we will replace the places it occupies in the memory by '.'
			then we will set its location to -1
		'''
		for process in departingProcessesList:
			if process.location != -1:
				for i in range(process.memoryFrameNumber):
					#replace the locations by "."
					nf_Memory.insert(".", process.location+i)
					
				process.location = -1 #make sure it is removed from memory
				process.iteration += 1 
			print ("time %dms: Process %s removed:" %(time+defragCounter, process.processName))
			#print the removal of the process from the memory
			nf_Memory.print_memory()

			if process.iteration == len(process.processArrival):#this process has complety ended
				endTime = endTime + 1

		'''PROCESS IS STARTING'''
		#let's get the arriving processes at first at this particular time
		arrivingProcessesList = list()
		for process in nf_processes:
			if process.iteration == len(process.processArrival): continue
			if time in process.processArrival:
			# You only want to collect the processes arriving at that time
				arrivingProcessesList.append(process)
		#Sort the processes by name
		arrivingProcessesList = sorted(arrivingProcessesList, key=operator.attrgetter('processName'))
		#now let's collect the arriving processes
		for process in arrivingProcessesList:
			print ("time %dms: Process %s arrived (requires %d frames)" %(time+defragCounter, process.processName, process.memoryFrameNumber))

			if nf_Memory.space_available(process)== False: 
				#This means it does not have any space even if we defragment. So we skip it. 
				print ("time %dms: Cannot place process %s -- skipped!" %(time+defragCounter, process.processName))
				process.iteration +=1
				if process.iteration == len(process.processArrival):
					endTime = endTime +1
				continue

			#Let's look for next good location
			temp = -1
			for i in range(256):
				check_index = (i+nextFitStartingLocation)%256
				notAllocatedMemory = 0
				for j in range(check_index, nf_Memory.memorySize()):
					if nf_Memory.getMemory()[j] != nf_Memory.getFreeFrame():
						break
					notAllocatedMemory += 1

				if process.memoryFrameNumber <= notAllocatedMemory:
					temp = check_index #meaning we can fit it
					break

			if temp == -1:
				print ("time %dms: Cannot place process %s -- starting defragmentation" %(time+defragCounter, process.processName))
				#now let's starting defragmentation
				defragmentationResult = nf_Memory.defragmentation(nf_processes)
				defragCounter += defragmentationResult[0] * 1
				print "time {}ms: Defragmentation complete (moved {} frames: {})" \
                    .format(time+defragCounter, defragmentationResult[0], defragmentationResult[1])
				nf_Memory.print_memory()

				temp = nf_Memory.searchFirstFreeMemory()
				#print temp
				#Add Process to Memroy ath the location of temp if it is possible
				if process.location==-1: 
					checkForRoom = True
					if process.memoryFrameNumber +temp <= 256:
	   					for i in range(process.memoryFrameNumber):
							if nf_Memory.getMemory()[temp+i]!=nf_Memory.getFreeFrame():
								checkForRoom = False
            	
	   				if checkForRoom == True:
	   					process.location = temp
						#nf_Memory.print_memory()
						#print "start23223232"
	    				for i in range(process.memoryFrameNumber):
							#nf_Memory.print_memory()
							#print process.processName
							#print i
							nf_Memory.insert(process.processName, temp+i)

	   			print ("time %dms: Placed process %s:" %(time+defragCounter, process.processName))

				nf_Memory.print_memory()
	   			nextFitStartingLocation = temp+ process.memoryFrameNumber

	   		else: #if Room already exists
	   			if process.location==-1: 
					checkForRoom = True
					if process.memoryFrameNumber +temp <= 256:
	   					for i in range(process.memoryFrameNumber):
							if nf_Memory.getMemory()[temp+i]!=nf_Memory.getFreeFrame():
								checkForRoom = False
            				
	   				if checkForRoom == True:
	   					process.location = temp
	    				for i in range(process.memoryFrameNumber):
	       					nf_Memory.insert(process.processName, temp+i)
	   			
	   			print ("time %dms: Placed process %s:" %(time+defragCounter, process.processName))

	   			#print_memory(nf_Memory)
	   			nf_Memory.print_memory()
	   			nextFitStartingLocation = temp+ process.memoryFrameNumber
	   	#when everything is over
	   	if endTime == len(nf_processes):
	   		break
	   	time += 1

	print ("time %dms: Simulator ended (Contiguous -- Next-Fit)" %(time+defragCounter))
	return nf_processes

#------------------------------------------------------------------------------------------------
def Best_Fit(bf_Memory, bf_processes):
	#variable to hold the current time in simulation
	time =0
	endTime = 0 #variable to keep track of what time the simulation ends
	defragCounter = 0
	nextFitStartingLocation = 0

	print ("time %dms: Simulator started (Contiguous -- Best-Fit)" %(time+defragCounter))
	#let's collect departures and remove from memory
	while endTime < len(bf_processes):
		departingProcessesList = list()# we will store them in this list
		for process in bf_processes:
			if process.location == -1: continue
			if time in process.processDeparture:
				#if the process is starting at in the interval of the variable time, add it to the list. 
				departingProcessesList.append(process)
		#Now sort the processes by names
		departingProcessesList = sorted(departingProcessesList, key=operator.attrgetter('processName'))

		#Now let's remove the process form the memory
		'''
			if the process the location is -1, then it has been removed
			we will replace the places it occupies in the memory by '.'
			then we will set its location to -1
		'''
		for process in departingProcessesList:
			if process.location != -1:
				for i in range(process.memoryFrameNumber):
					#replace the locations by "."
					bf_Memory.insert(".", process.location+i)
					
				process.location = -1 #make sure it is removed from memory
				process.iteration += 1 
			print ("time %dms: Process %s removed:" %(time+defragCounter, process.processName))
			#print the removal of the process from the memory
			bf_Memory.print_memory()

			if process.iteration == len(process.processArrival):#this process has complety ended
				endTime = endTime + 1

		'''PROCESS IS STARTING'''
		#let's get the arriving processes at first at this particular time
		arrivingProcessesList = list()
		for process in bf_processes:
			if process.iteration == len(process.processArrival): continue
			if time in process.processArrival:
			# You only want to collect the processes arriving at that time
				arrivingProcessesList.append(process)
		#Sort the processes by name
		arrivingProcessesList = sorted(arrivingProcessesList, key=operator.attrgetter('processName'))
		#now let's collect the arriving processes
		for process in arrivingProcessesList:
			print ("time %dms: Process %s arrived (requires %d frames)" %(time+defragCounter, process.processName, process.memoryFrameNumber))

			if bf_Memory.space_available(process)== False: 
				#This means it does not have any space even if we defragment. So we skip it. 
				print ("time %dms: Cannot place process %s -- skipped!" %(time+defragCounter, process.processName))
				process.iteration +=1
				if process.iteration == len(process.processArrival):
					endTime = endTime +1
				continue

			temp = bf_Memory.searchSmallestFreeMemory(process.memoryFrameNumber)[0]

			if temp == -1:
				print ("time %dms: Cannot place process %s -- starting defragmentation" %(time+defragCounter, process.processName))
				#now let's starting defragmentation
				defragmentationResult = bf_Memory.defragmentation(bf_processes)
				defragCounter += defragmentationResult[0] * 1
				print "time {}ms: Defragmentation complete (moved {} frames: {})" \
                    .format(time+defragCounter, defragmentationResult[0], defragmentationResult[1])
				bf_Memory.print_memory()

				temp = bf_Memory.searchFirstFreeMemory()

				#Add Process to Memroy ath the location of temp if it is possible
				if process.location==-1: 
					checkForRoom = True
					if process.memoryFrameNumber +temp <= 256:
	   					for i in range(process.memoryFrameNumber):
							if bf_Memory.getMemory()[temp+i]!=bf_Memory.getFreeFrame():
								checkForRoom = False
            				
	   				if checkForRoom == True:
	   					process.location = temp
	    				for i in range(process.memoryFrameNumber):
	    					bf_Memory.insert(process.processName, temp+i)
	       					
	   			
	   			print ("time %dms: Placed process %s:" %(time+defragCounter, process.processName))

	   			bf_Memory.print_memory()
	   			nextFitStartingLocation = temp+ process.memoryFrameNumber

	   		else: #if Room already exists
	   			if process.location==-1: 
					checkForRoom = True
					if process.memoryFrameNumber +temp <= 256:
	   					for i in range(process.memoryFrameNumber):
							if bf_Memory.getMemory()[temp+i]!=bf_Memory.getFreeFrame():
								checkForRoom = False
            				
	   				if checkForRoom == True:
	   					process.location = temp
	    				for i in range(process.memoryFrameNumber):
	       					bf_Memory.insert(process.processName, temp+i)
	   			
	   			print ("time %dms: Placed process %s:" %(time+defragCounter, process.processName))

	   			#print_memory(nf_Memory)
	   			bf_Memory.print_memory()
	   			nextFitStartingLocation = temp+ process.memoryFrameNumber
	   	#when everything is over
	   	if endTime == len(bf_processes):
	   		break
	   	time += 1

	print ("time %dms: Simulator ended (Contiguous -- Best-Fit)" %(time+defragCounter))
	return bf_processes
#---------------------------------------------------------------------------------------------------

	
def Worst_Fit(bf_Memory, bf_processes):
#variable to hold the current time in simulation
	time =0
	endTime = 0 #variable to keep track of what time the simulation ends
	defragCounter = 0
	nextFitStartingLocation = 0

	print ("time %dms: Simulator started (Contiguous -- Worst-Fit)" %(time+defragCounter))
	#let's collect departures and remove from memory
	while endTime < len(bf_processes):
		departingProcessesList = list()# we will store them in this list
		for process in bf_processes:
			if process.location == -1: continue
			if time in process.processDeparture:
				#if the process is starting at in the interval of the variable time, add it to the list. 
				departingProcessesList.append(process)
		#Now sort the processes by names
		departingProcessesList = sorted(departingProcessesList, key=operator.attrgetter('processName'))

		#Now let's remove the process form the memory
		'''
			if the process the location is -1, then it has been removed
			we will replace the places it occupies in the memory by '.'
			then we will set its location to -1
		'''
		for process in departingProcessesList:
			if process.location != -1:
				for i in range(process.memoryFrameNumber):
					#replace the locations by "."
					bf_Memory.insert(".", process.location+i)
					
				process.location = -1 #make sure it is removed from memory
				process.iteration += 1 
			print ("time %dms: Process %s removed:" %(time+defragCounter, process.processName))
			#print the removal of the process from the memory
			bf_Memory.print_memory()

			if process.iteration == len(process.processArrival):#this process has complety ended
				endTime = endTime + 1

		'''PROCESS IS STARTING'''
		#let's get the arriving processes at first at this particular time
		arrivingProcessesList = list()
		for process in bf_processes:
			if process.iteration == len(process.processArrival): continue
			if time in process.processArrival:
			# You only want to collect the processes arriving at that time
				arrivingProcessesList.append(process)
		#Sort the processes by name
		arrivingProcessesList = sorted(arrivingProcessesList, key=operator.attrgetter('processName'))
		#now let's collect the arriving processes
		for process in arrivingProcessesList:
			print ("time %dms: Process %s arrived (requires %d frames)" %(time+defragCounter, process.processName, process.memoryFrameNumber))

			if bf_Memory.space_available(process)== False: 
				#This means it does not have any space even if we defragment. So we skip it. 
				print ("time %dms: Cannot place process %s -- skipped!" %(time+defragCounter, process.processName))
				process.iteration +=1
				if process.iteration == len(process.processArrival):
					endTime = endTime +1
				continue

			temp = bf_Memory.searchLargestFreeMemory(process.memoryFrameNumber)[0]

			if temp == -1:
				print ("time %dms: Cannot place process %s -- starting defragmentation" %(time+defragCounter, process.processName))
				#now let's starting defragmentation
				defragmentationResult = bf_Memory.defragmentation(bf_processes)
				defragCounter += defragmentationResult[0] * 1
				print "time {}ms: Defragmentation complete (moved {} frames: {})" \
                    .format(time+defragCounter, defragmentationResult[0], defragmentationResult[1])
				bf_Memory.print_memory()

				temp = bf_Memory.searchFirstFreeMemory()

				#Add Process to Memroy ath the location of temp if it is possible
				if process.location==-1: 
					checkForRoom = True
					if process.memoryFrameNumber +temp <= 256:
	   					for i in range(process.memoryFrameNumber):
							if bf_Memory.getMemory()[temp+i]!=bf_Memory.getFreeFrame():
								checkForRoom = False
            				
	   				if checkForRoom == True:
	   					process.location = temp
	    				for i in range(process.memoryFrameNumber):
	    					bf_Memory.insert(process.processName, temp+i)
	       					
	   			
	   			print ("time %dms: Placed process %s:" %(time+defragCounter, process.processName))

	   			bf_Memory.print_memory()
	   			nextFitStartingLocation = temp+ process.memoryFrameNumber

	   		else: #if Room already exists
	   			if process.location==-1: 
					checkForRoom = True
					if process.memoryFrameNumber +temp <= 256:
	   					for i in range(process.memoryFrameNumber):
							if bf_Memory.getMemory()[temp+i]!=bf_Memory.getFreeFrame():
								checkForRoom = False
            				
	   				if checkForRoom == True:
	   					process.location = temp
	    				for i in range(process.memoryFrameNumber):
	       					bf_Memory.insert(process.processName, temp+i)
	   			
	   			print ("time %dms: Placed process %s:" %(time+defragCounter, process.processName))

	   			#print_memory(nf_Memory)
	   			bf_Memory.print_memory()
	   			nextFitStartingLocation = temp+ process.memoryFrameNumber
	   	#when everything is over
	   	if endTime == len(bf_processes):
	   		break
	   	time += 1

	print ("time %dms: Simulator ended (Contiguous -- Worst-Fit)" %(time+defragCounter))
	return bf_processes

def Non_Contiguous(nonContiguousMemory, nonContiguous_processes):
	time =0
	endTime = 0

	print ("time %dms: Simulator started (Non-contiguous)"%time)

	while(endTime < len(nonContiguous_processes)):
		departingProcessesList = list()# we will store them in this list
		for process in nonContiguous_processes:
			if process.location == -1: continue
			if time in process.processDeparture:
				#if the process is starting at in the interval of the variable time, add it to the list. 
				departingProcessesList.append(process)
		#Now sort the processes by names
		departingProcessesList = sorted(departingProcessesList, key=operator.attrgetter('processName'))

		for process in departingProcessesList:


			for i in range(0, nonContiguousMemory.memorySize()):
				if nonContiguousMemory.getMemory()[i] == process.processName:
					nonContiguousMemory.insert(nonContiguousMemory.getFreeFrame(), i)
			process.location = -1
			process.iteration +=1

			remove_process = nonContiguousMemory.pageRemoveProcess(process.processName)


			print ("time {}ms: Process {} removed:"\
			      .format(time, process.processName))
			nonContiguousMemory.print_memory()
			nonContiguousMemory.printTable()

			if process.iteration == len(process.processArrival):
				endTime += 1

		arrivingProcessesList = list()
		for process in nonContiguous_processes:
			if process.iteration == len(process.processArrival): continue
			if time in process.processArrival:
			# You only want to collect the processes arriving at that time
				arrivingProcessesList.append(process)
		#Sort the processes by name
		arrivingProcessesList = sorted(arrivingProcessesList, key=operator.attrgetter('processName'))

		for process in arrivingProcessesList:
			print ("time {}ms: Process {} arrived (requires {} frames)"\
			      .format(time, process.processName, process.memoryFrameNumber))

			if nonContiguousMemory.space_available(process)== False: 
				print ("time %dms: Cannot place process %s -- skipped!" %(time, process.processName))
				process.iteration +=1
				if process.iteration == len(process.processArrival):
					endTime = endTime +1
				continue 

			numAllocatedFrame = 0
			memorysearh_index = 0 
			while numAllocatedFrame < process.memoryFrameNumber:
				
				framesLeft = process.memoryFrameNumber - numAllocatedFrame 
				#print process.memoryFrameNumber # 46
				#print numAllocatedFrame  #0
				temp=-1
				spaceAvailable = 0
				for i in range(nonContiguousMemory.getTotal()):
					checker = (i+memorysearh_index)%nonContiguousMemory.getTotal()
					temp_unlloc =0
					for i in range (checker, nonContiguousMemory.memorySize()):
						#print "char: " + nonContiguousMemory.getMemory()[i]
						#print temp_unlloc
						if nonContiguousMemory.getMemory()[i] != nonContiguousMemory.getFreeFrame():
							break
						temp_unlloc +=1

					spaceAvailable = temp_unlloc
					if 1<= spaceAvailable:
						temp = checker
						break
				frameToAllocate = min(spaceAvailable, framesLeft)
				for index in range(temp, temp+frameToAllocate):
					nonContiguousMemory.insert(process.processName, index)
					#nonContiguousMemory.print_memory()

				tableUpdate= []
				temp_numAllocatedFrame = numAllocatedFrame
				temp_temp = temp
				for i in range(0, frameToAllocate):
					tableUpdate.append((temp_numAllocatedFrame, temp_temp))
					temp_numAllocatedFrame +=1
					temp_temp +=1
				#print "before " + str(numAllocatedFrame)
				x = []

				if process.processName not in nonContiguousMemory.getTable().keys():
					nonContiguousMemory.tableInsert(process.processName, x)

				l = nonContiguousMemory.getTableValue(process.processName)+tableUpdate
				
				nonContiguousMemory.tableInsert(process.processName,l )

				#print(nonContiguousMemory.getTableValue(process.processName))

				#print(l)

				memorysearh_index = temp + spaceAvailable
				numAllocatedFrame += frameToAllocate
				#print "after " + str(numAllocatedFrame)

			process.location = 0
			print ("time {}ms: Placed process {}:" \
			       .format(time, process.processName))
			nonContiguousMemory.print_memory()
			nonContiguousMemory.printTable()

		if endTime == len(nonContiguous_processes):
			break
		time += 1
	sys.stdout.write("time {}ms: Simulator ended (Non-contiguous)".format(time))
				


if __name__ == '__main__':
	# Checking for correct number of command line arguments
	total = 256
	rows = 8
	if len(sys.argv) != 2:
		sys.stderr.write("ERROR: Invalid arguments\nUSAGE: python project2.py <input-file> <input-file-vm>\n")
		sys.exit()

		# Opening file for parsing 
	inputfile = open(sys.argv[1], 'r')

	#parsing file
	processes = parsefile(inputfile)

	inputfile.close()

	
	nf_processes = copy.deepcopy(processes)
	bf_processes= copy.deepcopy(processes)
	wf_processes = copy.deepcopy(processes)

	nonContiguous_processes = copy.deepcopy(processes)

	sampleMemory = Memory(total, rows)
	nonContiguousMemory= Memory(total, rows)
	
	

	#Placement Algorithm
	
	Next_Fit(sampleMemory, nf_processes)
	print 
	Best_Fit(sampleMemory, bf_processes)
	print
	Worst_Fit(sampleMemory, wf_processes)
	print
	Non_Contiguous(nonContiguousMemory, nonContiguous_processes)
	print

