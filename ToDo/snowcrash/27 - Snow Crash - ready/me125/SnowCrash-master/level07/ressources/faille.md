./level07 == level07
En faisant un hexdump -C on voit un getenv et une variable LOGNAME
env == LOGNAME=level7
donc export LOGNAME=\`getflag\` pour qu'elle soit interpreter comme une cmd