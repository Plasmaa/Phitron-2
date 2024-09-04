#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    stringstream ss(s); // counts word or when it find space it then it goes to the next word.
    string word;
    int count = 0;


    while(ss>>word)
    {
        cout<<word<<endl;
        count++;
    }

    cout<<"Total number of word in the sentence : "<<count<<endl;
    
    return 0;
}