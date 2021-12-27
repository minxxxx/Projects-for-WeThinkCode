 #!/bin/sh
 touch /tmp/gabe
   while true; do
        ln -sf /tmp/gabe /tmp/copyToken  &
        /home/user/level10/level10 /tmp/copyToken 127.0.0.1 &
        ln -sf /home/user/level10/token /tmp/copyToken &
   done