#include <bits/stdc++.h>
using namespace std;

void insert_at_head(list<int> &l, int val)
{
    l.push_front(val);
}

void insert_at_tail(list<int> &l, int val)
{
    l.push_back(val);
}

void delete_at_index(list<int> &l, int index)
{
    if (index < 0 || index >= l.size())
    {
        cout << "Invalid" << endl;
        return;
    }
    auto it = l.begin();
    advance(it, index);
    l.erase(it);
}

void print_list_from_left( list<int> &dll)
{
    cout << "L -> ";
    auto it = dll.begin();
    while (it != dll.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void print_list_from_right( list<int> &dll)
{
    cout << "R -> ";
    auto it = dll.end();
    while (it != dll.begin())
    {
        --it;
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l;
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(l, v);
        }
        else if (x == 1)
        {
            insert_at_tail(l, v);
        }
        else if (x == 2)
        {
            delete_at_index(l, v);
        }

        print_list_from_left(l);
        print_list_from_right(l);
    }

    return 0;
}
