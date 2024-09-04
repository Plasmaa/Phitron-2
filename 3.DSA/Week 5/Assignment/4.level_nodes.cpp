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
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void print_nodes(Node *root, int X)
{
    if (root == NULL)
    {
        cout << "Invalid" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    int curr_level = 0;

    while (!q.empty())
    {
        int size = q.size();

        if (curr_level == X)
        {
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                cout << temp->val << " ";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        curr_level++;
    }

    cout << "Invalid" << endl;
}

int main()
{
    Node *root = input_tree();

    int X;
    cin >> X;

    print_nodes(root, X);

    return 0;
}
