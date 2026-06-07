class Solution {
public:
    bool isAnagram(string s, string t) {
        int check[26] = {0};
        for(auto x : s) check[x-'a']++;
        for(auto x : t) {
            check[x-'a']--;
            if(check[x-'a']==-1) return false;
        }
        for(int i=0; i<26; i++) if(check[i]!=0) return false;
        return true;
    }
};
