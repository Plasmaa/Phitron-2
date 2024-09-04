#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class doubly_linked_list
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insert_At_Index(int index, int val)
    {
        if (index < 0 || index > size)
        {
            cout << "Invalid" << endl;
            return;
        }

        Node *newNode = new Node(val);

        if (index == 0)
        {
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        else if (index == size)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node *curr = head;
            for (int i = 0; i < index - 1; ++i)
            {
                curr = curr->next;
            }
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next)
            {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        }

        size++;
        print_L_to_R();
        print_R_to_L();
    }

    void print_L_to_R()
    {
        cout << "L -> ";
        Node *curr = head;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void print_R_to_L()
    {
        cout << "R -> ";
        Node *curr = tail;
        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    doubly_linked_list l;

    for (int i = 0; i < n; ++i)
    {
        int x, v;
        cin >> x >> v;
        l.insert_At_Index(x, v);
    }

    return 0;
}
