#!/usr/bin/env python3

import argparse
import sys

import srcs.globals
from srcs.State import State
from srcs.algo import *
from srcs.NPuzzleError import NPuzzleError
import profile

def getEndState(size):
	liste = [[-1 for j in range(size)] for i in range(size)]
	ligne = 0
	colomne = -1
	direction = 0 # 0 = droite, 1 = bas, 2 = gauche, 3 = haut
	num = 1
	while (True):
		if direction == 0:
			colomne += 1
		elif direction == 1:
			ligne += 1
		elif direction == 2:
			colomne -= 1
		else:
			ligne -= 1

		if (colomne == size - 1 or liste[ligne][colomne + 1] != -1) and direction == 0:
			direction = 1
		elif (ligne == size - 1 or liste[ligne + 1][colomne] != -1) and direction == 1:
			direction = 2
		elif (colomne == 0 or liste[ligne][colomne - 1] != -1) and direction == 2:
			direction = 3
		elif (ligne == 0 or liste[ligne - 1][colomne] != -1 and direction) == 3:
			direction = 0
		liste[ligne][colomne] = num % (size * size)
		if (num == size * size):
			return (State(liste=liste))
		num += 1

def func():
	parser = argparse.ArgumentParser()
	group = parser.add_mutually_exclusive_group()
	group.add_argument("-f", "--file", help="Specify an initial state of the puzzle.")
	group.add_argument("-s", "--size", type=int, help="Specify the size of a puzzle to generate.")
	parser.add_argument("-d", "--heuristic", type=int, help="Heuristic: 0 => Manhattan Distance, 1 => Misplaced Tiles, 2 => Linear Conflict")
	args = parser.parse_args()

	if args.file is None and args.size is None:
		print (sys.argv[0] + ": You must specify a puzzle acquirement method.")
		sys.exit(1)
	if (args.heuristic is None or args.heuristic < 0 or args.heuristic > 3):
		print ("No valid heuristic specified. Choosing Manhattan Distance as default Heuristic.")
		args.heuristic = 0

	State.heuristic_used = args.heuristic
	try:
		if args.file:
			initial_state = State(file=args.file)
		else:
			print ("The puzzle will be randomly generated")
			initial_state = State(size=args.size)
	except ValueError as e:
		print (str(e))
		sys.exit(2)
	except NPuzzleError as e:
		print (str(e))
		sys.exit(3)
	except IOError as e:
		print("An error occured : " + str(e))
		sys.exit(4)
	end_state = getEndState(initial_state.size)
	if (initial_state.isSolvable(end_state) == False):
		print("This puzzle can't be solved")
	else:
		solve(initial_state, end_state)

if __name__ == '__main__':
	# profile.run("func()")
	func()
