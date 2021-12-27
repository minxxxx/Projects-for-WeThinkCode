# ft_printf: a 42 project

The goal of this project was to recode the printf function with the following prototype
(same as man 3 printf, except for the name):
```
int ft_printf(const char *format_string, ...);
```

Other information about the project:
- there is no required buffer, as is present in the system printf
- the following conversions are supported: sSpdDioOuUxXcC
- the %% is supported
- the following flags are supported: #0-+[SPACE]
- the following lengths flags are supported: hh, h, l, ll, j, z
- precision is supported
- basic functionality for * is supported

Authorized functions:
- malloc
- free
- exit
- functions from man 3 stdarg
