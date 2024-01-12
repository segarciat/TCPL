# Exercise 1-16

Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.

## Clarifications

Suppose the program sets line limit to 5. The result of the the program on the following input:

```
tree
biology
two
```

should be
```
biol
8
```

The limit of 5 means that the 5th character is the null character, so only 4 characters will actually display. Also, though `biology` has length 7, we must also account for the newline character, which is the 8th.
