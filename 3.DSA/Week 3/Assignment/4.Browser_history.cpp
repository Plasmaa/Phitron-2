#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<string> addresses;
    string input;

    while (cin >> input)
    {
        if (input == "end")
            break;

        addresses.push_back(input);
    }

    int n;
    cin >> n;
    cin.ignore();

    auto curr = addresses.begin();

    getline(cin, input);
    string command = input.substr(0, 5);
    string address = input.substr(6);

    bool f = false;
    for (auto it = addresses.begin(); it != addresses.end(); it++)
    {
        if (*it == address)
        {
            curr = it;
            f = true;
            break;
        }
    }

    if (f)
    {
        cout << *curr << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }

    for (int i = 1; i < n; ++i)
    {
        getline(cin, command);
        if (command == "next")
        {
            if (next(curr) != addresses.end())
            {
                curr++;
                cout << *curr << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (curr != addresses.begin())
            {
                curr--;
                cout << *curr << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command.substr(0, 5) == "visit")
        {
            address = command.substr(6);
            f = false;
            for (auto it = addresses.begin(); it != addresses.end(); ++it)
            {
                if (*it == address)
                {
                    curr = it;
                    f = true;
                    break;
                }
            }
            if (f)
            {
                cout << *curr << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
