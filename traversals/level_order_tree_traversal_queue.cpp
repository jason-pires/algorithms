// Breadth first traversal
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Tree
struct Tree {
	int data;
	struct Tree *left, *right;
};

// Iterative method to find height of Binary Tree
void printLevelOrder(Tree* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue<Tree*> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (!q.empty()) {
		// Print front of queue
		Tree* node = q.front();
		cout << node->data << " ";
		// Removes top of queue
		q.pop();

		/* Enqueue left child */
		if (node->left != NULL)
			q.push(node->left);

		/*Enqueue right child */
		if (node->right != NULL)
			q.push(node->right);
	}
}

// Utility function to create a new tree node
Tree* newNode(int data)
{
	Tree* temp = new Tree;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Tree* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	return 0;
}
