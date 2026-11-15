class Solution {
    bool check(map<char, int> *a, map<char, int> *m) {
        for(auto x : (*m)) {
            if(x.second > (*a)[x.first]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) {
            return "";
        }

        int answer = -1, current_size = 0, min_start, min_end;
        map<char, int> have, need;
        int len = 0, start = 0, end = 0;
        for(auto x : t) need[x]++;

        have[s[0]]++;

        if(check(&have, &need)) return string(1, s[0]);

        while(answer != t.size()) {
            //cout<<"1 ";
            if(check(&have, &need)) {
                //cout<<answer<<" ff\n";
                if(answer == -1 || end - start < answer - 1) {
                    answer = end - start + 1;
                    min_start = start;
                    min_end = end;
                }
                have[s[start]]--;
                start++;
                //cout<<answer<<" gg\n";
            }
            else {
                end++;
                if(end == s.size()) break;
                have[s[end]]++;
            }
        }

        if(answer == -1) return "";

        string ans = "";

        while(min_start<=min_end) {
            ans+=s[min_start];
            min_start++;
        }

        return ans;
    }
};
