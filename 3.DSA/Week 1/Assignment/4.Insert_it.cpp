#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    vector<int>a(n);
    for (int i=0; i<n; i++)
        cin>>a[i];

    cin>>m;
    vector<int>b(m);
    for(int i=0; i<m; i++)
        cin >> b[i];

    int x;
    cin>>x;

    vector<int>v(n+m);

    for (int i=0; i<x; i++)
    {
        v[i]=a[i];
    }
    for (int i=0; i<m; i++)
    {
        v[x+i] = b[i];
    }
    for (int i=x; i<n; i++)
    {
        v[m+i] = a[i];
    }
    for (int i=0; i<n+m; i++)
        cout<<v[i]<<" ";

    return 0;
}
