impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<char> = Vec::new();
        for c in s.chars() {
            if c == '(' || c == '{' || c == '[' {
                stack.push(c);
                continue
            }
            if let Some(&top) = stack.last() {
                if (top == '(' && c == ')') || (top == '{' && c == '}') || (top == '[' && c == ']') {
                    stack.pop();
                }
                else {return false}
            }
            else {return false}
        }
        stack.len()==0
    }
}
