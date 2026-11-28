public class Solution {
    public bool hasDuplicate(int[] nums) {
        var found =  new HashSet<int> {};
        for(int i = 0; i < nums.Length; i++) {
            if(!found.Add(nums[i])) {
                return true;
            }
        }
        return false;
    }
}