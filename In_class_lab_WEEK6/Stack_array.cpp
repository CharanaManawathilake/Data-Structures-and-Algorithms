#include <iostream>
using namespace std;

class Stack
{
private:
  int size;       // Size of the array.
  int top;        // Stores the index of the top of the stack
  int *stack_arr; // Creates an array to store the data.

public:
  Stack(int max_size) // Initializes the top to -1.
  {
    top = -1;
    size = max_size;
    stack_arr = new int[max_size];
  }

  void push(int value)
  {
    if (top == size - 1) // If the stack is full.
      cout << "Stack Overflow" << endl;
    else
      stack_arr[++top] = value; // Inputs the value if the stack is not full.
  }

  void pop()
  {
    if (top == -1) // If the stack is empty
      cout << "Stack Underflow" << endl;
    else // If the stack is not empty the top pointer is brought down by one place.
      top--;
  }

  bool isEmpty() // Returns true if the array is empty.
  {
    if (top == -1)
      return true;
    return false;
  }

  bool isFull() // Returns true if the array is full.
  {
    if (top == size - 1)
      return true;
    return false;
  }

  int stackTop() // Returns the value of the top of the stack.
  {
    if (top == -1) // If the stack is empty.
    {
      cout << "Stack Empty" << endl;
      return -1;
    }
    else
      return stack_arr[top];
  }

  void display() // Displays the entire stack as a list.
  {
    for (int i = 0; i <= top; i++)
    {
      cout << stack_arr[i] << ' ';
    }
    cout << endl;
  }
};

int main()
{
  Stack s(15);
  s.push(3);
  s.push(5);
  s.pop();
  s.display();
  // s.pop();
}