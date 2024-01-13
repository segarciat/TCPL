# Exercise 2-2

Write a loop to the `for` loop below from the `getline` program of Chapter 1 without using `&&` or `||`:

```c
for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
```
