#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    unordered_map<int, int> freq;
    map<int, int> freqCount;
    while (Q--)
    {
        int queryType;
        cin >> queryType;

        if (queryType == 1)
        {
            int X;
            cin >> X;

            if (freq[X] > 0)
            {
                freqCount[freq[X]]--;
                if (freqCount[freq[X]] == 0)
                    freqCount.erase(freq[X]);

                freq[X]++;
                freqCount[freq[X]]++;
            }
            else
            {
                freq[X] = 1;
                freqCount[1]++;
            }
        }
        else if (queryType == 2)
        {
            if (freqCount.empty())
            {
                cout << "empty\n";
            }
            else
            {
                auto it = freqCount.rbegin();
                int maxFreq = it->first;
                int maxElem = INT_MIN;
                for (const auto &entry : freq)
                {
                    if (entry.second == maxFreq)
                    {
                        maxElem = max(maxElem, entry.first);
                    }
                }

                cout << maxElem << "\n";

                freqCount[maxFreq]--;
                if (freqCount[maxFreq] == 0)
                    freqCount.erase(maxFreq);

                freq[maxElem]--;

                if (freq[maxElem] > 0)
                {
                    freqCount[freq[maxElem]]++;
                }
            }
        }
    }

    return 0;
}
