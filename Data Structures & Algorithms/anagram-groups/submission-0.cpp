class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash;
        vector<vector<string>> ans;
        string y;
        for(auto x : strs) {
            y=x;
            sort(x.begin(),x.end());
            hash[x].push_back(y);
        }
        for(auto x : hash) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
