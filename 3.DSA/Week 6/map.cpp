#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> mp;

    // 1st way
    mp["Sakib al hasn"] = 79; // O(logN)
    mp["tamim"] = 79;

    // 2nd way
    mp.insert({"akib", 100});
    mp.insert({"akib", 150});
    mp.insert({"akib", 450});

    // 3rd way
    mp.insert(make_pair("pious", 500));

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl; // O(logN)
    }

    cout << mp.count("akib") << endl;
    cout << mp.count("gg") << endl;
    cout << mp.count("owo") << endl;

    return 0;
}