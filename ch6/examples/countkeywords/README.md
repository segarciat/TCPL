# Compiling and Running

Compile the program as follows:

```bash
gcc -std=c89 -o countkeywords main.c getch.c getword.c 
```

Run it as follows:

```bash
# Replace main.c with whatever file you want
countkeywords < main.c
```
