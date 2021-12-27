No ressources provided for this level. No Indication at all.
We must use gdb to disasemble `/bin/getflag` and dig in.
By disasembling we can see a recurrent schema (x15), just like the number of the flag !
Ofc soft use ptrace which is blocking us, by jumping at the correct address and bypass ptrace fail, we can jump at the last flag and get the value from it
jump * <address>
x/s $eax -> print value (str for s) of $eax register
get ur flag :)

