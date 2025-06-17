class Solution {
public:
    const int mod = 1e9 + 7;

    // Recursive helper function to count the number of valid schemes
    int hlo(int n, int minProfit, vector<int>& group, vector<int>& profit, int profittillnow, int i) {
        // Base case: all jobs considered
        if (i >= group.size()) {
            // If the accumulated profit meets or exceeds the required minimum
            return profittillnow >= minProfit ? 1 : 0;
        }

        long long TAKE = 0;

        // Option 1: Take the current job if enough people are available
        if (group[i] <= n) {
            // Recursively calculate the number of ways by taking the current job
            // - Reduce the number of people available (n - group[i])
            // - Add the job's profit to profittillnow (bounded by minProfit)
            TAKE = hlo(n - group[i], minProfit, group, profit,
                       min(minProfit, profittillnow + profit[i]), i + 1) % mod;
        }

        // Option 2: Skip the current job
        long long nottake = hlo(n, minProfit, group, profit, profittillnow, i + 1) % mod;

        // Total number of valid schemes from this state
        return (TAKE + nottake) % mod;
    }

    // Main function
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // Start the recursion from the 0th job, with full group capacity and zero profit
        return hlo(n, minProfit, group, profit, 0, 0);
    }
};
