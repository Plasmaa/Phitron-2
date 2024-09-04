#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    s= "Wow";

    string b = "nah";

    //string c = s+b;

    //cout<<c; 

    s.append(b);

    cout<<s<<endl;

    s.push_back('G');

    cout<<s;
    
    return 0;
}