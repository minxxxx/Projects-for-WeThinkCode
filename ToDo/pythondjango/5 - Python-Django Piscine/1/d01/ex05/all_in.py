
# coding: utf-8

# In[105]:


from sys import argv

def my_var():
    states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
        }
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
        }

    # s = "New jersey, Tren ton, NewJersey, Trenton, toto, , sAlem"
    # s.split(',')


    # In[100]:


    l = []
    for w in argv[1].split(','):
        l.append(w.strip().title())


    # In[101]:


    def check_state(x):
        if(x == ''): return False
        else:
            if(x in states):
                if(states[x] in capital_cities):
                    print(str(capital_cities[states[x]]) + ' is the capital of ' + x)
                    return False
            else:
    #             print(x + ' is neither a capital city nor a state')
                return True


    # In[102]:


    def check_capital(x):
        if(x == ''): return False
        else:
            for (acr, cap) in capital_cities.items():
                if(cap == x):
                    for (cap2, acr2) in states.items():
                        if(acr == acr2):
                            print(x + ' is the capital of ' + cap2)
                            return False
        return True


    # In[103]:


    for i in l:
        if(check_state(i) and check_capital(i)): 
            print(i + ' is neither a capital city nor a state')
            
if __name__ == '__main__':
    my_var()

