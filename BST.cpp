#include <iostream>
#include <cmath>
#include <cstdlib>

// This program will check whether given BST is balanced or not, find its max and min height

using namespace std;


// class of node
class Node
{
	public:
		int data;
		Node *left,*right;
		Node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
};

// class of binary search tree
class BST
{
	public:
		Node *root;
		BST()
		{
			root = NULL;
		}
	void insertNode(int d)  // insert the node in BST
	{
		Node *temp = new Node(d);
		if(root == NULL)
		{
			root = temp;
			return;
		}
		else
		{
			Node *cur = root;
			Node *pre = root;
			while(cur != NULL)
			{
				pre = cur;
				if(cur->data > d)
				   cur = cur->left;
				else
				   cur = cur->right;
			}
			if(pre->data > d)
			     pre->left = temp;
			else
			     pre->right = temp;
		}
	}
};


// Find maximum height of tree
int height(Node *root)
{
	if(root == NULL)
	       return 0;
	return 1 + max(height(root->left), height(root->right));   	
}
 
 // Find minimum height of tree
 
int minheight(Node *root)
{
	if(root == NULL)
	       return 0;
	return 1 + min(height(root->left), height(root->right));   	
}




// check whether given BST is balanced or not
bool isBalanced(Node *root)
{
	if(root == NULL)
	  return true;
	int ls = height(root->left);
	int rs = height(root->right);
	if(abs(ls-rs) <= 1 && isBalanced(root->left) && isBalanced(root->right))
	    return true;
	return false;	  
}

// driver program
int main()
  { 
    BST tree;
	int n,k;
	cout << "Enter no of nodes" << endl;
	cin >> n;
	cout << endl;
	cout << "Enter them"<<endl;
	for(int i=1 ; i <= n ; i++)
	   {
	   	cin >> k;
	   	tree.insertNode(k);
	   }
	   cout << endl;
    if (isBalanced(tree.root))
            cout << "    Given BST tree is balanced" << endl;
    else
            cout <<"     Given BST tree is unbalanced" <<endl;
    cout << "max height of tree:  " << height(tree.root) << endl;
    cout << "min height of tree:  " << minheight(tree.root) << endl;

	return 0;
  }

