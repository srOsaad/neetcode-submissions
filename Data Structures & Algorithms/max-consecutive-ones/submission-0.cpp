class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, temp = 0;
        for(auto x : nums) {
            if(x==1) temp++;
            else {ret = (temp>ret ? temp : ret); temp=0;}
            cout<<"temp now: "<<temp<<'\n';
        }
        return (temp>ret ? temp : ret);
    }
};