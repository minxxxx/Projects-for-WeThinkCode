# 42-push_swap
Because swap_push isn't as natural

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

## Instruction set
For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

## Compiling
Run `make`.

## Running
```
./push_swap 1 2 3 4
```
