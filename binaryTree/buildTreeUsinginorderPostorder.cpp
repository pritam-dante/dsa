#include <iostream>
#include <queue>
#include "binaryTreeNode.h"
using namespace std;

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L: -1";
        }
        cout << ",";
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R: -1";
        }
        cout << "\n";
    }
}
BinaryTreeNode<int> *buildTreeHelper(int *in, int *po, int inS, int inE, int poS, int poE)
{
    if (inS > inE)
    {
        return NULL; // assuming tree length is same and no duplicate values
    }

    int rootData = po[poE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (rootData == in[i])
        {
            rootIndex = i;
            break;
        }
    }

    int lpoS = poS;
    int linS = inS;
    int linE = rootIndex - 1;
    int lpoE = linE - linS + lpoS;
    int rpoS = lpoE + 1;
    int rpoE = poE - 1;
    int rinS = rootIndex + 1;
    int rinE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, po, linS, linE, lpoS, lpoE);
    root->right = buildTreeHelper(in, po, rinS, rinE, rpoS, rpoE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *post, int size)
{
    return buildTreeHelper(in, post, 0, size - 1, 0, size - 1);
}

int main()
{
    int in[] = {4, 2, 8, 5, 9, 1, 6, 3, 7};
    int post[] = {4, 8, 9, 5, 2, 6, 7, 3, 1};
    BinaryTreeNode<int> *root = buildTree(in, post, 9);
    printLevelWise(root);
}