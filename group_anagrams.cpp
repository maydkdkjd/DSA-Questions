
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(move(str));
        }

        for (const auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
