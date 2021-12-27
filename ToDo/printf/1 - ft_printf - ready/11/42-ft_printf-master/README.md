# PRINTF Project

## Project Overview
PRINTF is a 42 Project that aims to mimic libc printf function

Basics, requested from subject:
* A) parsing for flags, field_width, precision, length_modifier.
* B) parsing for conversion specifier.
* C) displaying UTF-8 characters. (%C and %S).
* D) computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
* E) displaying signed numbers (%d %D %i).
* F) displaying pointer address (%p).

Bonus:
* A) <strong>At 140% of libc printf speed</strong> thanks to buffer addition and functions' optimization.
* B) Handles multi fd (use ft_dprintf(int fd, char const format, ...) instead of ft_printf).
* C) <strong>All flags stored on only 14 bits.</strong>
* D) wildcard_length_modifier (%*) : replaces precision and field_width with parameter in va_list ap.
* E) print_len with %n (refer to ft_printf.c : *va_arg(ap, int *) = p->len;).
* F) displaying errno with %m.
* G) colors with '%s' and then for example PF_BLUE.
* H) %f and %F to handle double and float numbers.
* I) %a and %A to handle hexadecimal double numbers (rather pointless...).
* J) Also returns the string only with ft_sprintf.

## Sources
* https://linux.die.net/man/3/printf

## Installation & Tests
```
$> make
$> gcc libftprintf.a srcs/main.c && ./a.out
```

## How to use examples
```
#include "ft_printf.h"
ft_printf("%sstring : %s, dec : %d, binary nb: %b, octal nb: %o, unsigned nb: %u, hexadecimal nb: %x, with uppercase: %X%s\n", PF_GREEN, "42", 42, 42, 42, 42, 42, 42, PF_EOC);
ft_printf("%S\n", L"잘했지 ?");
```

## Resulting outputs
```
$> string : 42, dec : 42, binary nb: 101010, octal nb: 52, unsigned nb: 42, hexadecimal nb: 2a, with uppercase: 2A
$> 잘했지 ?
```

## Contact & contribute
To contact me and helping me to (fix bugs || improve) ft_printf, feel free to e-mail me at **angavrel at student dot 42 dot fr**
