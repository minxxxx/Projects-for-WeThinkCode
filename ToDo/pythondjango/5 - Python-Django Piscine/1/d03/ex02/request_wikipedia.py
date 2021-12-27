
# coding: utf-8

# In[98]:


def my_var():
    import requests, json, sys
    from dewiki import parser

    # word = "Ronaldo_(Brazilian_footballer)"
    # word = 'Russia'
#     word = 'Pain au chocolat'

    if(len(sys.argv) == 1):
        print('Dude, you gave me an empty string!\nType something!')
        sys.exit()
    

    req = requests.get("https://en.wikipedia.org/w/api.php?action=query&titles={}&prop=revisions&rvprop=content&format=json".format(sys.argv[1]))




    if req.status_code != 200:
        print('An error occured!')
        sys.exit()

    json_text = json.loads(req.text)

    almost_text = json_text['query']['pages']

    for i in almost_text.values():
        if 'revisions' in i:
#             print('We have some information about it!\n')
            for j in almost_text.values():
                row_info = j['revisions'][0]['*']
        else:
            print('No info about this word!')
            sys.exit()


    text = parser.Parser().parse_string(row_info)
    filename = '{}.wiki'.format(sys.argv[1].replace(' ', '_'))
    with open(filename, 'w') as f:
        f.write(text)

if __name__ == '__main__':
    my_var()

