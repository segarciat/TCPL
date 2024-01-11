# Exercise 1-1

Run the `"hello, world"` program on your system. Experiment with leaving out parts of the program, to see what error messages you get.

## Omitting Include

The version `include-missing-hello.c` omits the `#include` line. It compiles successfully, but emits warnings such as:

```
warning: incompatible implicit declaration of built-in function ‘printf’
```

## Omitting Braces

The version `braces-missing-hello.c` omits the braces `{` and `}`, and it fails to compile with error:

```
hello-no-braces.c:4:5: error: expected declaration specifiers before ‘printf’
    4 |     printf("hello, world\n");
      |     ^~~~~~
hello-no-braces.c:5: error: expected ‘{’ at end of input
```

## Omitting Main Function Parentheses

The version `main-parens-missing-hello.c` omits the parentheses `()` that follow the main function, and fails to compile
with error:

```
hello-no-main-parens.c:4:1: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token
    4 | {
      | ^
```
