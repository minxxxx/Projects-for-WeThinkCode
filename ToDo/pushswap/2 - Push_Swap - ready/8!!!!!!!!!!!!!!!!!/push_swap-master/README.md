# push_swap
Sorting integers on a stack in a minimum number of moves with a limited set of instructions.
The main algorithm is a mix of quick sort and merge sort.

**Results** (average):
- 100 parameters: 679 moves
- 500 parameters: 5149 moves

The game is composed of 2 stacks named a and b.  
	a contains a random number of either positive or negative numbers without any duplicates  
	b is empty  
The aim is to sort in ascending order numbers into stack a.  
  
**Set of instructions**:
- sa: swap a - swaps the first 2 elements of stack a (does nothing if there is only one or no elements).
- sb: swap b - swaps the first 2 elements of stack b (does nothing if there is only one or no elements).
- ss: sa and sb at the same time.
- pa: push a - takes the first element on top of b and puts it on top of a (does nothing if b is empty).  
- pb: push b - takes the first element on top of a and puts it on top of b (does nothing if a is empty).  
- ra: rotate a - shifts up all elements of stack. The first element becomes the last one.  
- rb: rotate b - shifts up all elements of stack. The first element becomes the last one.  
- rr: ra and rb at the same time.
- rra: reverse rotate a - shifts down all elements of stack a. The last element becomes the first one.
- rrb: reverse rotate b - shifts down all elements of stack b. The last element becomes the first one.
- rrr: rra and rrb at the same time.  
  
**Display** (usage):  
-m: number of moves  
-a: algorithm used  
-s: stacks step by step  
-r: visualizer  
-c: colors  

Tip: to generate a random sequence of numbers, run the program with the ruby command:  
ruby -e "puts (0..99).to_a.shuffle.join(' ')" 
