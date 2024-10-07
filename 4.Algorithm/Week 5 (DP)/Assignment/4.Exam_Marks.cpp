#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    bool checkSum(int n, int sum, int arr[])
    {
        if (n == 0)
        {
            if (sum == 0)
                return true;
            else
                return false;
        }

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n] <= sum)
        {
            bool op1 = checkSum(n - 1, sum - arr[n], arr);
            bool op2 = checkSum(n - 1, sum, arr);

            return dp[n][sum] = op1 || op2;
        }
        else
        {
            return dp[n][sum] = checkSum(n - 1, sum, arr);
        }
    }

    bool isSubsetSum(int arr[], int n, int sum)
    {
        memset(dp, -1, sizeof(dp));
        return checkSum(n, sum, arr);
    }
};

int main()
{
    fast();

    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        int arr[N + 1];

        for (int i = 1; i <= N; i++)
        {
            cin >> arr[i];
        }

        int target = 1000 - m;

        Solution ob;
        if (target < 0)
            no;
        else if (ob.isSubsetSum(arr, N, target))
            yes;
        else
            no;
    }
    return 0;
}
