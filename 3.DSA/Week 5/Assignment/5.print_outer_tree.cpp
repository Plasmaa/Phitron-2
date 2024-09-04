#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        return NULL;
    root = new Node(val);

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            p->left = new Node(l);
            q.push(p->left);
        }
        if (r != -1)
        {
            p->right = new Node(r);
            q.push(p->right);
        }
    }
    return root;
}

void print_left(Node *node)
{
    if (node == NULL)
        return;

    if (node->left)
    {
        print_left(node->left);
    }
    else if (node->right)
    {
        print_left(node->right);
    }
    cout << node->val << " ";
}

void print_right(Node *node)
{
    if (node == NULL)
        return;

    cout << node->val << " ";

    if (node->right)
    {
        print_right(node->right);
    }
    else if (node->left)
    {
        print_right(node->left);
    }
}

int main()
{
    Node *root = input_tree();

    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << endl;
        return 0;
    }

    int f = 0;
    if (root->left)
    {
        print_left(root);
        f++;
    }

    if (root->right)
    {
        if (f > 0)
            print_right(root->right);
        else
            print_right(root);
    }

    cout << endl;

    return 0;
}
