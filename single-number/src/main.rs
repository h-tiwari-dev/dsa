struct Solution {}
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut lastValues = 0;
        for num in nums {
            lastValues ^= num;
        }
        return lastValues;
    }
}
fn main() {
    println!("{}", Solution::single_number(vec![4, 1, 2, 1, 2]));
    println!("Hello, world!");
}
