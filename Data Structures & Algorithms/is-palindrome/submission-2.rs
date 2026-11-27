impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let line : Vec<char> = s.chars().filter(|c| c.is_ascii_alphabetic()).map(|c| c.to_ascii_lowercase()).collect();
        let mut i = 0;
        let mut l = line.len()-1;

        if l < 0 {
            return true;
        }

        while i < l {
            if line[i] != line[l] {
                return false;
            }
            i += 1;
            l -= 1;
        }
        return true;
    }
}
