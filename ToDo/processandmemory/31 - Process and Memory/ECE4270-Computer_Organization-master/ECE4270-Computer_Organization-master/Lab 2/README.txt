I added the assembler to the Makefile, so:

1) run: make
	Ignore warnings

2) run: ./assembler <name of mips file>.io

	This creates a file that has the machine code in it named 	"assembled_<name of mips file>.io"

3) run: ./mu-mips assembled_<name of mips file>.io

So for the bubble sort run:

make
./assembler bubble_sort.in
./mu-mips assembled_bubble_sort.in

Then within the simulator do:

sim 
mdump 0x10010000 0x10010034

To run the program and view the sorted array in memory
