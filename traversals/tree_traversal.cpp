#include <iostream>
using namespace std;

/* Basic structure of a binary tree.
It has data, pointer to left child and a pointer to right child */
struct Tree {
	int data;
	struct Tree *left, *right;
};

//Utility function to create a new tree
Tree* newTree(int data)
{
	Tree* temp = new Tree;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* "bottom-up" postorder traversal - postorder */
void printPostorder(struct Tree* node)
{
	if (node == NULL)
		return;

	// first traversal on left subtree
	printPostorder(node->left);

	// then traversal on right subtree
	printPostorder(node->right);

	// now show node data
	cout << node->data << " ";
}

/* Print the binary tree nodes in inorder*/
void printInorder(struct Tree* node)
{
	if (node == NULL)
		return;

	/* first traversal on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now traversal on right child */
	printInorder(node->right);
}

/* Print the binary tree nodes in preorder*/
void printPreorder(struct Tree* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left subtree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
	cout << "\nCompound a binary tree... \n";
	struct Tree* root = newTree(1);
	root->left = newTree(2);
	root->right = newTree(3);
	root->left->left = newTree(4);
	root->left->right = newTree(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
