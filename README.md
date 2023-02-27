# push_swap
## Task
Create a program that is able to sort a set of integer values as quickly as possible. The program receives a set of integer values (they can be negative or positive, but aren't allowed to exceed the integer range), that is stored in **stack a**. Those values need to be sorted using certain instructions and **stack b**. In general, those instructions can be summed up like this:
 - **Swap**: swap the first two elements of a stack
 - **Push**: push the first element of one stack on another
 - **Rotate**: move elements up or down by one, the first element becomes the last (regular) or the last element becomes the first (reverse)

Both rotate and swap can be executed for both stacks the same time (ss, rr, rrr), which saves instructions required.

## Allowed external functions
| function  | library  | description                       | used |
|-----------|----------|-----------------------------------|------|
| write     | unistd.h | write to a file descriptor        | yes  |
| read      | unistd.h | read from a file descriptor       | no   |
| malloc    | stdlib.h | allocates memory                  | yes  |
| free      | stdlib.h | frees reserved memory             | yes  |
| exit      | stdlib.h | causes normal process termination | yes  |
| ft_printf | libft.h  | recreates printf functionality    | no   |

## Errors
Under certain circumstances, the program needs to display an "Error" message on the standard output, followed by a newline. Those situations are:  
- arguments contain illegal characters and aren't valid integers (only -, digits and space characters are allowed - in that order)
- arguments are out of integer range
- duplicate values in arguments

## Requirements

 - [x] Program needs to take **integer values** (signed) as arguments
 - [x] Program needs to be **called push_swap**
 - [x] Output of program needs to be instructions followed by a new line
 - [x] Allocated memory needs to be freed correctly (no memory leaks)
 - [x] No global variables
 - [ ] If no parameters are provided, the prompt needs to returned (no values)
 - [ ] Errors need to be handled (see [Errors](#Errors))

## Solution


## Tester
- [Tester by gemartin99](https://github.com/gemartin99/Push-Swap-Tester): Good tester, but unfortunately **only for macOS** (shell script uses [leaks](https://www.unix.com/man-page/osx/1/leaks/) instead of valgrind)
- [Tester by laisarena](https://github.com/laisarena/push_swap_tester): Simple and checks for most use cases, but unfortunately not for leaks
- 