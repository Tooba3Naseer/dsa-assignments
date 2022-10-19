#include <iostream>



using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		// constructor
		Node(int d)
		{
			data = d;
			next = NULL;
		}
		
};


// implementation of stack by making linked list of nodes
class Stack
{
	private:
		Node *top;
	public:
		Stack()
		{
			top = NULL;
		}
		bool isempty()
		{
			return (top==NULL);
		}
		void push(int elem)
		{
			if(isempty())
			{
				top = new Node(elem);
				return;
			}
			Node *temp = new Node(elem);
			temp->next = top;
			top = temp;
			cout << elem << " has been pushed on top" << endl;
		}
		void pop()
		{
			if(isempty())
			{
				return;
			}
			Node *temp = top;
			int d = temp->data;
			top = top->next;
			delete temp;
			cout << d <<" has been deleted" << endl;	
		}
		void deleteAll()
		{
			Node *temp = top;
			top = NULL;	
			while(temp->next != NULL)
			{
				Node *cur = temp;
				temp = temp->next;
				delete cur;
			}	
		}
		void display()
		{
			if(isempty())
			{
				cout << "stack is empty" << endl;
				return;
			}
			Node *temp = top;
			while(temp!= NULL)
			{
				cout << temp->data <<" ";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main()
{
	Stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(90);
	s1.display();
	s1.pop();
	s1.display();
	s1.deleteAll();
	s1.display();
	return 0;
}
	
