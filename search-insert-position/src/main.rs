struct Solution {}
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let index = 0;
        for (i, num) in nums.iter().enumerate() {
            if (num.gt(&target) || num.eq(&target)) {
                return i as i32;
            }
        }
        return nums.len() as i32;
    }
}
fn main() {
    let nums = vec![1, 3, 5, 6];
    let target = 7;
    println!("{}", Solution::search_insert(nums, target));
}
