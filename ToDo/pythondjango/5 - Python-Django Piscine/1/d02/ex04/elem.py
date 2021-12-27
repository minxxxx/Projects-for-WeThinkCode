
# coding: utf-8

# In[120]:


# %load elem.py
#!/usr/bin/python3


class Text(str):
    """
    A Text class to represent a text you could use with your HTML elements.

    Because directly using str class was too mainstream.
    """

    def __str__(self):
        """
        Do you really need a comment to understand this method?..
        """

#         return super().__str__().replace('\n', '\n<br />\n')
        new = super().__str__()
        # new = super().__str__().replace('\n', '\n<br />\n')
        if(new == '<'):
            new = new.replace('<', '&lt;')
        if(new == '>'):
            new = new.replace('>', '&gt;')
        if(new == '"'):
            new = new.replace('"', '&quot;')
        new = new.replace('\n', '\n<br />\n')
        return new


class Elem:
    """
    Elem will permit us to represent our HTML elements.
    """
#     [...]
    class ValidationError(Exception):
        def __init__(self):
            self.message = 'Wrong format: this is not a Text or Elem type.'
        def __str__(self):
            return self.message

    def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
        """
        __init__() method.

        Obviously.
        """
#         [...]
        self.tag = tag
        self.attr = attr
        self.content = []
        self.tag_type = tag_type
    
        if(content):
            self.add_content(content)
        elif content != None:
            if not isinstance(content, Text):
                raise Elem.ValidationError

#         return '<div></div>'

    def __str__(self):
        """
        The __str__() method will permit us to make a plain HTML representation
        of our elements.
        Make sure it renders everything (tag, attributes, embedded
        elements...).
        """
        if self.tag_type == 'double':
            result = '<' + self.tag + self.__make_attr() + '>' + self.__make_content() + '</' + self.tag + '>'
        elif self.tag_type == 'simple':
#             [...]
            result = '<' + self.tag + self.__make_attr() + ' />'
        return result

    def __make_attr(self):
        """
        Here is a function to render our elements attributes.
        """
        result = ''
        for pair in sorted(self.attr.items()):
            result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
        return result

    def __make_content(self):
        """
        Here is a method to render the content, including embedded elements.
        """

        if len(self.content) == 0:
            return ''
        result = '\n'
        for elem in self.content:
            result += '  ' + str(elem).replace('\n', '\n  ') + '\n' 
        return result

    def add_content(self, content):
        if not Elem.check_type(content):
            raise Elem.ValidationError
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    @staticmethod
    def check_type(content):
        """
        Is this object a HTML-compatible Text instance or a Elem, or even a
        list of both?
        """
        return (isinstance(content, Elem) or type(content) == Text or
                (type(content) == list and all([type(elem) == Text or
                                                isinstance(elem, Elem)
                                                for elem in content])))


if __name__ == '__main__':
    print(Elem(tag='html', tag_type='double', 
          content=[Elem(tag='head', tag_type='double',
                       content=[Elem(tag='title', tag_type='double', content=Text('Hello ground!'))]), 
                   Elem(tag='body', tag_type='double',
                       content=[Elem(tag='h1', tag_type='double', content=Text('Oh no, not again!')),
                               Elem(tag='img', tag_type='simple', attr={'src':"http://i.imgur.com/pfp3T.jpg"})])]))


# In[118]:


str(Text('<'))

