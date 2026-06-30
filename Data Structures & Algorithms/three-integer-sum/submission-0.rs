impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = vec![];
        nums.sort();
        for i in (0..nums.len()-2).step_by(1) {

            if nums[i]>0 || nums[i]+nums[i+1]>0 {
                break;
            }
            for l in ((i+1)..nums.len()-1).step_by(1) {

                if nums[i]+nums[l]>0 {break;}
                let target = -(nums[i]+nums[l]);
                for j in ((l+1)..nums.len()).step_by(1) {

                    if nums[j]==target {
                        let mut triplet = vec![nums[i], nums[l], nums[j]];
                        triplet.sort();
                        result.push(triplet);
                    }
                    if nums[j]>target {break;}
                }
            }
        }
        result.dedup();
        return result;
    }
}
