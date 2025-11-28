# C
Imperative programming

## Libraries 

### Standard
| Library    | Description                              |
| ---------- | ---------------------------------------- |
| <stdio.h>  | input/output +                           |
| <math.h>   | mathematics                              |
| <stdlib.h> | allocating memory                        |
| <string.h> | string and memory work related functions |

### Other 
| Library    | Description                              |Installation|
| ---------- | ---------------------------------------- |------------|
|ncurses|library for creating TUIs (text-based user interfaces)|sudo apt-get install libncurses6 <br> sudo apt-get install libncurses-dev|



## Tips
- Assigning double value to an int variable truncates it
```C
int a = 3.7; // a is 3
int a = 5.5; // a is 5
int a = -5.5; // a is 5
```

