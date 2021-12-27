import requests, json, sys
from dewiki import parser

def ft_parse_wiki(str_to_search):
	r = requests.get("https://en.wikipedia.org/w/api.php?action=query&titles="+str_to_search+
		"&prop=revisions&redirects=&rvprop=content&format=json&formatversion=2&utf8=")
	if r.status_code != 200:
		raise Exception("Error occured!")
	# data = r.json()
	data = json.loads(r.text)
	try:
		if 'missing' in data['query']['pages'][0]:
			raise Exception("No such page or information about!")
		name = data['query']['pages'][0]['title']
		res = data['query']['pages'][0]['revisions'][0]['content']
		with open("_".join(name.split()) + ".wiki", 'w') as file:
			file.write(parser.Parser().parse_string(res) + "\n")
	except Exception as e:
		print (e)

if __name__ == '__main__':
	try:
		if len(sys.argv) != 2:
			raise Exception("Error! One argument need to be passed")
		ft_parse_wiki(sys.argv[1])
	except Exception as e:
		print (e)