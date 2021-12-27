#! /bin/bash

curl -I $1 2>&- | grep "Location:" | cut -c11-
