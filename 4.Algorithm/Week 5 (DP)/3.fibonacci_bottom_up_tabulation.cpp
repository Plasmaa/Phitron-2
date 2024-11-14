/*

    its called bottom up approach because it starts from the base of the array or the 0th index
    we use loop to hover all over the array

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    a[0] = 0;
    a[1] = 1;
    // O(N)

    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;
    return 0;
}