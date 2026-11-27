impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let line : Vec<char> = s.chars().filter(|c| c.is_ascii_alphanumeric()).map(|c| c.to_ascii_lowercase()).collect();
        let mut i:i32 = 0;
        let mut l:i32 = (line.len()-1) as i32;

        if l < 1 {
            return true;
        }

        while i < l {
            if line[i as usize] != line[l as usize] {
                return false;
            }
            i += 1;
            l -= 1;
        }
        return true;
    }
}
