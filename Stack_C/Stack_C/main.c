#include "stack.h"
#include "unit_tests.h"

void program(struct Stack* stack);

int main()
{
	struct Stack *the_stack;

	//Create the stack
	the_stack = (struct Stack*)malloc(sizeof(struct Stack));

	//Check if the stack was created successfully
	if(the_stack == NULL)
	{
		printf("Error could not create the stack, will now exit the program\n");
		exit(-1);
	}
	else
	{
		the_stack->first = NULL;
		the_stack->last = NULL;
	}
	
	//Main program
	program(the_stack);
	free(the_stack);
	system("pause");
	return 0;
}

void program(struct Stack *stack)
{
	char input[10] = {0};
	int value = 0;
	int exitP = 0;
	while(exitP == 0)
	{
		do {
			value = 0;
			system("cls");
			printf("What do you want to do?\n");
			printf("1. Add element\n");
			printf("2. Remove element\n");
			printf("3. Print stack\n");
			printf("4. Clear stack\n");
			printf("5. Run unit tests\n");
			printf("6. Exit\n");
			printf("Choice: ");
			//read the input from stdin and check if it could be read at all
			if(fgets(input, 10, stdin) == NULL)
			{
				printf("Error could not read input, Exiting program!\n");
				exit(-1);
			}
			//Convert the input read to an integer
			value = atoi(input);
		} while(value > 6 || value < 1);

		switch(value)
		{
			case 1:
				printf("Please enter a decimal number\n");
				printf("Number: ");
				if(fgets(input, 10, stdin) == NULL)
				{
					printf("Error could not read input, Exiting program!\n");
					exit(-1);
				}
				//Convert the input read to an integer
				value = atoi(input);
				push(value, stack);
				break;

			case 2:
				pop(stack);
				break;

			case 3:
				print_stack(stack);
				system("pause");
				break;

			case 4:
				clear_stack(stack);
				break;

			case 5:
				run_unit_tests(stack);
				system("pause");
				break;

			case 6:
				exitP = 1;
				break;

			default:
				break;
		}

	}
}