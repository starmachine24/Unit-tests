namespace stack_C_Sharp
{
	class Program
	{
		static void Main()
		{
			int result;
			int exit = 0;
			string input;
			Stack stack = new Stack();

			//stack.Print_stack();
			while(exit == 0)
			{
				do
				{
					System.Console.Clear();
					System.Console.WriteLine("What do you want to do?");
					System.Console.WriteLine("1. Add element");
					System.Console.WriteLine("2. Remove element");
					System.Console.WriteLine("3. Print stack");
					System.Console.WriteLine("4. Clear stack");
					System.Console.WriteLine("5. Run unit tests");
					System.Console.WriteLine("6. Exit");
					System.Console.Write("Choice: ");
					input = System.Console.ReadLine();

					//Try to parse the input, result == 0 if it is not parsed correctly
					int.TryParse(input, out result);

					//System.Console.WriteLine("Value of result is: " + result);

				} while (result > 6 || result < 1);

				switch(result)
				{
					case 1:

						//Loop for as long as the program receives invalid input
						do
						{
							System.Console.Write("Please enter a decimal number: ");
							input = System.Console.ReadLine();

						}while(!int.TryParse(input, out result));
						stack.Push(new Stack_element(result));
						break;

					case 2:
						stack.Pop();
						break;

					case 3:
						stack.Print_stack();
						System.Console.WriteLine("Press any key to continue");
						System.Console.ReadKey();
						break;

					case 4:
						stack.Clear_stack();
						System.Console.WriteLine("Press any key to continue");
						System.Console.ReadKey();
						break;

					case 5:
						Unit_tests(stack);
						break;

					case 6:
						exit = 1;
						break;
				}

			}
		}

		static public void Unit_tests(Stack stack)
		{
			System.Console.WriteLine("Starting Unit test 1");
			Unit_test1(stack);
			System.Console.WriteLine("");

			System.Console.WriteLine("Starting Unit test 2");
			Unit_test2(stack);
			System.Console.WriteLine("");

			System.Console.WriteLine("Starting Unit test 3");
			Unit_test3(stack);
			System.Console.WriteLine("");

			System.Console.WriteLine("Starting Unit test 4");
			Unit_test4(stack);

			stack.Print_stack();
			System.Console.WriteLine("Press any key to continue");
			System.Console.ReadKey();
		}

		//Unit test that pops every third element from the stack
		static public void Unit_test1(Stack stack)
		{
			int i = 0;

			for(i = 0; i < 100; i++)
			{
				stack.Push(new Stack_element(i));

				if (i % 3 == 0)
					stack.Pop();
			}
			stack.Print_stack();
			stack.Clear_stack();
			System.Console.WriteLine("Press any key to continue");
			System.Console.ReadKey();
		}
		//Test that add a bunch of elements and then removes an equal amount of elements, the stack should be empty when function is complete
		static public void Unit_test2(Stack stack)
		{
			stack.Push(new Stack_element(1));
			stack.Pop();
			stack.Push(new Stack_element(2));
			stack.Push(new Stack_element(3));
			stack.Push(new Stack_element(4));
			stack.Pop(); 
			stack.Push(new Stack_element(5));
			stack.Push(new Stack_element(6));
			stack.Pop(); 
			stack.Push(new Stack_element(7));
			stack.Pop();
			stack.Pop();
			stack.Pop();
			stack.Pop();

			stack.Print_stack();
			System.Console.WriteLine("Press any key to continue");
			System.Console.ReadKey();
		}
		//First tries to pop from an empty Stack then adds 5 new elements to the stack
		static public void Unit_test3(Stack stack)
		{
			stack.Pop();
			stack.Pop();
			stack.Push(new Stack_element(1));
			stack.Push(new Stack_element(2));
			stack.Push(new Stack_element(3));
			stack.Push(new Stack_element(4));
			stack.Push(new Stack_element(5));

			stack.Print_stack();
			stack.Clear_stack();
			System.Console.WriteLine("Press any key to continue");
			System.Console.ReadKey();
		}
		//After this function the stack should still contain elements 2, 3, and 6 in it
		static public void Unit_test4(Stack stack)
		{
			stack.Push(new Stack_element(11));
			stack.Clear_stack();
			stack.Push(new Stack_element(-1));
			stack.Push(new Stack_element(1));
			stack.Clear_stack();
			stack.Push(new Stack_element(2));
			stack.Push(new Stack_element(3));
			stack.Push(new Stack_element(6));
		}
	}
}
