// #[derive(PartialEq, Eq, Clone, Debug)]
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}
struct Solution {}
impl Solution {
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut list1_index = &list1;
        let mut list2_index = &list2;

        // let mut
        while list1_index.is_some() && list2_index.is_some() {}
        return None;
    }
}
fn main() {
    println!("Hello, world!");

    let list1 = Some(Box::new(ListNode {
        next: Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode { val: 4, next: None })),
        })),
        val: 1,
    }));

    let list2 = Some(Box::new(ListNode {
        next: Some(Box::new(ListNode {
            val: 3,
            next: Some(Box::new(ListNode { val: 4, next: None })),
        })),
        val: 1,
    }));

    let sol = Solution::merge_two_lists(list1, list2);

    for a in sol.iter() {
        print!("{} -> ", a.val);
        // if (a.next.is_some()) {
        //     a, err = a.next.unwrap();

        // }
    }
}
