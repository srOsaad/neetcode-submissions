class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visited[256] = {false}; 
        int start = 0, end = 0, ans = 0;
        
        while (end < s.size()) {
            if (visited[s[end]]) {
                while (s[start] != s[end]) {
                    visited[s[start]] = false;
                    start++;
                }
                start++; 
            } else {
                visited[s[end]] = true;
                ans = max(ans, end - start + 1);
            }
            end++; 
        }
        return ans;
    }
};
