impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut lo = 0;
        let mut hi = nums.len()-1;
        let mut mid = 0;
        while lo<hi {
            if nums[lo]<=nums[hi] {
                return nums[lo] as i32;
            }
            mid = (lo+hi) >> 1;
            if nums[mid] > nums[hi] {
                lo = mid + 1
            }
            else {
                hi = mid
            }
        }
        nums[lo]
    }
}
