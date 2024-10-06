/*
link - https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

class Solution
{
public:
    int sum = 0;
    int target_sum;
    int dp[201][10001];

    int subset_sum(int n, int target, vector<int> &nums)
    {
        // 1. base case
        if (n == 0)
        {
            if (target == 0)
                return 1;
            return 0;
        }
        // 2. if result is already calculated, return it
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }

        // 3. calculate result from smaller states
        int ans1 = subset_sum(n - 1, target, nums);
        if (target < nums[n - 1])
        {
            dp[n][target] = ans1;
            return ans1;
        }
        int ans2 = subset_sum(n - 1, target - nums[n - 1], nums);
        int ans = ans1 || ans2;
        dp[n][target] = ans;
        return ans;
    }

    int summation(vector<int> &nums)
    {
        for (auto it : nums)
            sum += it;

        return sum;
    }

    bool canPartition(vector<int> &nums)
    {
        int z = summation(nums);
        if (z % 2 != 0)
        {
            return false;
        }

        else
        {
            target_sum = z / 2;
            // Initialize dp with -1
            memset(dp, -1, sizeof(dp));

            int ans = subset_sum(nums.size(), target_sum, nums);
            return ans != 0;
        }
    }
};
