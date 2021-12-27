Executable, try to open argv[1] and read it, ofc with the token directly it wont work! by doing nm, we see that it use strstr() as it look for a specific string, probably on argv[1] for 'token' ? We try to make a symbolic link toward token -> ln -s <absoulute_path_token>/token /tmp/titi; ./level08 /tmp/titi; that's not a flag !
su flag08 -> quif5eloekouj29ke0vouxean; getflag;
flag = 25749xKZ8L7DkSCwJkT9dyv6f
