/*
link - https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
*/
#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
using namespace std;

ll input;
bool can_reach(ll n)
{
    if (n > input)
        return false;

    if (n == input)
        return true;

    return can_reach(n * 10) || can_reach(n * 20);
}

int main()
{
    fast();

    int t;
    cin >> t;

    while (t--)
    {
        cin >> input;
        bool flag = can_reach(1);

        if (flag)
            yes;
        else
            no;
    }

    return 0;
}