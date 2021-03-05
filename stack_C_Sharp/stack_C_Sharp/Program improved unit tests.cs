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
            System.Console.writeLine("Ret val popping_removes_top_elem (1 = pass, -1 = fail) = " + popping_removes_top_elem(new Stack());
            
            System.Console.writeLine("Ret val pushing_adds_new_elem_on_top (1 = pass, -1 = fail) = " + pushing_adds_new_elem_on_top(new Stack());
            
            System.Console.writeLine("Ret val clear_an_already_empty_stack (1 = pass, -1 = fail) = " + clear_an_already_empty_stack(new Stack());
            
            System.Console.writeLine("Ret val peak_returns_top_elem (1 = pass, -1 = fail) = " + peak_returns_top_elem(new Stack());
            
            System.Console.writeLine("Ret val get_size_of_stack (1 = pass, -1 = fail) = " + get_size_of_stack(new Stack());
		}
        
        //Formerly known as Unit_test1
		static public int popping_removes_top_elem(Stack _stack)
		{
            //Arrange
            int size;
            int success = -1;
            
            //Add elements to the stack
            _stack.stack.Add(new Stack_element(2));
            _stack.stack.Add(new Stack_element(45));
            size = _stack.stack.Count;
            
            //Act
            _stack.Pop();
            
            //Assert
            if(_stack.stack.Count == size - 1)
                success = 1; //Error
            
            return success;
		}

        //Formerly known as Unit_test2
		static public int pushing_adds_new_elem_on_top(Stack _stack)
		{
            //Arrange
            int temp = 3;
            int success = -1;
            
            //Act
            _stack.Push(new Stack_element(temp));
            
            //Assert
            if(_stack.stack[_stack.stack.Count - 1].Get_value() == temp)
                success = 1;
            
            return success;
		}
        
		//Formerly known as Unit_test3
		static public int clear_an_already_empty_stack(Stack _stack)
		{
            //Arrange
            int success = -1;
            
            //Act
            _stack.Clear_stack();
            
            //Assert
            if(_stack.stack.Count == 0)
                success = 1;
            
            return success;
		}
        
		//Formerly known as Unit_test4, this one will fail since the functionality is not even implemented
		static public int peak_returns_top_elem(Stack _stack)
		{
           //Arrange
           Stack_element stk_elem;
           int success = -1;

            //Add elements to the stack
           _stack.stack.Add(new Stack_element(45));
           _stack.stack.Add(new Stack_element(109));
           _stack.stack.Add(new Stack_element(11));

           //Act
           stk_elem = _stack.Peak();
           
           //Assert
           if(stk_elem == _stack.stack[2])
               success = 1;
           
           return success;
		}
        //New test will fail since the functionality is not implemented
        static public int get_size_of_stack(Stack _stack)
        {
            //Arrange
            int size = 0;
            int success = -1;
            
            //Add elements to the stack
           _stack.stack.Add(new Stack_element(1));
           _stack.stack.Add(new Stack_element(2));
           _stack.stack.Add(new Stack_element(3));
            
            //Act
            size = _stack.GetSize();
            
            //Assert
            if(size == 3)
                success = 1;
            
            return success;
        }
	}
}
