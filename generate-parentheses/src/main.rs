use std::collections::VecDeque;

struct Solution {}

struct DfsParenthesis {
    open: i32,
    close: i32,
    str: Box<String>,
}

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut result_ref: Vec<String> = Vec::new();
        // resultRef.push("aa");
        let mut deq = VecDeque::<Box<DfsParenthesis>>::new();
        deq.push_back(Box::new(DfsParenthesis {
            open: 0,
            close: 0,
            str: Box::new(format!("{}", "")),
        }));

        while !deq.is_empty() {
            let data = deq.pop_back().unwrap();
            if data.str.len() == (2 * n) as usize {
                result_ref.push(data.str.to_string());
            }
            if data.open < n {
                let mut temp = data.str.clone();
                temp.push_str("(");
                deq.push_back(Box::new(DfsParenthesis {
                    open: data.open + 1,
                    close: data.close,
                    str: Box::from(temp),
                }))
            }
            if data.close < data.open {
                let mut temp = data.str.clone();
                temp.push_str(")");
                deq.push_back(Box::new(DfsParenthesis {
                    open: data.open,
                    close: data.close + 1,
                    str: Box::from(temp),
                }))
            }
        }

        return result_ref;
    }

    // pub fn dfs(open: i32, closed: i32, n: i32, partialValue: &String, resultRef: &Vec<String>) {
    //     if open == n && closed == n {
    //         resultRef.push()
    //     }
    // }
}

fn main() {
    let solution = Solution::generate_parenthesis(20);

    print!("{}", solution.len());
    // for sol in solution {
    //     print!("{}, ", sol);
    // }
}
