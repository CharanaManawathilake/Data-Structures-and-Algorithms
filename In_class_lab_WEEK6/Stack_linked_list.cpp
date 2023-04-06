#include <iostream>
using namespace std;

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

class Stack
{
private:
  Node *head;

public:
  Stack() // Creates a null node/ head when called
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

int main()
{
  Stack s;
  s.push(3);
  s.push(5);
  // s.pop();
  s.display();
  // s.pop();
}