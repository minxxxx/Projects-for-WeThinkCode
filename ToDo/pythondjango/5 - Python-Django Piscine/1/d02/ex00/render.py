
# coding: utf-8

# In[81]:


def my_var():
    import sys, os, re

    f = open(os.getcwd() + '/settings.py', 'r')
    l = []
    for i in f.read().replace('\n', ',').split(','):
    #     print(i)
        l.append(i.strip().split(' = '))

    d = dict((i[0].replace('\'', ''), i[1].replace('"', '')) for i in l)

    filename = sys.argv[1]

    try:
        if re.match("\w+.template", filename):
        #     print(filename)
            template_file = open(filename, 'r')
            output = open(filename.split('.')[0] + '.html', 'w')
            output.write(template_file.read().format_map(d))
            output.close()
        else:
            print('No template file in the directory')
            sys.exit(0)
    except FileExistsError as err:
        print("File {} doesn't exist!".format(err.filename))
        sys.exit(0)
    except FileNotFoundError as err:
        print("File {} not found!".format(err.filename))
        sys.exit(0)
    except Exception as err:
        print("Some error occured!")
        sys.exit(0)

if __name__ == '__main__':
    my_var()

