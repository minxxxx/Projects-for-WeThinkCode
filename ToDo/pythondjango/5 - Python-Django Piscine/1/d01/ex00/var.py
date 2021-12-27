
# coding: utf-8

# In[9]:


# 42 est de type <class 'int'>
# 42 est de type <class 'str'>
# quarante-deux est de type <class 'str'>
# 42.0 est de type <class 'float'>
# True est de type <class 'bool'>
# [42] est de type <class 'list'>
# {42: 42} est de type <class 'dict'>
# (42,) est de type <class 'tuple'>
# set() est de type <class 'set'>

l = [42, '42', 'quarante-deux', 42.0, True, [42], {42:42}, (42,), set()]

def my_var():
    for i in l:
        print(str(i) + ' est de type ' + str(type(i)))
    
if __name__ == '__main__':
    my_var()

