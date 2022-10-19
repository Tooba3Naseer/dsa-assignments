#include <iostream>

using namespace std;

//implementation of stack by using array
class Stack
{
	private:
		int top;
		int array[10];    // so stack has size 10
    public:
    	Stack()
    	{
    		top = -1;   // intialize the stack
    	}
    	bool isempty()
    	{
    		return (top==-1);
    	}
    	bool isfull()
    	{
    		return (top==9);  //  top==n-1 where n is size of stack
    	}
    	void push(int elem)
    	{
    		if (isfull())
    		{
    			cout << "  stack is full" << endl;
    			return;
    		}
    		top++;
    		array[top] = elem;
    		cout << elem << "  has been inserted" << endl;
    	}
    	void pop()
    	{
    		if(isempty())
    		{
    			cout << "  stack is empty" << endl;
    			return;
    		}
    		int temp = array[top];
    		top--;
    		cout <<  temp << "  has been deleted" << endl;
    	}
    	void deleteAll()
    	{
    		top=-1;
    		cout << "  all elements of stack has been deleted" << endl;
    	}
    	void display()
    	{
    		if(isempty())
    		{
    			cout << "  stack is empty" << endl;
    		}
    		for(int i =top; i >= 0; i--)
    		{
    			cout << array[i] <<"  ";
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
	
