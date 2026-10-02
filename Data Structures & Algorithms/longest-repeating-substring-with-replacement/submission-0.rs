impl Solution {
     pub fn character_replacement(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let k = k as usize;
        let mut count = [0usize; 26];
        let (mut left, mut max_freq, mut best) = (0, 0, 0);

        for right in 0..s.len() {
            let c = (s[right] - b'A') as usize;
            count[c] += 1;
            max_freq = max_freq.max(count[c]);

            if right - left + 1 - max_freq > k {
                count[(s[left] - b'A') as usize] -= 1;
                left += 1;
            }
            best = best.max(right - left + 1);
        }
        best as i32
    }
}
