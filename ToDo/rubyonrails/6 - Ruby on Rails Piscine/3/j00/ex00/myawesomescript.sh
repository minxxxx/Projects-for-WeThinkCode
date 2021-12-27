#!/bin/sh
curl -s -I $1 | grep -i "LOCATION" | cut -d ' ' -f2 | cut -d $'\r' -f1
