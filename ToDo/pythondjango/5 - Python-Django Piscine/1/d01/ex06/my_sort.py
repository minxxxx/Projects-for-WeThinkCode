
# coding: utf-8

# In[58]:


def my_var():
    d = {
    'Hendrix' : '1942',
    'Allman' : '1946',
    'King' : '1925',
    'Clapton' : '1945',
    'Johnson' : '1911',
    'Berry' : '1926',
    'Vaughan' : '1954',
    'Cooder' : '1947',
    'Page' : '1944',
    'Richards' : '1943',
    'Hammett' : '1962',
    'Cobain' : '1967',
    'Garcia' : '1942',
    'Beck' : '1944',
    'Santana' : '1947',
    'Ramone' : '1948',
    'White' : '1975',
    'Frusciante': '1970',
    'Thompson' : '1949',
    'Burton' : '1939',
    }


    sorted_by_year = sorted(d.items(), key=lambda kv: kv[1])

    d2 = {}
    for (val, key) in sorted_by_year:
        d2[key] = []
    for (val, key) in sorted_by_year:    
        d2[key].append(val)

    for i in d2.values():
        print(*sorted(i))
        
if __name__ == '__main__':
    my_var()

