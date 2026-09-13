// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//     pub val: i32,
//     pub next: *mut ListNode,
// }
//
// impl ListNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         ListNode { next: std::ptr::null_mut(), val }
//     }
// }

impl Solution {
    pub fn has_cycle(mut head: *mut ListNode) -> bool {
        let mut node_set : HashSet<*const ListNode> = HashSet::new();
        
        while !head.is_null() {
            let ptr : *const ListNode = head as *const ListNode;
            if node_set.contains(&ptr) {
                return true;
            }
            node_set.insert(ptr);
            unsafe {
                head = (*head).next;
            }
        }
        return false;
    }
}
