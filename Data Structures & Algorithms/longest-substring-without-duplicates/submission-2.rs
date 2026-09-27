impl Solution {
    pub fn length_of_longest_substring(st: String) -> i32 {
        if st.len() == 0 {
            return 0;
        }

        let s = st.as_bytes(); 
        let mut visited = [false; 128];
        let mut start = 0;
        let mut end = 0;
        let mut longest_sub = 1;

        while end != s.len() {
            if visited[Self::c2i(s[end])] {
                while s[start] != s[end] {
                    start+=1;
                }
                start+=1;
                end+=1;
                continue;
            }
            let temp = end - start + 1;
            longest_sub = if temp > longest_sub {temp} else {longest_sub};
            visited[Self::c2i(s[end])] = true;
            end+=1;
        }

        longest_sub as i32
    }

    fn c2i(b: u8) -> usize {
        b as usize
    }
}
