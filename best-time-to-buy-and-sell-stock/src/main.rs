use std::f32::INFINITY;

struct Solution {}
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max_profit = 0;
        let mut min_value = prices[0];

        for i in 1..prices.len() {
            if (prices[i] < min_value) {
                min_value = prices[i];
            }
            if (prices[i] - min_value) > max_profit {
                max_profit = prices[i] - min_value;
            }
        }

        max_profit
    }
}

fn main() {
    println!("{}", Solution::max_profit(vec![7, 6, 4, 3, 1]));
    println!("Hello, world!");
}
