import srcs.globals
from queue import PriorityQueue
from queue import Queue
from srcs.State import State

def	initialize_map(end_state):
	srcs.globals.g_hash_end_state = [1 for i in range (end_state.size * end_state.size)]
	for i in range(end_state.size):
		for j in range(end_state.size):
			srcs.globals.g_hash_end_state[end_state.state[i][j]] = (i, j)

def countain_pq(liste, to_check, hash_table):
	try:
		if (to_check.str_state in hash_table):
			return liste.queue.index((to_check.heuristique + to_check.g, to_check))
		return (False)
	except ValueError:
		return (False)

def solve(initial_state, end_state):
	initialize_map(end_state)
	initial_state.calcHeuristique()
	initial_state.predecesseur = False
	end_state.calcHeuristique()
	openset = PriorityQueue()
	openset.put_nowait((initial_state.heuristique + initial_state.g, initial_state))
	closedset = {}

	present_in_openset = {}
	present_in_openset[initial_state.str_state] = 1

	total_number_selected_in_openset = 1

	while (not openset.empty()):
		current_heur, current = openset.get_nowait()

		if (current.state == end_state.state):
			print ("Total number of states ever selected in the \"opened\" set: " + str(total_number_selected_in_openset))
			print ("Maximum number of states ever represented in memory at the same time during the search: " + str(State.max_numbers))
			print ("Number of moves required to transition from the initial state to the final state: " + str(current.g) + "\n")
			x = ""
			while current != False:
				if (x == ""):
					x = str(current) + x
				else:
					x = str(current) + "\n" + x
				current = current.predecesseur
			print (x, end="")
			return True
		closedset[str(current.state)] = 1
		neighbors = current.getNeighbors()
		if neighbors:
			for neighbor in neighbors:
				if not neighbor.str_state in closedset:
					neighbor.predecesseur = current
					tmp = countain_pq(openset, neighbor, present_in_openset)
					if (tmp == False):
						openset.put_nowait((neighbor.heuristique + neighbor.g, neighbor))
						present_in_openset[neighbor.str_state] = 1
						total_number_selected_in_openset += 1
					else:
						if (openset.queue[tmp][1].g > neighbor.g):
							openset.queue[tmp][1].g = neighbor.g
							openset.queue[tmp][1].predecesseur = neighbor.predecesseur
	print ("This puzzle can't be solved.")
	return True
