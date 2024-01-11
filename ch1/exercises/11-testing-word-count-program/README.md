# Exercise 1-11

How would you test the word count program? What kind of inputs are most likely to uncover bugs if there are any?

## Solution

### String with no blanks (except the newline from pressing ENTER)

I would run the program and provide input containing no blanks, newlines, or tabs. For example, inputting:

```
hello
```

pressing ENTER, and pressing CTRL+D, the output should be 1 line, 1 word, 6 characters. Note that the newline character is part of the string since we have to express ENTER, which makes up the 6th invisible character.

### A single line without tabs, a single blank between words

The following should be 1 line, 4 words, 25 characters

```
hello world  im   sergio
```

### A single line with a single tab between words, no spaces

The following should be 1 line, 4 words, 22 characters

```
hello	world	im	sergio
```

### A single line, multiple tabs and multiple spaces between characters, and mix of spaces and tabs

The following is equivalent to `hello  world\t\tim \tsergio\n`, and should be 1 line, 4 words, 25 characters

```
hello  world		im 	sergio
```

### String with only blanks should have 0 words

An input such as ` \t\n  \n` and has 2 lines, 0 words, 6 characters
