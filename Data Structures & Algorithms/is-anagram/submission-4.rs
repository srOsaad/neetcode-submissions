impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut seen = [0; 26];

        for byte in s.bytes() {
            seen[(byte - b'a') as usize] += 1;
        }

        for byte in t.bytes() {
            seen[(byte - b'a') as usize] -= 1;

            if seen[(byte - b'a') as usize] < 0 {
                return false;
            }
        }

        for i in seen {
            if i > 0 {
                return false;
            }
        }

        return true;
    }
}
