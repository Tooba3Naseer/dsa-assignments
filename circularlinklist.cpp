#include <iostream>

using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node(int d)
		{
			data = d;
			next = NULL;
		}
};

class CircularLinklist
{
	public:
		Node *ptr;
		CircularLinklist()
		{
			ptr = NULL;
		}
		void insertNodeAtFront(int d)
		{
			Node *temp;
			temp = new Node(d);
			if (ptr == NULL)
			{
				ptr = temp;
				temp->next = ptr;
			}
			else
			{
				Node *cur = ptr;
				while(cur->next != ptr)
				{
					cur = cur->next;
				}
				cur->next= temp;
				temp->next = ptr;
				ptr = temp;
			}
		}
		void insertNodeAtEnd(int d)
		{
			Node *temp;
			temp = new Node(d);
			if (ptr == NULL)
			{
				ptr = temp;
				temp->next = ptr;
			}
			else
			{
				Node *cur = ptr;
				while(cur->next!= ptr)
				{
					cur = cur->next;
				}
				cur->next = temp;
				temp->next= ptr;
			}
		}
		void concatenate(CircularLinklist &ptr1, CircularLinklist &ptr2)
		{
			Node *temp,*cur;
			temp = ptr1.ptr;
			cur = ptr2.ptr;
			while(temp->next != ptr1.ptr)
			{
				temp = temp->next;
			}
			while(cur->next != ptr2.ptr)
			{
				cur = cur->next;
			}
			temp->next = ptr2.ptr;
			cur->next = ptr1.ptr;
			ptr = ptr1.ptr;
		}
		void deleteNodeAtEnd()
		{
			if(ptr == NULL)
			{
				return;
			}
			Node *temp = ptr;
			if (temp->next == temp)
			{
				delete temp;
				ptr = NULL;
			}
			else
			{
			
			while(temp->next->next != ptr)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = ptr;
		    }
		}
		
		void deleteNodeAtFront()
		{
			if(ptr == NULL)
			{
				return;
			}
			Node *temp = ptr;
			if(temp->next == temp)
			{
				delete temp;
				ptr = NULL;
			}
			else
			{
				Node *cur = ptr;
				while(cur->next != ptr)
				{
					cur = cur->next;
				}
				ptr = temp->next;
				cur->next = ptr;
				delete temp;
			}
		}
		
		int countNodes()
		{
			if(ptr == NULL)
			{
				return 0;
			}
			int count = 0;
			Node *temp = ptr;
			while(temp->next != ptr)
			{
				temp = temp->next;
				count = count +1;
			}
			return count+1;
		}
		
		void display()
		{
			if(ptr == NULL)
			cout << "empty circularlink list" << endl;
			else
			{
				Node *temp = ptr;
				while(temp->next != ptr)
				{
					cout << temp->data <<" " ;
					temp=temp->next;
				}
				cout << temp->data << " ";
				cout << endl;
			}
		}
};

int main()
{
	CircularLinklist l1,l2,l3;
	l1.insertNodeAtFront(40);
	l1.insertNodeAtFront(10);
	l1.insertNodeAtEnd(30);
	l1.display();
	
	l2.insertNodeAtFront(403);
	l2.insertNodeAtFront(102);
	l2.insertNodeAtEnd(130);
	l2.display();
	l2.deleteNodeAtEnd();
	l2.display();
	cout << endl;
	l1.deleteNodeAtFront();
	l1.display();
	cout << endl;
	cout << "nodes in l1" << "   " << l1.countNodes() << endl;
	l3.concatenate(l1,l2);
	l3.display();
	
	return 0;
	
}
