impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.len() < 3 {
            return 0
        }

        let mut left = 0;
        let mut right = height.len() - 1;
        let mut left_max = height[left];
        let mut right_max = height[right];
        let mut result = 0;
        
        loop {
            if left >= right {
                break
            }

            if height[left] < height[right] {
                left += 1;
                if left_max <= height[left] {
                    left_max = height[left];
                }
                else {
                    result += left_max - height[left];
                }
            }
            else {
                right -= 1;
                if right_max<=height[right] {
                    right_max = height[right];
                }
                else {
                    result += right_max - height[right]
                }
            }            
        }
        return result
    }
}
