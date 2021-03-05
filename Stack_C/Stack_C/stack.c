#pragma once
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void push(int value, struct Stack *stack)
{
	//Error handling for NULL pointers for the stack
	if(stack == NULL)
	{
		printf("Error stack is NULL, exiting program!\n");
		system("pause");
		exit(-1);
	}

	struct Stack_element *new_elem = NULL;
	new_elem = (struct Stack_element*)malloc(1 * sizeof(struct Stack_element));

	//Check for creation errors
	if(new_elem == NULL)
	{
		printf("Error could not create element, will now exit the program\n");
		exit(-1);
	}

	new_elem->value = value;
	new_elem->next = NULL;

	//Empty stack
	if(stack->first == NULL)
	{
		stack->first = new_elem;
		stack->last = new_elem;
	}
	//Non-empty stack
	else
	{
		stack->last->next = new_elem;
		stack->last = new_elem;
	}
}

void pop(struct Stack *stack)
{
	struct Stack_element *current = NULL;

	//The stack is empty
	if(stack->first == NULL)
		return;

	//If there is only one element in the stack
	else if(stack->first->next == NULL)
	{
		free(stack->first);
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		current = stack->first;

		//Find the second last element
		while(current->next != stack->last)
		{
			current = current->next;
		}

		//Remove the last element
		free(current->next);
		current->next = NULL;

		//Update the last pointer
		stack->last = current;
	}
}

void print_stack(struct Stack *stack)
{
	struct Stack_element *current;
	int i;
	//Error handling for NULL pointers for the stack
	if(stack == NULL)
	{
		printf("Error stack is NULL, exiting program!\n");
		system("pause");
		exit(-1);
	}
	//Stack is empty
	if(stack->first == NULL)
	{
		printf("Both pointers are NULL, therefore the stack is empty!\n");
		return;
	}

	current = stack->first;
	i = 0;
	while(current != NULL)
	{
		printf("Value of element on pos %d: %d\n",i ,current->value);
		current = current->next;
		i++;
	}
	//Print the value of the element that both first and last points to
	if(stack->first != NULL && stack->last != NULL)
	{
		printf("First points to elem with value: %d\n", stack->first->value);
		printf("Last points to elem with value: %d\n", stack->last->value);
	}
}

void clear_stack(struct Stack *stack)
{
	//Error handling for NULL pointers for the stack
	if(stack == NULL)
	{
		printf("Error stack is NULL, exiting program!\n");
		system("pause");
		exit(-1);
	}
	//Stack is empty
	if(stack->first == NULL)
	{
		printf("The stack is already empty!\n");
		system("pause");
		return;
	}

	struct Stack_element *current = stack->first;

	while(current->next != NULL)
	{
		stack->first = current->next;
		free(current);
		current = stack->first;
	}
	//If both first and last point to the same element, only one element remain in the stack
	if(stack->first == stack->last)
		free(stack->first);

	stack->first = NULL;
	stack->last = NULL;
}