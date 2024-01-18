#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
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
/**
 *struct parse_s - array containing variables
 *@args: argument
 *@file: path to the file of monty code
 *@index: sows the content of the monty file
 *@flag: switches between a queue and a stack
 *
 *Description: a fixed array
 */
typedef struct parse_s
{
	char *args;
	FILE *file;
	char *index;
	int flag;
} parse_t;
extern parse_t parse;
void error(int err_code, ...);
void pall_node(stack_t **head, unsigned int count);
int main(int argc, char *argv[]); 
void free_list(stack_t *head);
int find(char *index, stack_t **top, unsigned int count, FILE *file);
void push_node(stack_t **head, unsigned int count);
void add_func(stack_t **head, int value);
void add_queue(stack_t **head, int value);
void pint_node(stack_t **head, unsigned int count);
void pop_node(stack_t **head, unsigned int count);
void swap_node(stack_t **head, unsigned int count);
void add_node(stack_t **head, unsigned int count);
void nop_node(stack_t **head, unsigned int count);
#endif /* MONTY_H */
