use std::collections::HashMap;

impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut check = HashMap::new();

        for num in nums {
            if let Some(x) = check.get(&num) {
                return true;
            }
            else {
                check.insert(num,1);
            }
        }

        return false;
    }
}
