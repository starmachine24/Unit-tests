#include "stack.h"
#include "unit_tests.h"

int popping_removes_top_elem_in_stack(struct Stack *stack);
int pushing_adds_element_on_top(struct Stack *stack);
int clear_already_empty_stack(struct Stack *stack);
int pop_from_empty_stack(struct Stack *stack);
int give_print_function_invalid_stack(struct Stack *stack);
int push_to_uninitialized_stack(struct Stack *stack);

void run_unit_tests(struct Stack *stack)
{
	printf("popping_removes_top_elem_in_stack result (1 pass, -1 fail): %d", popping_removes_top_elem_in_stack((struct Stack*)malloc(1 * sizeof(struct Stack))));
    
    printf("pushing_adds_element_on_top result (1 pass, -1 fail): %d", pushing_adds_element_on_top((struct Stack*)malloc(1 * sizeof(struct Stack))));
    
    printf("clear_already_empty_stack result (1 pass, -1 fail): %d", clear_already_empty_stack((struct Stack*)malloc(1 * sizeof(struct Stack))));
    
    printf("pop_from_empty_stack result (1 pass, -1 fail): %d", pop_from_empty_stack((struct Stack*)malloc(1 * sizeof(struct Stack))));
    
    printf("push_to_uninitialized_stack result (1 pass, -1 fail): %d", push_to_uninitialized_stack(NULL));
    
    printf("give_print_function_invalid_stack result (1 pass, -1 fail): %d", give_print_function_invalid_stack(NULL));
}

//Formerly known as unit_test_1
int popping_removes_top_elem_in_stack(struct Stack *stack)
{
    //Arrange
    int success = -1;
    
    stack->first = (struct Stack_element*)malloc(1 * sizeof(struct Stack_element));
    stack->last = (struct Stack_element*)malloc(1 * sizeof(struct Stack_element));
    
    stack->first->value = 5;
    stack->first->next = stack->last;
    
    stack->last->value = 10;
    stack->last->next = NULL;
    
    //Act
    pop(stack);
    
    //Assert
    if(stack->last->value == 5)
        success = 1;
    
    //Free the memory
    free(stack->first);
    free(stack);
    stack = NULL;
    
    return success;
}

//Simpler version of the former unit_test_3 
int pushing_adds_element_on_top(struct Stack *stack)
{
    //Arrange
    int success = -1;
    
    stack->first = (struct Stack_element*)malloc(1 * sizeof(struct Stack_element));
    
    stack->first->value = 5;
    stack->first->next = stack->last;
    stack->last = NULL;
    
    //Act
    push(25,stack);
    
    //Assert
    if(stack->last->value == 25)
        success = 1;
    
    //Free the memory
    free(stack->last);
    free(stack->first);
    free(stack);
    stack = NULL;
    
    return success;
}

//Formerly known as unit_test_4, this one will fail
void clear_already_empty_stack(struct Stack *stack)
{
    //Arrange
    int success = -1;
    stack->first = NULL;
    stack->last = NULL;
    
    //Act
    clear_stack(stack);
    
    //Assert
    if(stack == NULL)
        success = 1;
    
    return success;
}

//Formerly known as unit_test_5, this one is a fail, not correctly handeled
int pop_from_empty_stack(struct Stack *stack)
{
    //Arrange
    int success = -1;
    stack->first = NULL;
    stack->last = NULL;
    
    //Act
    pop(stack);
    
    //Assert
    if(stack == NULL)
        success = 1;
    
    return success;
}
//New test, this one will be correctly handled
int push_to_uninitialized_stack(struct Stack *stack)
{
    //Arrange
    int success = -1;
    
    //Act
    push(2,stack);
    
    //Assert
    if(stack == NULL)
        success = 1;
    
    free(stack);
    stack = NULL;
    return success;
}
//New test
int give_print_function_invalid_stack(struct Stack *stack)
{
    //Arrange
    int success = -1;
    
    //Act
    print_stack(stack);
    
    //Assert, 
    if(stack == NULL)
        success = 1;
        
        
    free(stack);
    stack = NULL;
    return success;
}