class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,
        right = nums.size(),mid;
        while(left<=right) {
            mid = (left+right)>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) left=mid+1;
            else if(nums[mid]>target) right=mid-1;
            else {
                if(nums[mid] == target) return mid;
            }
        }
        return -1;
    }
};
