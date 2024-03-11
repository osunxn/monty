" Monty - Stacks, Queues - LIFO, FIFO

" This repository contains the implementation of a simple interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes, and this interpreter processes these byte codes.

" ## Resources
" - [Google](https://www.google.com)
" - [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files-in-c)
" - [Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)
" - [Stack operations](https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm)
" - [Queue operations](https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm)

" ## Learning Objectives
" After completing this project, you should be able to explain the following concepts without relying on external sources:

" ### General
" - The meanings of LIFO and FIFO
" - Understanding stacks, their usage, and common implementations
" - Understanding queues, their usage, and common implementations
" - Common use cases of stacks and queues
" - Proper use of global variables in C

" ## Requirements
" ### General
" - Allowed editors: vi, vim, emacs
" - Compilation on Ubuntu 20.04 LTS using gcc with options: `-Wall -Werror -Wextra -pedantic -std=c89`
" - Files should end with a newline
" - A `README.md` file at the project's root
" - Code should follow the Betty style
" - A maximum of one global variable is allowed
" - No more than 5 functions per file
" - Usage of the C standard library is allowed
" - Prototypes of all functions should be included in the header file `monty.h`
" - Header files should be include guarded

" ## Data Structures
" Please use the following data structures for this project:

```vim
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
" ## Compilation & Output
" Compile the code using the following command:
" bash " $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty "

" Print any output on stdout and any error message on stderr.

" ## Tests
" Collaborate on creating a set of tests to ensure the correct functioning of the code.

" ## The Monty Language
" Monty 0.98 is a scripting language compiled into Monty byte codes. These files usually have the .m extension and contain instructions executed line by line.

" ### Monty Byte Code Files
" Files containing Monty byte codes have the .m extension. Each line contains at most one instruction. Blank lines are allowed.

" Example:
" monty " push 0 " push 1 " push 2 " pall "

" ### The Monty Program
" Usage: monty file

" - If no file or more than one argument is provided, print USAGE: monty file and exit with EXIT_FAILURE.
" - If the file cannot be opened, print Error: Can't open file <file> and exit with EXIT_FAILURE.
" - If an invalid instruction is encountered, print L<line_number>: unknown instruction <opcode> and exit with EXIT_FAILURE.

" The Monty program stops execution if:
" - All lines are executed successfully.
" - An error is encountered.
" - An error occurs during execution.

" ## Quiz Questions
" Answer quiz questions successfully.

" ## Tasks
" ### Task 0: push, pall
" Implement the push and pall opcodes.

" ### Task 1: pint
" Implement the pint opcode.

" ### Task 2: pop
" Implement the pop opcode.

" ### Task 3: swap
" Implement the swap opcode.

" ### Task 4: add
" Implement the add opcode.

" ### Task 5: nop
" Implement the nop opcode.

" ### Task 6: sub (Advanced)
" Implement the sub opcode.

" ### Task 7: div (Advanced)
" Implement the div opcode.

" ### Task 8: mul (Advanced)
" Implement the mul opcode.

" ### Task 9: mod (Advanced)
" Implement the mod opcode.

" ### Task 10: comments (Advanced)
" Implement comments. Lines starting with # should be treated as comments.

" ### Task 11: pchar (Advanced)
" Implement the pchar opcode.

" ### Task 12: pstr (Advanced)
" Implement the pstr opcode.

" ### Task 13: rotl (Advanced)
" Implement the rotl opcode.

" ### Task 14: rotr (Advanced)
" Implement the rotr opcode.

" ### Task 15: stack, queue (Advanced)
" Implement the stack and queue opcodes.

" ### Task 16: Brainfck (Advanced)
" Write a Brainfck script that prints "School", followed by a new line.

" ### Task 17: Add two digits (Advanced)
" Read two digits from stdin, add them, and print the result.

" ### Task 18: Multiplication (Advanced)
" Read two digits from stdin, multiply them, and print the result.

" ### Task 19: Multiplication Level Up (Advanced)
" Multiply two digits read from stdin, print the result followed by a new line.

" ## Directory Structure
" - bf: Contains Brainf*ck scripts.
" - bytecodes: Contains Monty byte code files.
