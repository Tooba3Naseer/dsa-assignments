#include <iostream>

using namespace std;

// In this program we write the non-recursive version of inorder traversal. For this purpose,
// we first convert the BST to right threaded binary tree, then write another function which outputs the 
// inorder traversal of tree. The basic advantage of non-recursive version of inorder over recursive version 
// is that it is more efficient because no extra space is required, no stack overflow. 

// class of node
class Node
{
	public:
		int data;
		Node *left,*right;
		int tag; // through tag, we check whether it is link or thread to its inorder successor 
		Node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
			tag = 0;  //intial it is 0
		}
};

// this class will make binary search tree
class BST
{
	
	public:
		Node *root;
		BST()
		{
			root = NULL;
		}
	void insert(int d);
};

// insertion in BST
void BST::insert(int d)
{
	Node *temp;
	temp = new Node(d);
	if(root == NULL)
	{
	  root = temp;	
	}
	else
	{
		Node *cur,*pre;
		cur = root;
		while(cur != NULL)
		{
			pre = cur;
			if(cur->data > d)
			    cur = cur->left;
			else
			    cur = cur->right;
		}
		if (pre->data > d)
				pre->left = temp;
		else
		   pre->right= temp;
		
	}
}

// now convert BST to threaded binary tree
void makeItrightThreaded(BST &tree)
{
	Node *root = tree.root;
	if (root == NULL)   
	     return;
    Node *cur, *pre;
    cur = root;
    while(cur != NULL)
    {
    	if(cur->left == NULL)
    	   cur = cur->right;
    	else
    	{
    		pre = cur->left;
    		if(pre == NULL)
    		   return;
    		while(pre->right != NULL && pre->right!=cur)
    		       pre = pre->right;
    		if(pre->right == NULL)  
    		    {
    		    	pre->right = cur;  // thread 'pre node' to its inorder successor
    		    	pre->tag = 1;     // then set tag to 1 which shows that this node has thread
    		    	cur = cur->left;
    		    }
    		 if(pre->right==cur)  
			       cur = cur->right; 
    		    
    	}
    }	
}

// now pass threaded binary tree to this function, which outputs the inorder traversal
void nonRecursiveInorder(BST &tree)
{
	Node *ptr = tree.root;
	cout << " Inorder traversal of given tree " << endl;
	while(ptr!=NULL)
	{
		while(ptr->left != NULL)
			ptr = ptr->left;
		cout << ptr->data <<" ";
		while(ptr->tag == 1)
		{
			ptr = ptr->right;
			cout << ptr->data << " ";
		}
		ptr=ptr->right;
	}
}

// driver program
int main()
{
	BST tree;
	int n,k;
	cout << "enter no of nodes" << endl;
	cin >> n;
	cout << endl;
	cout << "Enter them"<<endl;
	for(int i=1 ; i <= n ; i++)
	   {
	   	cin >> k;
	   	tree.insert(k);
	   }
	   makeItrightThreaded(tree);
	   nonRecursiveInorder(tree);
	   return 0;
}


