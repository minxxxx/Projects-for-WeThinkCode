#!/bin/sh
touch /tmp/droits
      while true; do
              ln -sf /tmp/droits /tmp/lien  &
              /home/user/level10/level10 /tmp/lien 127.0.0.1 &
              ln -sf /home/user/level10/token /tmp/lien &
      done
