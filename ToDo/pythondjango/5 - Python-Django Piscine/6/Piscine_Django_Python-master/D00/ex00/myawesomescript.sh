#!/bin/sh
curl -I -s  $1 | grep Location | cut -d " "  -f 2
