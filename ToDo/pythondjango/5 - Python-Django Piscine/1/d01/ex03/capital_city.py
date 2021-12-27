
# coding: utf-8

# In[18]:


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

    

    if(len(argv) != 2): return
    else:
        if(argv[1] in states):
            if(states[argv[1]] in capital_cities):
                print(capital_cities[states[argv[1]]])
        else:
            print('Unknown state.')
    
        
if __name__ == '__main__':
    my_var()

