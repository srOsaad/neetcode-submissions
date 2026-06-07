class Solution {
    bool ok(vector<int> *X, int Y, int Z) {
        int tot = 0;
        for(auto m : (*X)) {
            tot += ceil(double(m)/Y);
            if(tot>Z) return false;
        }
        return tot<=Z;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int R = INT_MIN, L=1, M, ans = -1;
        bool check;
        for(auto u : piles) R=max(R,u);
        
        while(L<=R) {
            M = (L+R)>>1;
            check = ok(&piles, M, h);
            if(!check) L=M+1;
            else if(check) {
                ans = M;
                R = M-1;
            }
            else{
                M = (L+R)>>1;
                check = ok(&piles, M, h);
                if(check) {
                    ans = M;
                    R = M-1;
                }
            }
        }
        return ans;
    }
};
