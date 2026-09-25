impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut lo , mut hi, mut pivot, mut mid, mut ans) = (0, nums.len()-1, 0, 0, -1);
        //finding pivot

        while pivot<hi {
            mid = (pivot + hi) >> 1;
            if nums[mid] > nums[hi] {
                pivot = mid + 1;
            }
            else {hi = mid;}
        }

        if nums[pivot] <= target && target <= nums[nums.len()-1] {
            lo = pivot;
            hi = nums.len()-1;
            while lo<=hi {
                mid = (lo+hi) >> 1;
                if nums[mid] == target {
                    ans = mid as i32;
                    break;
                }
                if nums[mid] <  target {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        else if pivot>0 {
            lo = 0;
            hi = pivot - 1;
            while lo<=hi {
                mid = (lo+hi) >> 1;
                if nums[mid] == target {
                    ans = mid as i32;
                    break;
                }
                if nums[mid] <  target {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        return ans;
    }
}
