#include <iostream>
#include <cmath>

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

void inorder(Node *root)
{
	if(root==NULL)
	    return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int height(Node *root)
{
	if(root == NULL)
	       return 0;
	return 1 + max(height(root->left), height(root->right));   	
}

int getBalance(Node *root)
{
	int ls = height(root->left);
	int rs = height(root->right);
	return ls-rs;
}

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

Node *leftLeft(Node *root)
{
	Node *pivot = root;
	Node *cur = pivot->left;
	Node *temp = cur->right;
	cur->right = pivot;
	pivot->left = temp;	
	return cur;
}

Node *rightRight(Node *root)
{
	Node *pivot = root;
	Node *cur = pivot->right;
	Node *temp = cur->left;
	cur->left = pivot;
	pivot->right = temp;
	return cur;
}

Node *rightLeft(Node *root)
{
	Node *cur = root->left;
	Node *temp = rightRight(cur);
	return leftLeft(root);
}

Node *leftRight(Node *root)
{
	Node *cur = root->right;
	Node *temp  = leftLeft(cur);
	return rightRight(root);
}

Node *insetBalance(Node *node, int d)
{
    if (node == NULL)
        return(Node(d));
 
    if (d < node->data)
        node->left  = insertBalance(node->left, d);
    else if (d > node->data)
        node->right = insertBalance(node->right, d);
    else // Equal keys not allowed
        return node;
 
    if (isBalanced(node))
           return node;
    else
    {
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && d < node->left->data)
        return leftLeft(node);
 
    // Right Right Case
    if (balance < -1 && d > node->right->data)
        return rightRight(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->data)
    {
        return rightLeft(node);
    }
 
    // Right Left Case
    if (balance < -1 && d < node->right->data)
    {
        return leftRight(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
  }
	
}

int main()
{ Node *root;
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

	cout << "enter node that you want to insert" << endl;
	cin >>k;
	makeBalance(k,tree);
	Node *root = tree.root;
	tree.inorder(root);
	return 0;
}
