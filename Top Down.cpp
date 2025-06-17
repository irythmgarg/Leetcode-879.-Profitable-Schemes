class Solution {
public:
    // 3D DP array to memoize results: dp[people left][profit so far][index]
    int dp[101][101][101];
    const int mod = 1e9 + 7;

    // Recursive helper function to count valid schemes
    int hlo(int n, int minProfit, vector<int>& group, vector<int>& profit, int profittillnow, int i) {
        // Base case: all jobs considered
        if (i >= group.size()) {
            // If profit meets the requirement, count this as 1 valid scheme
            return profittillnow >= minProfit ? 1 : 0;
        }

        // Return cached result if already computed
        if (dp[n][profittillnow][i] != -1)
            return dp[n][profittillnow][i];

        long long TAKE = 0;

        // Option 1: Take current job if enough people are available
        if (group[i] <= n) {
            // Take the job:
            // - reduce people (n - group[i])
            // - increase profit (bounded by minProfit to compress DP state)
            TAKE = (hlo(n - group[i], minProfit, group, profit, 
                        min(minProfit, profittillnow + profit[i]), i + 1)) % mod;
        }

        // Option 2: Skip the current job
        long long nottake = (hlo(n, minProfit, group, profit, profittillnow, i + 1)) % mod;

        // Store and return the total number of schemes from current state
        return dp[n][profittillnow][i] = (TAKE + nottake) % mod;
    }

    // Main function
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // Initialize memoization array with -1
        memset(dp, -1, sizeof(dp));
        
        // Start recursion from index 0 with full people and 0 profit so far
        return hlo(n, minProfit, group, profit, 0, 0);
    }
};
