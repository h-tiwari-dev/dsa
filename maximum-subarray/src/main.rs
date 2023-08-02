struct Solution {}

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut dp = vec![0; nums.len()];

        for i in 0..nums.len() {
            if i == 0 {
                dp[i] = nums[i];
            } else {
                if nums[i] > (nums[i] + dp[i - 1]) {
                    dp[i] = nums[i];
                } else {
                    dp[i] = nums[i] + dp[i - 1];
                }
            }
        }
        let val = dp.iter().max();
        return match val {
            None => 0,
            Some(i) => *i,
        };
    }
}

fn main() {
    println!("{}", Solution::max_sub_array(vec![5, 4, -1, 7, 8]))
}
