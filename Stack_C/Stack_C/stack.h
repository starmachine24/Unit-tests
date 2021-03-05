#pragma once
#include <stdio.h>
#include <stdlib.h>
struct Stack_element
{
	int value;
	struct Stack_element *next;
};

struct Stack
{
	struct Stack_element *first;
	struct Stack_element *last;
};

void push(int value, struct Stack *stack);
void pop(struct Stack *stack);
void print_stack(struct Stack *stack);
void clear_stack(struct Stack *stack);