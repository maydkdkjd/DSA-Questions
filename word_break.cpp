class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] is true if s[0...i-1] can be segmented into words in the dictionary
        vector<bool> dp(n + 1, false);
        dp[0] = true; // An empty string can always be segmented

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
