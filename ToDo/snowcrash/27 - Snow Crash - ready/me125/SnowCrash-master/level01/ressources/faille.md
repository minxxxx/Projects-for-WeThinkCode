Le fichier /etc/passwd contient une liste de l'ensemble des users (levelXX ...) on voit que le format du level01 est different des autres. On essaye donc de le cracker avec john the ripper.

cd john :

cd src 
make
make clean generic
cd ../run
./john --show ../../sc_passwd

result :

flag01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash

1 password hash cracked, 0 left
