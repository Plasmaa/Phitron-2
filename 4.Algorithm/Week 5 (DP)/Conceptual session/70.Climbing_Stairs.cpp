/*

    link - https://leetcode.com/problems/climbing-stairs/

*/

class Solution
{
public:
    int dp[50];
    Solution() { memset(dp, -1, sizeof(dp)); }
    int climbStairs(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        else if (dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return dp[n];
    }
};