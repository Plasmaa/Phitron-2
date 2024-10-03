/*
link - https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/

class Solution
{
public:
    int dp[1000];
    int mx;

    int min_cost(vector<int> &cost, int n)
    {
        if (n == 0 || n == 1)
        {
            return cost[n];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        int op1 = min_cost(cost, n - 1);
        int op2 = min_cost(cost, n - 2);
        int sum = min(op1, op2) + cost[n];

        return dp[n] = sum;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        mx = cost.size();

        return min(min_cost(cost, mx - 1), min_cost(cost, mx - 2));
    }
};

/*


Step by Step from Recursion : (Time Limit Exceeded)
In this approach,we identify a recurrence relation between subproblems and use recursion to find the minimum cost.It's not efficient and has an exponential time complexity.

class Solution
{
    // time limit exceeded
    // recursive approach
public
    int minCostClimbingStairs(int[] cost)
    {
        int n = cost.length;
        return Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
private
    int minCost(int[] cost, int n)
    {
        if (n < 0)
            return 0;
        if (n == 0 || n == 1)
            return cost[n];
        return cost[n] + Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
}

==========================================================================================================================================================================================================================

Top - Down DP with Memoization : We optimize the recursive approach by adding memoization to reduce the time complexity from exponential to linear.We create an array to store previously computed values.

Top - Down DP with Memoization(O(n) time, O(n) space) : int[] dp;
public
int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    dp = new int[n];
    return Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
}

private
int minCost(int[] cost, int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return cost[n];
    if (dp[n] != 0)
        return dp[n];
    dp[n] = cost[n] + Math.min(minCost(cost, n - 1), minCost(cost, n - 2));
    return dp[n];
}

==========================================================================================================================================================================================================================


Bottom - Up DP - Tabulation : This approach further optimizes the problem by converting recursion to iteration and getting rid of the recursive stack.We use an array to store intermediate results and iteratively calculate the minimum cost.

Bottom - Up DP - Tabulation(O(n) time, O(n) space) : public int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    int[] dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
            dp[i] = cost[i];
        else
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
    }
    return Math.min(dp[n - 1], dp[n - 2]);
}

==========================================================================================================================================================================================================================


Fine Tuning - Reduce Space to O(1) : In this final optimization, we reduce the space complexity from O(n) to O(1). We only keep track of the minimum cost for the current step and the previous step since we don't need the entire DP array.

Fine Tuning - Reduce Space to O(1) (O(n) time, O(1) space):
public int minCostClimbingStairs(int[] cost)
{
    int n = cost.length;
    int first = cost[0];
    int second = cost[1];
    if (n <= 2)
        return Math.min(first, second);
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + Math.min(first, second);
        first = second;
        second = curr;
    }
    return Math.min(first, second);
}

*/