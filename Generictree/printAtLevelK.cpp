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

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    print(root);
    cout<<"At level 2"<<endl;
    printAtLevelK(root, 2);
}