## push_swap
This project is part of the 42 curriculum and was submitted in 42-berlin. The maximum number of points was achieved in the efficiency tests (100 / 500 random numbers). The bonus part was not processed. 
The sorting algorithm is based on a mix of my own thoughts & improvements and the thoughts of the so-called "Turk Algorithm" (https://medium.com/@ayogun/push-swap-c1f5d2d41e97). 
Instead of defining several variables within the linked list I tried to handle all the required calculations "in time". Hence, the linked list, I worked with is very easy and does only consists of two variables (value / next). Does this maybe save some memory space without requiring more processors capacity? I hope so and will make research on that issues in future. 

General project instructions
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Global variables are forbidden.
- You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top
- Instructions must be separated by a ’\n’ and nothing else.
- The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. 
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

<br>

The rules
- You have 2 stacks named a and b.
- At the beginning:
  - The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack b is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
  - sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - ss : sa and sb at the same time.
  - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  - rr : ra and rb at the same time.
  - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  - rrr : rra and rrb at the same time.
 
<br>

Additional work
  - the program is able to handle input if strings and ints are mixed, e. g. 
  $>./push_swap "1 2 4 3" 76 90 "348 05" 55

<br>

Known bugs
- there is a bug with input
  $>./push_swap “” - 1 4
  as "" will be handeled as "0".
  I have already uploaded a fixed version (arg_check_fixed.c), which has to be tested more seriously. 
