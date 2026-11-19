class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x;
        for(int i=0; i<nums.size(); i++) {
            x=target-nums[i];
            for(int l=i+1; l<nums.size() && nums[l]<=x; l++) {
                if(nums[l]==x) {
                    return {i,l};
                }
            }
        }
        return {0,1};
    }
};
