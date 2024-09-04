#include <bits/stdc++.h>
using namespace std;

void insert_at_tail(list<int> &head, int v)
{
    head.push_back(v);
}

void remove_duplicates(list<int> &head)
{
    head.sort();
    head.unique();
}

void print_linked_list(list<int> &head)
{
    for (int val : head)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    list<int> head;
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

    return 0;
}
