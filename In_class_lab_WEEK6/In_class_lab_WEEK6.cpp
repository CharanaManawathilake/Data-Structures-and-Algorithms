#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;
using namespace std::chrono;

// Emulating a Nodes structure
struct Node // Create a Node data structure
{
  int data;
  Node *next;

  Node(int value) // This method takes in a value and creates a node with node.data = value.
  {
    data = value;
    next = NULL;
  }
};

// Emulating a Stack using Linked_list structures.
class Linked_list_Stack
{
private:
  Node *head;

public:
  Linked_list_Stack() // Creates a null node/ head when called
  {
    head = NULL;
  }

  bool isEmpty() // Returns true if the stack is empty, else returns false.
  {
    if (head == NULL)
      return true;
    return false;
  }

  void push(int value)
  {
    Node *newNode = new Node(value); // Creates a new node with the given value.
    newNode->next = head;            // Assign the current head as the next node of the new node.
    head = newNode;                  // Assigne the new node to the head pointer.
  }

  void pop()
  {
    if (isEmpty()) // Checks if the stack is empty.
      cout << "stack Underflow" << endl;
    else // If the stack is not empty.
    {
      Node *temp = head;
      head = (*head).next; // Assigns the head pointer to the next node.
    }
  }

  int stackHead()
  {
    if (head == NULL) // Returns Empty if the stack is empty.
    {
      cout << "Stack is Empty" << endl;
      return -1;
    }
    return head->data; // Returns the head pointer if the stack is not empty.
  }

  void display() // Prints the stack as a list.
  {
    Node *currNode = head;
    while (currNode != NULL)
    {
      cout << currNode->data << ' ';
      currNode = currNode->next;
    }
    cout << endl;
  }
};

// Emulating a linked list using arrays.
class Array_Stack
{
private:
  int size;       // Size of the array.
  int top;        // Stores the index of the top of the stack
  int *stack_arr; // Creates an array to store the data.

public:
  Array_Stack(int max_size) // Initializes the top to -1.
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
  int x;
  cout << "Enter the array size : ";
  cin >> x;
  int array_time[5];
  int linkedlist_time[5];
  for (int i = 0; i < 5; i++)
  {
    auto start = high_resolution_clock::now();
    Array_Stack s(x);
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    array_time[i] = duration.count();
  }
  for (int i = 0; i < 5; i++)
  {
    auto start = high_resolution_clock::now();
    Linked_list_Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    linkedlist_time[i] = duration.count();
  }
  cout << "Array size is : " << x << "." << endl;
  cout << "Time taken by the array1 is : " << array_time[0] << " microseconds" << endl;
  cout << "Time taken by the array2 is : " << array_time[1] << " microseconds" << endl;
  cout << "Time taken by the array3 is : " << array_time[2] << " microseconds" << endl;
  cout << "Time taken by the array4 is : " << array_time[3] << " microseconds" << endl;
  cout << "Time taken by the array5 is : " << array_time[4] << " microseconds" << endl;
  cout << "Time taken by the linked_list1 is : " << linkedlist_time[0] << " microseconds" << endl;
  cout << "Time taken by the linked_list2 is : " << linkedlist_time[1] << " microseconds" << endl;
  cout << "Time taken by the linked_list3 is : " << linkedlist_time[2] << " microseconds" << endl;
  cout << "Time taken by the linked_list4 is : " << linkedlist_time[3] << " microseconds" << endl;
  cout << "Time taken by the linked_list5 is : " << linkedlist_time[4] << " microseconds" << endl;
}