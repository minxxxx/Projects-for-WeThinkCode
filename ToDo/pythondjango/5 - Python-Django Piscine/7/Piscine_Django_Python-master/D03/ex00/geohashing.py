#!/usr/bin/python3
# coding : utf8

import sys
import antigravity

def geohashing(latitude, longitude, date, indice_dow):
	""" 
		Pour utiliser geohash, voici un extrait de la doc :
	    geohash(latitude, longitude, datedow)
        Compute geohash() using the Munroe algorithm.

        >>> geohash(37.421542, -122.085589, b'2005-05-26-10458.68')
        37.857713 -122.544543
	"""
	date_dow = date + "-" + str(indice_dow)
	antigravity.geohash(latitude, longitude, date_dow.encode('ascii'))

def usage():
	print("Usage : geohashing.py latitude longitude date indice_dow")
	print("Exemple : geohashing.py 37.421542 -122.085589 2005-05-26 10458.68")
	exit(1)

if __name__ == '__main__':
	if len(sys.argv) == 5:
		try:
			lat = float(sys.argv[1])
			lon = float(sys.argv[2])
			indice_dow = float(sys.argv[4])
		except ValueError :
			print("latitude,longitude et indice_dow doivent être de type float")
			usage()
		geohashing(lat, lon, sys.argv[3], indice_dow)
	else:
		usage()
		
