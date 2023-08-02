use std::collections::VecDeque;

struct Solution {}
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let vec_a: Vec<char> = a.chars().collect();
        let vec_b: Vec<char> = b.chars().collect();
        let mut result_vec = Vec::<char>::new();
        let mut remainder = 0;
        let mut i_a = a.len();
        let mut j_b = b.len();
        let binary_1 = '1';
        let binary_0 = '0';

        while i_a > 0 || j_b > 0 {
            let mut dat = 0;
            // println!("{}{}", i_a, j_b);

            if i_a > 0 {
                let single_a = vec_a.get(i_a - 1).unwrap();
                if single_a.eq(&binary_1) {
                    dat += 1;
                }
                i_a -= 1;
            }
            if j_b > 0 {
                let single_b = vec_b.get(j_b - 1).unwrap();
                if single_b.eq(&binary_1) {
                    dat += 1;
                }
                j_b -= 1;
            }
            if remainder > 0 {
                dat += 1;
            }

            if dat == 0 {
                result_vec.push(binary_0);
                remainder = 0;
            } else if dat == 1 {
                result_vec.push(binary_1);
                remainder = 0;
            } else if dat == 2 {
                result_vec.push(binary_0);
                remainder = 1;
            } else if dat == 3 {
                result_vec.push(binary_1);
                remainder = 1;
            }
        }
        if remainder > 0 {
            if result_vec.last().unwrap().eq(&binary_0) {
                result_vec.pop();
                result_vec.push(binary_1);
            } else if result_vec.last().unwrap().eq(&binary_1) {
                result_vec.pop();
                result_vec.push(binary_0);
                result_vec.push(binary_1);
            }
        }

        let result_string: String = result_vec.into_iter().rev().collect();
        // .rev().iter().collect();
        return result_string;
        // return result_string;
    }
}
// 11
// 111
// 111
// ---
// 1010

fn main() {
    let solution = Solution::add_binary("11".to_string(), "1".to_string());

    println!("{}", solution);
    // for sol in solution {
    //     print!("{}, ", sol);
    // }
}
