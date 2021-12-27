'''
Created on Jan 12, 2013

@author: dirk dierickx
'''


'''A package for removing wiki markup text'''


def from_string(string=''):
    '''
    Remove wiki markup text from a string
    '''
    from dewiki.parser import Parser
    return Parser().parse_string(string)


def from_byte(byte=None):
    pass


def from_file(file=None):
    pass
