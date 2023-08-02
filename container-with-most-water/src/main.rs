use std::ops::Mul;

struct Solution {}
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left_pointer = height.first();
        let mut right_pointer = height.last();
        let mut max_value = -1;
        let mut i = 0 as i32;
        let mut j = (height.len() as i32) - 1;

        while left_pointer.is_some() && right_pointer.is_some() && j > i {
            if height.get(i as usize).unwrap().gt(left_pointer.unwrap()) {
                left_pointer = height.get(i as usize);
            }
            if height.get(j as usize).unwrap().gt(right_pointer.unwrap()) {
                right_pointer = height.get(j as usize);
            }
            if left_pointer.unwrap().le(right_pointer.unwrap()) {
                let _max_value = left_pointer.unwrap().mul(j - i);
                if _max_value.gt(&max_value) {
                    max_value = _max_value
                }
            } else if right_pointer.unwrap().le(left_pointer.unwrap()) {
                let _max_value = right_pointer.unwrap().mul(j - i);
                if _max_value.gt(&max_value) {
                    max_value = _max_value
                }
            }
            if height
                .get(i as usize)
                .unwrap()
                .lt(height.get(j as usize).unwrap())
            {
                i += 1;
            } else {
                j -= 1;
            }
        }

        return max_value;
    }
}

fn main() {
    println!("{}!", Solution::max_area(vec![1, 1]));
}
