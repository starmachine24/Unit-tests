using System.Collections.Generic;

namespace stack_C_Sharp
{
	public class Stack_element
	{
		int value;

		public Stack_element()
		{
			value = 0;
		}

		public Stack_element(int _value)
		{
			value = _value;
		}

		public int Get_value()
		{
			return value;
		}
	}

	public class Stack
	{
		public List<Stack_element> stack;

		public Stack()
		{ 
			stack = new List<Stack_element>();
		}

		//Add the element to the stack
		public void Push(Stack_element elem)
		{
			stack.Add(elem);
		}

		//Remove the last element in the stack
		public void Pop()
		{
			int lastElem = stack.Count;

			if (lastElem == 0)
				return;

			stack.RemoveAt(lastElem - 1);
		}

		public void Print_stack()
		{
			int i = 0;
			if (stack.Count == 0)
				System.Console.WriteLine("The stack is Empty");

			//Print out the stack and each element's position in the stack
			foreach (var element in stack)
			{
				System.Console.WriteLine("Value of element on pos " + i + ": " + element.Get_value());
				i++;
			}
		}

		public void Clear_stack()
		{
			stack.Clear();
		}
	}
}
