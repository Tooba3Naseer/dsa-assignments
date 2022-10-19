#include <iostream>


using namespace std;

class Node
{
	public:
		int data;
		Node *RLink,*LLink;
		// constructor
		Node(int d)
		{
			data = d;
			RLink = NULL;
			LLink = NULL;
		}
};



class DoublyLinklist
{
	Node *ptr;
	public:
		DoublyLinklist()
		{
			ptr = NULL;
		}
		
		// insert node at front
		void insertNodeAtFront(int d)
		{
			Node *temp;
			temp = new Node(d);
			if (ptr == NULL)   // if doublylinklist is empty
			{
				ptr = temp;
			}
			else
			{
				temp->RLink = ptr;
				ptr->LLink = temp;
				ptr = temp;
			}
		}
		void insertNodeAtRearEnd(int d)
		{
			Node *temp;
			temp = new Node(d);
			if(ptr == NULL)
			{
				ptr = temp;
			}
			else
			{
				Node *cur;
				cur = ptr;
				while(cur->RLink != NULL)
				{
					cur = cur->RLink;
				}
				cur->RLink = temp;
				temp->LLink = cur;
			}
		}
		void deleteNodeAtFront()
		{
			if(ptr == NULL)
			{
				return;
			}
			Node *temp;
			temp = ptr;
			ptr = ptr->RLink;
			ptr->LLink = NULL;
			delete temp;
		}
		
		void deleteNodeAtRearEnd()
		{
			if (ptr == NULL)
			{
				return;
			}
			if(ptr->RLink == NULL)           // if list has only one node
			{
				Node *temp = ptr;
				ptr = NULL;
				delete temp;
				return;
			}
			else
			{
				Node *temp;
				temp = ptr;
				while(temp->RLink->RLink != NULL)
				{
					temp = temp->RLink;
				}
				delete temp->RLink;
				temp->RLink = NULL;
			}
		}
		void deleteNode(int d)
		{
			if (ptr==NULL)
			      return;
			if(ptr->data== d)   // if the node we want to delete is at front
			{
				Node *temp = ptr;
				ptr=ptr->RLink;
				ptr->LLink = NULL;
				delete temp;
				return;
			}
			Node *temp = ptr;            // if the node ant to delete is at end
			while(temp->RLink != NULL)
			{
				temp = temp->RLink;
			}
			if (temp->data== d)
			{
				this->deleteNodeAtRearEnd();
				temp = NULL;
				return;
			}
			else              // if the node we want to delete is  not at front and not at end
			{
				Node *temp;
				temp = ptr;
				while(temp->data != d)
				{
				    temp = temp->RLink;	
				}
				temp->LLink->RLink = temp->RLink;
				temp->RLink->LLink = temp->LLink;
				delete temp;
			}
		}
		
		void display()
		{
			if (ptr == NULL)
			{
				cout << "doubly link list is empty" << endl;
				return;
			}
			Node *temp = ptr;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->RLink;
			}
			cout << endl;
		}
};

int main()
{
	DoublyLinklist d1;
	d1.insertNodeAtFront(40);
	d1.insertNodeAtRearEnd(50);
	d1.insertNodeAtFront(90);
	d1.insertNodeAtFront(80);
	d1.display();
	d1.deleteNodeAtFront();
	d1.display();
	d1.deleteNode(50);
	d1.display();
	d1.deleteNodeAtRearEnd();
	d1.display();
	return 0;
}
