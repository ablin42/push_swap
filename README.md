# push_swap
### This is the push_swap project done @ 42 Paris

[Subject] (https://github.com/ablin42/push_swap/blob/master/push_swap.pdf)
This project require us to sort data on a stack, with a limited set of instructions, with as little move as it takes.
To validate the project, we have to handle multiple sorting algorithms and chose which solution is the best for an optimized sorting of the data.

## Instruction set
A typo in an instruction/an instruction that doesn't exist will cause the program to print Error and end.

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

### Objectives
> - Sorting algorithms
> - Stack notions

### Skills
> - Rigor
> - Imperative programming
> - Algorithms & AI
> - Unix
