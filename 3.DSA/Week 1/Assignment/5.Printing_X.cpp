#include<bits/stdc++.h>

using namespace std;

main()
{
    int n; cin>>n;

    int space = n-2;
    int prev_space=0;


    for(int i=0; i<n/2; i++)
    {
        for(int j=0; j<prev_space; j++)
        {
            cout<<" ";
        }
        cout<<"\\";

        for(int j=0; j<space; j++)
        {
            cout<<" ";
        }
        cout<<"/"<<endl;

        prev_space++;
        space-=2;
    }
    for(int i=0; i<n/2; i++)
    {
        cout<<" ";
    }
    cout<<"X"<<endl;

    space+=2;
    for(int i=0; i<n/2; i++)
    {
        for(int j=1; j<prev_space; j++)
        {
            cout<<" ";
        }
        cout<<"/";

        for(int j=0; j<space; j++)
        {
            cout<<" ";
        }
        cout<<"\\"<<endl;

        prev_space--;
        space+=2;
    }
}
