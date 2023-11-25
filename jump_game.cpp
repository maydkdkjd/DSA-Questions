#include <vector>
#include <climits>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0; // Base case: no jumps needed to reach the last index

        for (int i = n - 2; i >= 0; i--) {
            int maxSteps = nums[i];
            for (int step = 1; step <= maxSteps && i + step < n; step++) {
                int nextIndex = i + step;
                if (dp[nextIndex] != INT_MAX) {
                    dp[i] = std::min(dp[i], 1 + dp[nextIndex]);
                }
            }
        }

        return dp[0];
    }
};
