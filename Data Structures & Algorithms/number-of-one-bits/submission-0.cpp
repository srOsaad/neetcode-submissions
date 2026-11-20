class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        //string bit_s = "";
        for(int i = 0; i < 32; i++) {
            count += (n & 1);
            //bit_s = ((n & 1) ? "1" : "0") + bit_s;
            n >>= 1;

        }
        //cout<<bit_s<<'\n';
        return count;
    }
};
