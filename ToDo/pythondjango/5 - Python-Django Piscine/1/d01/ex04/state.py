
# coding: utf-8

# In[ ]:


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
        for acr, cap in capital_cities.items():
#             print(cap, argv[1])
            if(cap == argv[1]):
#                 print('Good')
                for cap2, acr2 in states.items(): 
#                     print(cap, cap2)
                    if(acr == acr2):
                        print(cap2)
                        return
                    else: 
                        print('Unknown capital city.')
                        return
            else: 
                print('Unknown capital city.')
                return
    
        
if __name__ == '__main__':
    my_var()

