#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
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
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
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

void printLevelWise(TreeNode<int> *root)
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

int numberOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numberOfNodes(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int max = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = height(root->children[i]);
        if (temp > max)
            max = temp;
    }
    return max + 1;
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

int countLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
        return 1;
    int smallAns = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        smallAns += countLeafNodes(root->children[i]);
    }
    return smallAns;
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << "Tree looks like this: " << endl;
    printLevelWise(root);
    cout << "Number of nodes: " << numberOfNodes(root) << endl;
    cout << "Height of tree: " << height(root) << endl;
    cout << "Level 2: " << endl;
    printAtLevelK(root, 2);
    cout << "leafNodes: " << countLeafNodes(root) << endl;
    preOrder(root);
}