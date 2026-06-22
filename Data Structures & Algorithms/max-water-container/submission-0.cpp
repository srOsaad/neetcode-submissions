class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0,t;
        for(int i=0;i<heights.size()-1;i++) {
            for(int l=i+1;l<heights.size();l++){
                t = min(heights[i],heights[l])*(l-i);
                ans = t>ans ? t : ans;
            }
        }
        return ans;
    }
};
