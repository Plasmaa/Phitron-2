#include <bits/stdc++.h>
using namespace std;

class Doubly_linked_list
{
public:
    int val;
    Doubly_linked_list *next;
    Doubly_linked_list *prev;
    Doubly_linked_list(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_tail(Doubly_linked_list *&head, Doubly_linked_list *&tail, int val)
{
    Doubly_linked_list *newNode = new Doubly_linked_list(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

bool isPalindrome(Doubly_linked_list *head)
{
    if (head==NULL)
        return true;

    Doubly_linked_list *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    while (head != tail && head->prev != tail)
    {
        if (head->val != tail->val)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main()
{
    Doubly_linked_list *head = NULL;
    Doubly_linked_list *tail = NULL;
    int val;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }

    if (isPalindrome(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
