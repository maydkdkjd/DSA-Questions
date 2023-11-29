class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int k = s.length();
        int firstDeflectionPoint = -1, secondDeflectionPoint = -1;
        int currMax = s[k - 1] - '0';
        for(int i = k - 2; i >= 0; i--) {
            if(s[i] - '0' < currMax) {
                firstDeflectionPoint = i;
                break;
            }
            currMax = s[i] - '0';
        }
        if(firstDeflectionPoint == -1) return -1;
        int min = 10;

        for(int i = firstDeflectionPoint + 1; i < k; i++) {
            if(s[i] - '0' > s[firstDeflectionPoint] - '0' && min > s[i] - '0') {
                min = s[i] - '0';
                secondDeflectionPoint = i;
            }
        }
        if(secondDeflectionPoint == -1) return -1;
        swap(s[firstDeflectionPoint], s[secondDeflectionPoint]);
        sort(s.begin() + firstDeflectionPoint + 1, s.end());

        long long ans = stoll(s);
        return (ans > INT_MAX) ? -1 : ans;
    }
};
