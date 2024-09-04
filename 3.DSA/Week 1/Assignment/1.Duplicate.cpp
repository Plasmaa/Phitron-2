#include<bits/stdc++.h>

using namespace std;

main()
{
    int n; cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int f=0;
    for(int i=0; i<n-1; i++)
    {
        if(a[i]==a[i+1])
        {
            f++;
            cout<<"YES";
            break;
        }
    }
    if(f==0)
        cout<<"NO";
}
