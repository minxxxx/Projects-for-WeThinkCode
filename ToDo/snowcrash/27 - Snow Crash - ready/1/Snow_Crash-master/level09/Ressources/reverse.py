import sys

for i, val in enumerate(sys.argv[1]):
     sys.stdout.write(chr(ord(val)-i))
     sys.stdout.flush()
print