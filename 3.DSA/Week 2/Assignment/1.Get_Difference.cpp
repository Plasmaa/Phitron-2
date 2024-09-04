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

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

int main()
{
    int val;
    Node *head = NULL;
    int maxVal;
    int minVal;
    int f=0;

    while (true)
    {
        cin >> val;
        if(f==0)
        {
            maxVal=val;
            minVal=val;
            f++;
        }

        if (val == -1)
            break;
        insert_at_head(head, val);
        if (val > maxVal)
            maxVal = val;
        if (val <= minVal)
            minVal = val;
    }

    int d = maxVal - minVal;
    cout << d << endl;

    return 0;
}
