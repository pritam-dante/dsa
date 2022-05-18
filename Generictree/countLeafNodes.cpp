#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter num of child of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int numData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> numData;
            TreeNode<int> *child = new TreeNode<int>(numData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        cout << pendingNodes.front()->data << ":";
        for (int i = 0; i < pendingNodes.front()->children.size(); i++)
        {
            cout << pendingNodes.front()->children[i]->data;
            pendingNodes.push(pendingNodes.front()->children[i]);
            if (i < pendingNodes.front()->children.size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
        pendingNodes.pop();
    }
}

int countLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    int smallAns = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        smallAns += countLeafNodes(root->children[i]);
    }
    return smallAns;
}

int main()
{
    TreeNode<int> *root = takeInput();
    print(root);
    cout << "Leaf nodes: " << countLeafNodes(root) << endl;
}