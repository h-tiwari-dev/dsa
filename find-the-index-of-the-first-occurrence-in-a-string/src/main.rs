use std::collections::HashSet;

struct Solution {}
impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let haystack_chars = haystack.chars().collect::<Vec<char>>();
        let needle_chars = needle.chars().collect::<Vec<char>>();

        let mut dp = vec![vec![0; haystack_chars.len()]; needle_chars.len()];

        for i in 0..needle_chars.len() {
            for j in 0..haystack_chars.len() {
                let needle_elem = needle_chars[i];
                let haystack_elem = haystack_chars[j];
                if needle_elem.eq(&haystack_elem) {
                    if j > 0 && i > 0 {
                        dp[i][j] = dp[i - 1][j - 1] + 1
                    } else {
                        dp[i][j] += 1;
                    }
                }
                // print!("{} | ", dp[i][j]);
            }
            // print!("\n");
        }

        // let max_index = 0;

        for j in 0..haystack_chars.len() {
            if dp[needle_chars.len() - 1][j] == needle_chars.len() {
                // print!("{}", needle_chars.len());
                return (j - (needle_chars.len() - 1)) as i32;
            }
        }
        //  dp[needle_chars.len() - 1]
        //     .iter()
        //     .enumerate()
        //     .max_by(|(_, a), (_, b)| a.cmp(b))
        //     .map(|(index, _)| index)
        //     .unwrap();

        // if dp[needle_chars.len() - 1][max_index] == needle_chars.len() {
        //     return (max_index - needle_chars.len()) as i32 + 1;
        // } else {
        return -1;
        // }
        // let haystack_chars = haystack.chars().collect::<Vec<char>>();
        // let needle_chars = needle.chars().collect::<Vec<char>>();
        // let needle_size = needle_chars.len();
        // println!("{}", haystack_chars.len());
        // // let needle_chars = needle.chars().collect();
        // // n
        // let mut needle_index = 0;

        // for (i, s) in haystack_chars.into_iter().enumerate() {
        //     let needle_char = needle_chars.get(needle_index).unwrap();

        //     if needle_char.eq(&s) {
        //         needle_index += 1;
        //     } else {
        //         needle_index = 0;
        //     }
        //     println!("{} {} {}", needle_index, needle_size, i);
        //     if needle_index.eq(&needle_size) {
        //         return ((i + 1) - needle_size) as i32;
        //     };
        //     // if (haystack_chars.get(i).eq(needle_chars.get(needleIndex))) {}
        // }

        return -1;
        // returnIndex;
    }
}

fn main() {
    let haystack = "sadbutsad";
    let needle = "sad";

    println!(
        "{}",
        Solution::str_str(haystack.to_string(), needle.to_string()),
    );
}
