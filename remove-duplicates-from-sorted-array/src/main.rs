use std::collections::HashSet;

struct Solution {}
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        // let hash_set = nums.into_iter().collect::<HashSet<&mut i32>>();
        let mut hash_set = HashSet::new();

        let mut cll = nums.clone();
        for num in cll.iter_mut() {
            if !hash_set.contains(num) {
                // print!("{}", num);
                hash_set.insert(num);
            }
        }
        // HashSet::from(nums);
        let size = hash_set.len();

        let mut temp = Vec::new();

        for num in hash_set.into_iter() {
            temp.push(num);
        }

        temp.sort();
        for (i, num) in temp.into_iter().enumerate() {
            nums[i] = *num;
        }

        return size as i32;
    }
}
fn main() {
    let mut vec: Vec<i32> = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];

    let result = Solution::remove_duplicates(&mut vec);
    println!("Result: {}", result);
    println!("Hello, world!");
}
