## <b> Summary: </b><br>
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

## <b> Introduction: </b><br>
The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

## <b> General Considerations: </b><br>
- The second project of Codam (42 Network School) in the ai branch, the full PDF can be found in this repository. <br>
- Solo project (two persons).
- Makefile commands: 
```
make
make re
make clean
make fclean
```

## <b> Checker: </b><br>
Takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

- Usage: 
```
./checker [ set of numbers ]
```

## <b> Push Swap: </b><br>
Calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

- Usage: 
```
./push_swap [ set of numbers ]
```

###### <b> Combine both to check if push swap is sorting correctly: </b><br>

- Usage: 
```
ARG="[ set of numbers ]"; ./push_swap $ARG | ./checker $ARG
```

###### <b> Valid instructions: </b><br>
> sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements). <p>
> sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements). <p>
> ss : sa and sb at the same time.  <p>
> pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty. <p>
> pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.  <p>
> ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.  <p>
> rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one. <p>
> rr : ra and rb at the same time.  <p>
> rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.  <p>
> rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.  <p>
> rrr : rra and rrb at the same time.
