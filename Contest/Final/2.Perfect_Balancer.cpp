#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    // Reading energy levels
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Step 1: Calculate total sum of the array
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += a[i];
    }

    // Step 2: Calculate half sum (may need to double-count the middle element)
    int half_sum = total_sum / 2;

    // Step 3: Iterate through the array to find the balancing point
    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_sum += a[i];

        // Check if the current sum has reached the half sum (we allow the middle element to be counted twice)
        if (current_sum == half_sum)
        {
            cout << (i + 1) << " " << a[i] << endl; // 1-based index
            return 0;
        }
    }

    // If no balancing point is found
    cout << "UNSTABLE" << endl;
    return 0;
}
