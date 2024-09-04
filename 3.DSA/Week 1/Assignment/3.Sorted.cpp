#include<bits/stdc++.h>

using namespace std;

main()
{
    int T;
    cin>>T;
    while(T)
    {
        int n;
        cin>>n;

        vector<int>a(n);

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int f=0;
        for(int i=0; i<n-1; i++)
        {
            if(a[i]>a[i+1])
            {
                f++;
                cout<<"NO";
                break;
            }
        }
        if(f==0)
            cout<<"YES";

        T--;

        cout<<endl;
    }
    return 0;
}
