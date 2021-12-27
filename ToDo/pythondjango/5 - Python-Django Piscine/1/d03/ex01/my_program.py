
# coding: utf-8

# In[24]:


def my_var():
    import path as p

    fld = p.Path('./new_folder')
    if not fld.isdir():
        fld.mkdir()

    fld = fld / 'f.txt'
    if not fld.isfile():
        fld.touch()

    fld.write_text('\nSUCCESS!!!\n')

    for i in fld.lines():
        print(i)
        
if __name__ == '__main__':
    my_var()

