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

void remove_duplicates(Node *head)
{
    Node *cur = head;
    while (cur != NULL && cur->next != NULL)
    {
        Node *a = cur;
        while (a->next != NULL)
        {
            if (a->next->val == cur->val)
            {
                Node *duplicate = a->next;
                a->next = a->next->next;
                delete duplicate;
            }
            else
            {
                a = a->next;
            }
        }
        cur = cur->next;
    }
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
    int val;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, val);
    }

    remove_duplicates(head);

    print_linked_list(head);

    Node *a;
    while (head != NULL)
    {
        a = head;
        head = head->next;
        delete a;
    }

    return 0;
}
