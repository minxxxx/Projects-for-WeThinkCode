
# coding: utf-8

# In[28]:


def my_var():
    f = open('numbers.txt', 'r')

    for i in f:
        num = i.split(',')
    for i in range(len(num)+1):
        print(i)
    f.close()

if __name__ == '__main__':
    my_var()

