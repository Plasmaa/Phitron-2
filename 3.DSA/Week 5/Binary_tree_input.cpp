#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;

    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // 1. to bring out
        Node *a = q.front();
        q.pop();

        // 2. rest of the work
        int l, r;
        cin >> l >> r;

        Node *left;
        Node *right;

        if (l == -1)
            left = NULL;
        else
            left = new Node(l);
        if (r == -1)
            right = NULL;
        else
            right = new Node(r);

        a->left = left;
        a->right = right;

        // 3. push childrens
        if (a->left)
            q.push(a->left);
        if (a->right)
            q.push(a->right);
    }
    return root;
}

void level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // 1. bring out the root
        Node *a = q.front();
        q.pop();

        // 2. rest of the work
        cout << a->val << " ";

        // 3. push the children
        if (a->left != NULL)
            q.push(a->left);
        if (a->right)
            q.push(a->right);
    }
}

int main()
{
    Node *root = input_tree();
    level_order(root);

    return 0;
}