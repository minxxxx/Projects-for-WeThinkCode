all: mu-mips assembler
mu-mips: mu-mips.c
	gcc -Wall -g -O2 $^ -o $@
assembler: assembler.c
	gcc -Wall -g -O2 $^ -o $@

.PHONY: clean
clean:
	rm -rf *.o *~ mu-mips
	rm -rf *.o *~ assembler
