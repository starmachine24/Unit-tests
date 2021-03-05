#include "stack.h"
#include "unit_tests.h"

void run_unit_tests(struct Stack *stack)
{
	printf("Starting test 1\n");
	unit_test_1(stack);
	printf("\n");

	printf("Starting test 2\n");
	unit_test_2(stack);
	printf("\n");

	printf("Starting test 3\n");
	unit_test_3(stack);
	printf("\n");

	printf("Starting test 4\n");
	//Run clear stack on an already cleared stack
	clear_stack(stack);
	printf("\n");

	printf("Starting test 5\n");
	//Pop from an already cleared stack
	pop(stack);
	printf("\n");

	printf("Starting test 6\n");
	unit_test_6(stack);
}

//Every third integer between 0 - 100 should be removed
void unit_test_1(struct Stack *stack)
{
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		push(i, stack);
        
		if(i % 3 == 0)
		{
			pop(stack);
		}
	}
	print_stack(stack);
	clear_stack(stack);
}

//In the end the stack should be empty after this test, which should trigger the error message in the print_stack function
void unit_test_2(struct Stack *stack)
{
	push(1, stack);
	pop(stack);
	push(2, stack);
	pop(stack);
	push(3, stack);
	push(4, stack);
	pop(stack);
	push(5, stack);
	pop(stack);
	push(6, stack);
	pop(stack);
	push(7, stack);
	pop(stack);
	pop(stack);
	print_stack(stack);
}
//The stack should contain 1 - 5 where 5 is a the top, afterwards clear the stack
void unit_test_3(struct Stack* stack)
{
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	push(1, stack);
	push(2, stack);
	push(3, stack);
	push(4, stack);
	push(5, stack);
	print_stack(stack);

	clear_stack(stack);
}

//At the end of the function the stack should only contain a 2 before it is cleared at the end of the function
void unit_test_6(struct Stack* stack)
{
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	push(1,stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	push(2, stack);

	print_stack(stack);
	clear_stack(stack);
}