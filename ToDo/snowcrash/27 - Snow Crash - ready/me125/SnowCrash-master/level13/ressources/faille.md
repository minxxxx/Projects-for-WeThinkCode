Il faut utiliser LD_PRELOAD, si il est défini dans l env, LD_PRELOAD sera chargé avant toute les autres bibliothèque. On va donc remplacer la fonction getuid par une fonction maison pour que celle-ci nous renvoi l uid dont nous avons besoin.

On créer une copie du binaire level 13 : cp level13 /tmp/level13bis.
On créer notre propre getuid : 


#include <unistd.h>

uid_t getuid()
{
	return (4242);
}

On créer maintenant un .so qui nous serviras a use notre getuid avant celui du system grace a LD_PRELOAD : gcc -fPIC -shared -o lib.so getuid.c
Il nous reste plus qu a executer la copie de notre binaire : flag : 2A31L79asukciNyi8uppkEuSx