# Exercise 1-2

Experiment to find out what happens when `printf`'s argument string contains `\c`, where `c` is some character that
does not correspond to a valid escape sequence. The complete list is in sectin 2.3, and is as follows:

* `\a`: alert (bell) character
* `\b`: backspace
* `\f`: formfeed
* `\n`: newline
* `\r`: carriage return
* `\t`: horizontal tab
* `\v`: vertical tab
* `\\`: backslash
* `\?`: question mark
* `\'`: single quote
* `\"`: double quote
* `\ooo`: octal number
* `\xhh`: hexadecimal number

## Solution

The program `invalid-escape-sequence.c` includes the `printf("Hello, world\z\n");`. The program compiles successfully,
and the output is:

```
Hello, worldz
```

It does, however, emit the warning:

```
invalid-escape-sequence.c: In function ‘main’:
invalid-escape-sequence.c:6:30: warning: unknown escape sequence: '\z'
    6 |     printf("Hello, world\z\n");
      |                              ^
```
