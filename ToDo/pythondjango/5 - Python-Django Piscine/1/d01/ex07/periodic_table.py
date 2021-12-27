
# coding: utf-8

# In[47]:


def my_var():
    f = open('periodic_table.txt', 'r')

    elements = []
    for i in f:
        num = i.split('=')
        name = num[0].replace(' ','')
    #     print(num[1].strip())
        temp = []
        for j in num[1].strip().split(','):
            temp.append((j.strip().split(':')[0], j.strip().split(':')[1]))
    #     print(temp)
        elements.append([name, dict(temp)])

    # print(elements)

    f.close()

    previous_index = -1

#     print('<!DOCTYPE html>')
    print('<html>')
    print('<head>')
    print('<title>Periodic Table</title>')
    print('</head>')
    print('<body>')
    
    print('<center>')
    
    print('<table>')
    
    print('<caption>Periodic Table of Elements</caption>')

    for i in elements:
        if(int(i[1]['position']) == 0):
            print('<tr>')
        if((previous_index < int(i[1]['position'])) and (previous_index != -1) and (previous_index - int(i[1]['position']) != 1)):
            for j in range(int(i[1]['position']) - previous_index - 1):
                print('<td style="border: 1px solid black; padding:10px">')
                print('</td>')
        print('<td style="border: 1px solid black; padding:10px">')
        print('<h4>' + i[0] + '</h4>')
        print('<ul>')
        print('<li>No' + i[1]['number'] + '</li>')
        print('<li>' + i[1]['small'].strip() + '</li>')
        print('<li>' + i[1]['molar'] + '</li>')
        print('<li>' + i[1]['electron'] + ' electron' + '</li>')
        print('</ul>')
        print('</td>')
        previous_index = int(i[1]['position'])

    print('</tr>')
    print('</table>')
    
    print('</center>')

    print('</body>')
    print('</html>')
    
if __name__ == '__main__':
    my_var()

