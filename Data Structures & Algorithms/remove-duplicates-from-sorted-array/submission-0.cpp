class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        i=j=1;
        while(i<nums.size()) {
            while(nums[i] == nums[i-1]) i++;
            if(i<nums.size()) {
                nums[j] = nums[i];
                j++;
                i++;
            }
        }
        return j;
    }
};