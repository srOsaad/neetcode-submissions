public class Solution {
    public bool IsAnagram(string s, string t) {
        var count = new Dictionary<char, int>();

        for (int i = 0; i < s.Length; i++) {
            count[s[i]] = count.GetValueOrDefault(s[i]) + 1;
        }

        for (int i = 0; i < t.Length; i++) {
            if (!count.ContainsKey(t[i])) {
                return false;
            }
            
            count[t[i]]--;
            if (count[t[i]] < 0) {
                return false;
            }
        }

        foreach(var (_ , val) in count) {
            if(val != 0) {
                return false;
            }
        }

        return true;
    }
}
