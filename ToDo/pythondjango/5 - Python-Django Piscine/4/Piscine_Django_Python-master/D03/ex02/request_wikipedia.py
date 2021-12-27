#!/usr/bin/python3
# coding : utf8

import sys
import requests
import json
import dewiki

def write_in_file(req, txt):
	filename = req.replace(" ", "_") + ".wiki"
	f = open(filename, "w")
	f.write(txt)
	f.close()

def process_request(req):
	url = 'https://fr.wikipedia.org/w/api.php'
	payload = {'action':'query', 'titles':req, 'prop':'revisions','rvprop':'content','format':'json'}
	r = requests.get(url,params=payload)
	#print("debug url = ", r.url)
	if r.status_code != 200:
		print("Erreur HTTP, code ", str(r.status_code))
		exit(1)
	res = r.json()
	#print("debug : res=", res)
	if res.get('query'):
		#print('debug : query trouve')
		query = res['query']
		if query.get('pages'):
			pages = query['pages']
			#print('debug : pages trouve')
			txt = ""
			for pageid in pages:
				page = pages[pageid]
				if page.get('revisions'):
					revisions = page['revisions']
					#print('debug : revisions trouve ',revisions)
					if revisions[0].get('*'):
						#print('debug : contentu trouve ',revisions[0]['*'] )
						txt += revisions[0]['*'] + "\n" 
				
					txt = dewiki.from_string(txt)
			write_in_file(req, txt)

def usage():
	print("Usage : python3 request_wikipedia.py chaine_de_recherche")

if __name__ == '__main__':
	if len(sys.argv) == 2:
		process_request(sys.argv[1])
	else :
		usage()