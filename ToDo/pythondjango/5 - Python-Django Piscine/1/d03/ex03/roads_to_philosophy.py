
# coding: utf-8

# In[110]:


import requests
from lxml import html
from bs4 import BeautifulSoup
import re

# word = 'russia'

def filter(tag):
    from bs4 import BeautifulSoup

    return tag is not None  and not tag.has_attr("role") and not tag.name == "abbr" and not tag.name == "img" and tag.name == 'a'

def next_article(word):

    url = 'https://en.wikipedia.org/wiki/' + word
    r = requests.get(url)
    soup = BeautifulSoup(r.content, "html.parser")

    parse_output = soup.find('div',attrs={"id":u"bodyContent"})                        .find('div',attrs={"id":u"mw-content-text"})                        .find('div',attrs={"class":u"mw-parser-output"})

    for i in parse_output.children:
        if i.name == 'p':
            possible_refs = i.find_all(filter)
            for j in possible_refs:
                href = str(j.get('href'))
                if href.startswith("/wiki/")                 and not (href.startswith("#")                         or href.startswith("/Wikipedia:")
                        or href.startswith("/wiki/Help")
                        or href.startswith('/wiki/File')
                        or href.startswith('/wiki/Wikipedia:Citation_needed')
                        or href.startswith('//upload.wikimedia.org/')):
#                     print("href " + href.replace("/wiki/", ""))
                    return href.replace("/wiki/", "")


# In[156]:


def road_to_philo():    
    import sys
    if len(sys.argv) != 2:
        print('Give me only 1 article name from Wikipedia please!')
        sys.exit()
    ref = sys.argv[1]
    list_of_ref = [ref]
    ref = next_article(ref)
    while ref is not None:
#         print(ref)
        list_of_ref.append(ref)
        next_article(ref)
        ref = next_article(ref)

        if ref in list_of_ref:
            print('Infinite loop!')
            sys.exit()
    #     pass
        if ref == 'Philosophy': 
            print('{} steps to the Philosophy starting from {}.'.format(len(list_of_ref), list_of_ref[0]))
            print('Path:\n')
            for i in range(len(list_of_ref)):
                print('{} -> '.format(list_of_ref[i]))
            print('Philosophy')
            sys.exit()

if __name__ == '__main__':
    road_to_philo()

