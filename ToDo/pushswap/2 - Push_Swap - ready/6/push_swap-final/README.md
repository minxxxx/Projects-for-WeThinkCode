# Push_swap

## Grade		116	/100

### Mandatory	100	/100
### Bonus		16	/25

## Description

The project introduces the concept of ```Sorting``` algorithms such as *Quicksort*, *Bubblesort* or *Mergesort* and others.

![push_swap](https://github.com/mmanley42/ressources/blob/master/push_swap_visu.gif)

The challenge is to produce an algorithm to sort a list of numbers. We have to produce two programs ```push_swap``` and ```checker```. 
The first has the role of sorting the list and displaying the instruction on the ```stdout```.
The second will read from what input is sent to him and check if with those rules the list given is truely sorted, by sending back **OK** or **KO**.

To do so here is the list of instructions that will sort the data in a stack :
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

The programs cannot exit unexpectedly (Segmentation fault, bus error, double free, etc) nor have any leaks. All errors will be handled properly.

## Usage 

Compile the proejct with  ```make```, there are now two programs ```push_swap``` and ```checker``` in the folder. They will both take a list of numbers as arguments.

### push_swap

Different accepted inputs :

```console
./push_swap " 0 5 3 7 4 -5"
```
```console
./push_swap 0 5 325 4485 -5 -98
```
```console
./push_swap 0   "5 3"   +7  "4 -5"
```
This will be push_swaps output :

```console
./push_swap " 0 5 3 7 4 -5"
pb
ra
pb
ra
ra
pb
ra
ss
rra
sa
pa
rb
pa
rrb
pa
```

### checker

Same inputs as push_swap will then wait for the instructions.

```console
./checker " 0 5 3 7 4 -5"
```
*input one instruction per line, then end it with a EOF (ctrl + D)*

output : either **OK** or **KO** depending on the instructions.

### Both

These two programs are ment to be used together here are a couple of examples :

```console
./push_swap 1 25 6 9 33 -6 | ./checker 1 25 6 9 33 -6
```
```console
ARG=` 1 25 6 9 33 -6`; ./push_swap $ARG | ./checker $ARG
```

Here is a small ```Ruby``` script to randomize a defined sized list : 

```console
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
OK
```
