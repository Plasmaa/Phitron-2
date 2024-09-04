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

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *a = head;
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = newNode;
}

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void delete_at_index(Node *&head, int index)
{
    if (head == NULL || index < 0)
        return;

    if (index == 0)
    {
        Node *b = head;
        head = head->next;
        delete b;
        return;
    }

    Node *a = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (a == NULL || a->next == NULL)
            return;
        a = a->next;
    }
    if (a == NULL || a->next == NULL)
        return;
    Node *b = a->next;
    a->next = a->next->next;
    delete b;
}

void print_linked_list(Node *head)
{
    Node *a = head;
    while (a != NULL)
    {
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, v);
        }
        else if (x == 2)
        {
            delete_at_index(head, v);
        }

        print_linked_list(head);
    }
    return 0;
}
