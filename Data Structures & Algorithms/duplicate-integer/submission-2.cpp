#include <bits/stdc++.h>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> cache;
        for(auto a : nums) {
            cache.insert(a);
        }
        return nums.size()!=cache.size();
    }
};