import antigravity, sys

#for test :
#python3 geohashing.py 37.421542 -122.085589 2005-05-26-10458.68

if __name__ == '__main__':
	if len(sys.argv) != 4:
		print ("Usage: <lat> <long> <YYYY-MM-DD-(daytime in seconds, for ex: 10458.68)>")
	else:	
		antigravity.geohash(float(sys.argv[1]), float(sys.argv[2]), sys.argv[3].encode())