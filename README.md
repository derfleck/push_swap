# push_swap
## Task
Create a program that is able to sort a set of integer values as quickly as possible. The program receives a set of integer values (they can be negative or positive, but aren't allowed to exceed the integer range), that is stored in **stack a**. Those values need to be sorted using certain instructions and **stack b**. In general, those instructions can be summed up like this:
 - **Swap**: swap the first two elements of a stack
 - **Push**: push the first element of one stack on another
 - **Rotate**: move elements up or down by one, the first element becomes the last (regular) or the last element becomes the first (reverse)

Both rotate and swap can be executed for both stacks the same time (ss, rr, rrr), which saves instructions required.

## Errors
- some arguments aren't integers
- some arguments are out of integer range
- no duplicate values allowed

## Requirements

 - [x] Program needs to take **integer values** (signed) as arguments
 - [x] Program needs to be **called push_swap**
 - [x] Output of program needs to be instructions followed by a new line
 - [x] Allocated memory needs to be freed correctly (no memory leaks)
 - [x] No global variables
 - [ ] If no parameters are provided, the prompt needs to returned (no values)
 - [ ] Errors need to be handled (needs to show Error and new line)

## Solution
