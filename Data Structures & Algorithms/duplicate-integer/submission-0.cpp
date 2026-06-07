class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> num;
        for(auto x : nums) num.insert(x);
        return nums.size()!=num.size();
    }
};
