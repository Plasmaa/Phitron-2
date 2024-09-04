#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int search(Node *head, int X)
{
    Node *a = head;
    int index = 0;
    while (a != NULL)
    {
        if (a->val == X)
        {
            return index;
        }
        a = a->next;
        index++;
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        Node *head = NULL;
        Node *tail = NULL;


        int val;
        while (1)
        {
            cin >> val;
            if (val == -1)
                break;
            insert_at_tail(head, tail, val);
        }

        int X;
        cin >> X;

        int s = search(head, X);
        cout << s << endl;
    }

    return 0;
}
