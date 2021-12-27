
# coding: utf-8

# In[5]:


import sys, antigravity


# In[10]:


def my_var():
    if(len(sys.argv) == 4):
        return antigravity.geohash(float(sys.argv[1]), float(sys.argv[2]), sys.argv[3].encode())
    else:
        print('Not enough data! Should be 3!\n')
        print('Give me your coordinates, date and time in the following format: \n37.421542 -122.085589 2005-05-26-10458.68')
        sys.exit()


# In[11]:


if __name__ == '__main__':
    my_var()

