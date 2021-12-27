#!/usr/bin/python3
# coding : utf8

import sys
import requests
from bs4 import BeautifulSoup

def web_request(req):
	url = 'https://en.wikipedia.org/wiki/' + req
	r = requests.get(url)
	if r.status_code != 200:
		if r.status_code == 404: # page non trouvee
			print('It leads to a dead end !')
		else :
			print('HTTP error ', str(r.status_code))
		exit(1)
	
	soup = BeautifulSoup(r.text, 'html.parser')
	title = str(soup.title.string)
	#print("debug : title = ", title)
	title = title.replace(' - Wikipedia', '')


	content = soup.find(id="mw-content-text")
	p = content.p
	b = p.b
	if not b:
		print('It leads to a dead end !')
		exit(1)
	a = p.find_all('a')
	if not a:
		print('It leads to a dead end !')
		exit(1)

	for elem in a:
		#print("debug : elem ", str(elem))
		if str(elem).find('title') > 0:
			target = elem['title']
			if target:
				if not target.startswith('Help:'):
					return target


def process_request(req):
	roads = [req]
	while (req.lower() != 'philosophy'):
		req = web_request(req)
		if req in roads: # requete deja trouvee
			#print("debug : req = ", req)
			print('It leads to an infinite loop !')
			exit(1)
		roads.append(req)
	for road in roads:
		print(road)
	print(str(len(roads)) + " road(s) from " + roads[0] + " to philosophy!")

def usage():
	print("Usage : python3 roadss_to_philosophy.py chaine_de_recherche")

if __name__ == '__main__':
	if len(sys.argv) == 2:
		process_request(sys.argv[1])
	else :
		usage()