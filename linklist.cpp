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

class Linklist
{
	
	public:
		Node *ptr;
		// Default Constructor
		Linklist()
		{
			ptr = NULL;
		}
              // Destructor
              ~Linklist()
               {
                        delete ptr;
                 }	
	void insertNodeAtFront(int d);
	void deleteNodeAtFront();
	void insertNodeAtEnd(int d);
	void insertNodeafterthat(int d,int d1);
	void deleteNodeAtEnd();
	void displayLinklist();
	void deleteNode(int d);
	int countNodes();
	bool isempty();
};

// insert the node at front of linked list
void Linklist::insertNodeAtFront(int d)
{
	Node *temp;
	temp = new Node(d);
	temp->next = ptr;
	ptr = temp;
}

// delete node at front of linked list
void Linklist::deleteNodeAtFront()
{
	if(ptr == NULL)
	{
		return;
	}
	Node *temp;
	temp = ptr;
	ptr = ptr->next;
	delete temp;
}
// insert node at end of linked list
void Linklist::insertNodeAtEnd(int d)
{
	Node *temp, *cur;
	temp = new Node(d);
	if( ptr == NULL)
	{
		ptr = temp;
              return; 
	}
	cur = ptr;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = temp;
}

// insert node that contain d1(data) after the node that contains given data(d)
void Linklist::insertNodeafterthat(int d,int d1)
{
	Node *temp;
	temp = new Node(d1);
	Node *cur;
	cur = ptr;
	while(cur->data != d)
	{
		cur = cur->next;
	}
	temp->next = cur->next;
	cur->next = temp;
}

// delete node at end
void Linklist::deleteNodeAtEnd()
{
        if (ptr == NULL)
         {
              return;
          }
	Node *temp;
	temp = ptr;
	if (ptr->next== NULL) // if linked list has only one node
	{
		ptr = NULL;
		delete temp;
		return;
	}
	while(temp->next->next != NULL) // we give this condition, so that we can set temp->next to Null
	{
		temp = temp->next;
	}
	delete temp->next;  
    temp->next = NULL;
}

// display the linked list
void Linklist::displayLinklist()
{
	Node *temp;
	temp = ptr;
	if (temp == NULL)
	{
		return;
	}
	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
 // delete node that contain data d in linked list
void Linklist::deleteNode(int d)
{
	Node *temp;
	temp = ptr;
	if( temp == NULL) // if linked list is empty
	{
		return;
	}
        if(temp->data == d) // if node that we want to delete is at front
        {
               ptr = ptr->next;
               delete temp;
               return;
          }
	Node *cur = ptr;
	while (temp->next->data != d) // temp will point on prev node of that node which we want to delete
	{
		temp = temp->next;
	}
	while(cur->data != d) // cur will point to node which we want to delete
	{
		cur = cur->next;
	}
	temp->next = cur->next;
       delete cur;
}
// it will just count the total nodes in linked list
int Linklist::countNodes()
{
    Node *temp;
	temp = ptr;
	int sum = 0;
	while(temp != NULL)
	{
		sum++;
		temp = temp->next;
	}
	return sum;	
}
// check whether linked list is empty or not
bool Linklist::isempty()
{
	return ptr == NULL;
}

// driver program
int main()
{
	Linklist l1,l2;
	l1.insertNodeAtEnd(30);
	l1.insertNodeAtFront(40);
	l1.insertNodeAtFront(10);
        l1.insertNodeAtEnd(11);
	l1.displayLinklist();
	cout << endl;
	l1.deleteNodeAtEnd();
	l1.displayLinklist();
	cout << endl;
	l1.deleteNodeAtFront();
	l1.displayLinklist();
	cout << endl;
        l1.deleteNode(30);
        l1.insertNodeafterthat(40,70);
        	l1.displayLinklist();
        	cout << endl;
        cout  << l1.countNodes() << endl;
        cout << boolalpha << l1.isempty() << endl;
        l2.insertNodeAtFront(100);
        l2.displayLinklist(); 
       return 0;
}               // here destructor calls and delete ptr then

